//Create
//append
//insert at first
//insert at desired
//delete at first
//delete at last
//delete at desired

#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
};

Node* append(Node *head,int data)
{
    Node *temp;
    temp=head;
    if(head==NULL)
    {
        Node *n;
        n=new Node(data);
        head=n;
        return head;
    }
    while(head->next!=NULL)
    {
        head=head->next;
    }
    Node *n;
    n=new Node(data);
    head->next=n;
    head=temp;
    return head;
}

Node* appendfirst(Node *head,int data)
{
    if(head==NULL)
    {
        Node *n;
        n=new Node(data);
        head=n;
        return head;
    }
    Node *temp;
    temp=head;
    Node *n;
    n=new Node(data);
    head=n;
    head->next=temp;
    return head;
}

Node* insertpos(Node *head,int data,int pos)
{
    if(head==NULL)
    {
        cout<<"NO NODE ADDING AT FIRST\n";
        Node *n;
        n=new Node(data);
        head=n;
        return head;
    }
    Node *temp,*Front;
    Front=head;
    int count=1;
    while(head->next!=NULL && count!=pos)
    {
        temp=head;
        head=head->next;
        count++;
    }
    if(count==pos)
    {
        Node *n;
        n=new Node(data);
        temp->next=n;
        n->next=head;
        head=Front;
        return head;
    }else
    {
        cout<<"Position Not Fount : Adding at last\n";
         Node *n;
        n=new Node(data);
        head->next=n;
        head=Front;
        return head;
    }

}
Node* deleteLast(Node *head)
{
    if(head==NULL)
    {
        cout<<"NO DATA\n";
    }
    Node *temp,*First;
    First=head;
    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
    }
    temp->next=NULL;
    delete head;
    head=First;
    return head;
}

Node* deletefirst(Node *head)
{
    if(head==NULL)
    {
        cout<<"NO DATA\n";
    }
    Node *temp;
    temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* deletepos(Node *head,int pos)
{
    if(head==NULL)
    {
        cout<<"NO DATA\n";
        return head;
    }
    Node *temp,*Front;
    Front=head;
    int count=1;
    while(head->next!=NULL && count!=pos)
    {
        temp=head;
        head=head->next;
        count++;
    }
    if(count==pos)
    {
        temp->next=head->next;
        delete head;
        head=Front;
        return head;
    }else
    {
        cout<<"Position Not Fount\n";
        head=Front;
        return head;
    }

}
void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->next;
    }
}

int main()
{
    Node *Head=NULL;
    Head=append(Head,26);
    Head=append(Head,260);
    Head=append(Head,26121);
    Head=appendfirst(Head,121212);
    Head=insertpos(Head,701984,3);
    display(Head);
    Head=deletepos(Head,3);
    cout<<"\n";
    display(Head);
    Head=deleteLast(Head);
    cout<<"\n";
    display(Head);
    Head=deletefirst(Head);
    cout<<"\n";
    display(Head);
    return 0;
}
