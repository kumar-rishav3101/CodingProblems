#include<stdio.h>
int main()
{
    int x=0;
    int *p=&x;
    *p=*p+1;
    printf("%d ",x);
}
