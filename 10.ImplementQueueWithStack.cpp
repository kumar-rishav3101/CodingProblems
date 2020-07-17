#include<iostream>
using namespace std;

class queue
{
public:
    int stack1[10];
    int stack2[10];
    int top1,top2;
    queue()
    {
        top1=-1;
        top2=-1;
    }

    void insert(int data)
    {
        top1++;
        stack1[top1]=data;
    }

    void remove()
    {
        if(top2==-1)
        {
            while(top1!=-1)
            {
                top2++;
                stack2[top2]=stack1[top1];
                top1--;
            }
        }
        cout<<"Element Removed "<<stack2[top2]<<"\n";
        top2--;
    }
};

int main()
{
    queue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.remove();
    q.insert(40);
    q.remove();
    q.remove();
    q.remove();
}
