#include<iostream>
using namespace std;
int main()
{
    int n,n2;
    cout<<"Enter size of 2 Arrays ";
    cin>>n>>n2;
    int *arr,*arr2,*arr3;
    arr = new int [n];
    arr2 = new int [n2];
    arr3 = new int [n+n2];
    cout<<"Enter Array 1 (Sorted):\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Array 1 (Sorted):\n";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    int i=0,j=0,x=0;
    for(;i<n&&j<n2;)
    {
        if(arr[i]<arr2[j])
        {
            arr3[x]=arr[i];
            x++;
            i++;
        }else
        {
            arr3[x]=arr2[j];
            x++;
            j++;

        }
    }
    if(i==n)
    {
        while(j<n2)
        {
            arr3[x]=arr2[j];
            x++;
            j++;

        }
    }else
    {
        while(i<n)
        {
            arr3[x]=arr[i];
            x++;
            i++;

        }

    }
    for(int i=0;i<x;i++)
    {
        cout<<arr3[i]<<"\t";
    }
}
