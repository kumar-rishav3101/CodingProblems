#include<iostream>
using namespace std;

void reversee(string &str,int n)
{
    static char *rev =new char[n];
    static int count=0;
    if(n<0)
    {
        cout<<"HERE"<<"\n";
        for(int i =0;i<count;i++)
        cout<<*(rev+i);
        return;
    }
    rev[count] = str[n];
    count++;
    return reversee(str,n-1);
}

int main()
{
    string name ="Rishav";
    reversee(name,name.size()-1);
}
