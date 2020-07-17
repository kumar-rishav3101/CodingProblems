#include<iostream>
using namespace std;
int main()
{
    int n,i=1;
    cout<<"Enter ";
    cin>>n;
    long int s=0;
    while(n)
    {
        s=s+i*(n%2);
        i*=10;
        n=n/2;
    }
    cout<<s;
}
