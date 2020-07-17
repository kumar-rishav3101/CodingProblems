#include<iostream>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST
{
public:
    Tree *add(int data,Tree *start)
    {
        Tree *temp=start;
        if(temp==NULL)
        {
            Tree *n;
            n= new Tree(data);
            return n;
        }
        if(temp->data > data )
        {
            temp->left = add(data,temp->left);
        }else
        {
            temp->right = add(data,temp->right);
        }
        return temp;
    }

    void findd(int key,Tree *start,int l)
    {
        Tree *temp=start;
        if(temp==NULL)
        {
            cout<<"Not Found ";
            return;
        }
        if(temp->data == key )
        {
            cout<<"Found at Level"<<l;
            return;
        }
        else if(temp->data > key )
        {
            findd(key,temp->left,l+1);
        }else
        {
            findd(key,temp->right,l+1);
        }
    }


    void inorder(Tree *t)
    {
        if(t==NULL)
        {
            return;
        }
        inorder(t->left);
        cout<<t->data<<"\t";
        inorder(t->right);

    }
};

int main()
{
    BST b;
    Tree *start=NULL;
    start=b.add(10,start);
    b.add(20,start);
    b.add(19,start);
    b.add(18,start);
    b.add(14,start);
    b.add(22,start);
    b.add(8,start);
    b.inorder(start);
    cout<<"\n";
    b.findd(14,start,0);
}
