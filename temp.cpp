#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST
{
    public:

    Node *add(Node *root,int data)
    {
        Node *temp=root;
        if(temp==NULL)
        {
            Node *n;
            n= new Node(data);
            return n;
        }
        if(temp->data > data )
        {
            temp->left = add(temp->left,data);
        }else if(temp->data < data )
        {
            temp->right = add(temp->right,data);
        }
        return temp;
    }



    void display(Node *start)
    {
        if(start == NULL)
            return;
        display(start->left);
        cout<<start->data<<" ";
        display(start->right);
    }


};

int main() {
	Node *start=NULL;
	BST b;
	int n;
	cin>>n;
	while(n--)
	{
	    char x;
	    int data;
	    cin>>x;
	    cin>>data;
	    if(x=='i')
	    {
	        if(start==NULL)
	        {
	            start=b.add(start,data);
	        }
	        b.add(start,data);
	    }else
	    {
	        b.del(start,NULL,data);
	    }
	}
    b.display(start);

	return 0;
}
