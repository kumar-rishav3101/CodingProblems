#include<iostream>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    int *arr;
    arr= new int[n];
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    for(int i=n-l-1;i<=(n-2);i++)
    {
        int sum=0;
        for(int j=1;j<=l;j++)
        {
            sum+=arr[i-j];
        }
        if(sum<arr[i])
        {
            arr[i]=sum;
        }
    }
    int sum=0;
    int i=n-1;
        for(int j=1;j<=l;j++)
        {
            sum+=arr[i-j];
        }
        arr[i]=sum;
      /*  for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }*/
        cout<<arr[i];

}
