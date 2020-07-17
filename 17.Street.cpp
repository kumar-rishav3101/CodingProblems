#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    int *arr;
    arr= new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int i, key, j;
    for (i = 2; i < n-1; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    int ans=1;
    for(i=n-1;i>=0;i-=2)
    {
        ans*=arr[i];
    }
    if(i==-1)
    {
        ans*=arr[0];
    }

    cout<<ans;
}
