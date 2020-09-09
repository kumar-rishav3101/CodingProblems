#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int arr[]={12,10,3,1,5,9};
   int N=6;
   vector<int> a,b;
   for(int i=0;i<N;i++)
    {
        if(arr[i]%2==0)
        b.push_back(arr[i]);

        else
        a.push_back(arr[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    int j=0,k=0;
     for(int i=0;i<N;i++)
     {
         if(i%2==0)
        arr[i]=a[j++];

         else
         arr[i]=b[k++];
     }

    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
}
