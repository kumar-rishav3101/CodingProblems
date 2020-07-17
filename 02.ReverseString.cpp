//Dynamic Allocation
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string message,temp;
    cout<<"Enter Message :";
    cin>>message;
    temp=message;
    for(int i=0;i<temp.length();i++)
    {
        message[message.length()-i-1]=temp[i];
    }
    cout<<message;
}

