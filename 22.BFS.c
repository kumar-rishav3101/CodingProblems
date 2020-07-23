#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int n;

struct queue
{
    int data[SIZE];
    int l;
    int r;
}q;
void enqueue(int data)
{
    if(q.l==-1)
    {
        q.l++;
        q.r++;
    }
    q.data[q.r]=data;
    q.r++;
}

int dequeue()
{
    if(q.l>=q.r)
    {
        return 0;
    }
    int data=q.data[q.l];
    q.l++;
    return data;
}

void bfs(int **arr,int source,int *visited)
{
    if (visited[source])
            return;
    visited[source]=1;
    printf("%d\t",source+1);
    for(int i=0;i<n;i++)
    {
        if(arr[source][i]==1)
            if(visited[i]!=1)
                enqueue(i);

    }
    while(1)
    {
        int data=dequeue();
        if(data==0)
            break;
        bfs(arr,data,visited);
    }
}

int main()
{
    q.l=-1;
    q.r=-1;
    printf("Enter Total No of Vertices :");
    scanf("%d",&n);
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int **arr=(int **)malloc(n*sizeof(int *));
    for(int r=0;r<n;r++)
        arr[r]=(int *)malloc(n*sizeof(int));

    printf("Enter Adjancency Matrix :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);

    int source =0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            bfs(arr,source,visited);
    }

    return 0;

}

