//Minimum Start Value

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10];
    printf("Enter Elements :");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }

    int ans=1;
    int sum=1;
    for(int i=0;i<10;i++)
    {
        sum += a[i];
        if(sum<=0)
        {
            ans += sum*-1 +1;
            sum=1;
        }
    }
    printf("answer %d",ans);
}
