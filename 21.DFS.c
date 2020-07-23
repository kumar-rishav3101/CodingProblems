#include<stdio.h>
#include<stdlib.h>
int visited[]={0,0,0,0,0,0,0,0,0,0,0,0};
int n;
void dfs(int **arr,int source)
{
    if (visited[source])
            return;
    visited[source]=1;
    printf("%d\t",source+1);
    for(int i=0;i<n;i++)
    {
        if(arr[source][i]==1)
            dfs(arr,i);

    }

}

int main()
{
    printf("Enter Total No of Vertices :");
    scanf("%d",&n);
    int **arr=(int **)malloc(n*sizeof(int *));
    for(int r=0;r<n;r++)
        arr[r]=(int *)malloc(n*sizeof(int));
    printf("Enter Adjancency Matrix :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    int source =0;
    dfs(arr,source);
    return 0;
}
