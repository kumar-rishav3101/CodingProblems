// Duplicate Elements
int hash[1000];
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10];
    int ans=0;

    printf("Enter elements:");
    for(int i=0;i<8;i++)
    {
        scanf("%d",&a[i]);
    }


    for(int i=0;i<8;i++)
    {
        if(hash[a[i]]==0)
        {
            hash[a[i]]=1;
        }else if(hash[a[i]]==1)
        {
            ans+=1;
            hash[a[i]]=2;
        }else if(hash[a[i]]==2)
        {
            continue;
        }
    }

    printf("ANSWER %d",ans);

}
