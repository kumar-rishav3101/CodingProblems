//add
//delete
//Display 1-n
//Display n-2
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
            this->previous=NULL;
        }
};

Node* add(Node *Head,int data)
{
    if(Head==NULL)
    {
        Node *n;
        n=new Node(data);
        Head=n;
        return Head;
    }
    Node *temp;
    temp=Head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node *n;
    n=new Node(data);
    temp->next=n;
    n->previous=temp;
    return Head;
}
Node* addpos(Node *Head,int pos,int data)
{
    if(Head==NULL)
    {
        Node *n;
        n=new Node(data);
        Head=n;
        return Head;
    }
    int count=1;
    Node *temp;
    temp=Head;
    while(temp->next!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    if(count==pos)
    {
        Node *n;
        n=new Node(data);
        n->previous=temp->previous;
        temp->previous->next=n;
        n->next=temp;
        temp->previous=n;
        return Head;
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
    Head=add(Head,26);
    Head=add(Head,260);
    Head=add(Head,26121);
    Head=addpos(Head,3,701984);
    display(Head);
    return 0;

}
