// Last and 2nd Last string

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100];
    char ans[4];
    printf("Enter String : ");
    scanf("%s",s);
    int last=strlen(s)-1;
    char l=s[last];
    char sl=s[last-1];
    ans[0]=s[last];
    ans[1]=' ';
    ans[2]=s[last-1];
    ans[3]='\0';
    printf("%s",ans);
}
