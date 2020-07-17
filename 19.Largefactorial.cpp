#include<iostream>
using namespace std;
class Node
{
public :
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

int main()
{
    int n;
    cout<<"Enter Value :";
    cin>>n;
    Node **p;
    p = new Node*[n+1];
    for(int i=0; i<n+1; i++)
    {
        p[i]=NULL;
    }
    Node *node1;
    node1 = new Node(1);
    p[1]=node1;

    int i=2;
    bool x=0;

    while(i<=n)
    {
        int store=i;
        Node *one=NULL;
        while(store)
        {
            if(one==NULL)
            {
                Node *node2;
                node2 = new Node(store%10);
                one=node2;
            }else
            {
                Node *onetemp=one;
                while(onetemp->next!=NULL)
                {
                    one=onetemp->next;
                }
                Node *node2;
                node2 = new Node(store%10);
                onetemp->next=node2;
                node2->prev=onetemp;
            }
            store /=10;

        }

        Node *tempone=NULL;
        Node *temptwo=NULL;
        int check=0;


        while(one!=NULL)
        {
            if(check==0)
            {

                Node *two=p[i-1];
                int data=0;
                while(two!=NULL)
                {
                    data= data +((one->data)*(two->data));
                    two=two->next;

                    Node *newnode;
                    newnode = new Node(data%10);
                    if(tempone==NULL)
                    {
                        tempone=newnode;

                    }
                    else
                    {
                        Node *temp=tempone;
                        while(temp->next!=NULL)
                        {
                            temp=temp->next;
                        }
                        temp->next=newnode;
                        newnode->prev=temp;
                    }

                    data /=10;
                }
                while(data)
                {
                    Node *newnode;
                    newnode = new Node(data%10);
                    Node *temp=tempone;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                    newnode->prev=temp;
                    data /=10;
                }


                one=one->next;
                check = 1;
            }
            else
            {

                Node *two=p[i-1];
                int data=0;
                while(two!=NULL)
                {
                    data= data +((one->data)*(two->data));
                    two=two->next;

                    Node *newnode;
                    newnode = new Node(data%10);
                    if(temptwo==NULL)
                    {
                        temptwo=newnode;

                    }
                    else
                    {
                        Node *temp=temptwo;
                        while(temp->next!=NULL)
                        {
                            temp=temp->next;
                        }
                        temp->next=newnode;
                        newnode->prev=temp;
                    }

                    data /=10;
                }
                while(data)
                {
                    Node *newnode;
                    newnode = new Node(data%10);
                    Node *temp=temptwo;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                    newnode->prev=temp;
                    data /=10;
                }
                one=one->next;
            }

        }

        if(temptwo==NULL)
        {
            p[i]=tempone;
        }else
        {
            Node *finalans=NULL;
            Node *n;
            n=new Node(tempone->data);
            finalans=n;
            Node *temp=finalans;
            tempone=tempone->next;
            int data=0;
            while(tempone!=NULL)
            {
                data=data+(tempone->data+temptwo->data);
                Node *n;
                n = new Node(data%10);
                temp->next=n;
                n->prev=temp;
                temp=temp->next;
                data /=10;
                tempone=tempone->next;
                temptwo=temptwo->next;
            }
            int data2=0;
            data2=data;

            while(temptwo!=NULL)
            {
                data2=data2+temptwo->data;
                Node *n;
                n = new Node(data2%10);
                temp->next=n;
                n->prev=temp;
                temp=temp->next;
                data2 /=10;
                temptwo=temptwo->next;
            }

            while(data2)
                {

                    Node *newnode;
                    newnode = new Node(data2%10);
                    temp->next=newnode;
                    newnode->prev=temp;
                    temp=temp->next;
                    data2 /=10;
                }

            p[i]=finalans;

        }

        i++;
    }

    Node *display=p[i-1];

    while(1)
    {
        if(display->next==NULL)
            break;
        display=display->next;

    }

    while(1)
    {
        cout<<display->data;
        if(display->prev==NULL)
            break;
        display=display->prev;
    }

}
