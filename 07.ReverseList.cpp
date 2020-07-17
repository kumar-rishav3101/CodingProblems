
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

Node* reverseList(Node *Head)
{
    Node *temp,*temp2;
    temp2=Head->next;
    Head->next=NULL;
    while(temp2!=NULL)
    {
        temp=Head;
        Head=temp2;
        temp2=temp2->next;
        Head->next=temp;
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
    display(Head);
    Head=reverseList(Head);
    cout<<"\n";
    display(Head);
    return 0;
}



