
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

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head=head->next;
    }
}

void palindrome(Node *head,int n)
{
    int a[n/2+1];
    a[0]=0;
    int i=1;
    while(head!=NULL&& i!=(n/2+1))
    {
        a[i]=head->data;
        head=head->next;
        i++;
    }
    i--;
    if(n%2==0)
    {
        while(head!=NULL && a[i] == head->data)
        {
            head=head->next;
            i--;
        }
    }
    else
    {
        head=head->next;
        while(head!=NULL && a[i] == head->data)
        {
            head=head->next;
            i--;
        }

    }
    if(head==NULL)
    {
        cout<<"Palindrome";
    }else
    {
        cout<<"Not Palindrome";
    }
}

int main()
{
    Node *Head=NULL;
    int n=0;
    Head=append(Head,1);
    n++;
    Head=append(Head,2);
    n++;
    Head=append(Head,1);
    n++;
    display(Head);
    palindrome(Head,n);
    return 0;
}
