/*

0 4 1 100 100
100 0 100 1 100
100 2 0 5 100
100 100 100 0 3
100 100 100 100 0
*/


#include<stdio.h>
#include<stdlib.h>
int n;
struct Node
{
    int index;
    int value;
    struct Node *next;
};


void Dijkstra(struct Node *Head,int **arr,int *dist)
{
    if(Head==NULL)
        return;
    if(dist[Head->index] > Head->value)
    {

       dist[Head->index] = Head->value;
    }

    for(int i=0;i<n;i++)
    {
        if(i!=Head->index)
        {
            if(arr[Head->index][i]!=100)
            {
                    struct Node *temp=Head;
                    struct Node *temp2=NULL;
                    while( temp!=NULL && temp->value < (arr[Head->index][i]+Head->value) )
                    {
                        temp2=temp;
                        temp=temp->next;
                    }
                    if(Head->value > (arr[Head->index][i]+Head->value) )
                    {
                        struct Node *n;
                        n=(struct Node *)malloc(sizeof(struct Node *));
                        n->index=i;
                        n->value=arr[Head->index][i]+Head->value;
                        n->next=Head;
                        Head=n;
                    }else
                    {
                        struct Node *n;
                        n=(struct Node *)malloc(sizeof(struct Node *));
                        n->index=i;
                        n->value=arr[Head->index][i]+Head->value;
                        n->next=temp;
                        temp2->next=n;
                    }
                }
            }
        }
    return Dijkstra(Head->next, arr, dist);
}



int main()
{

    printf("Enter No. of Vertices : ");
    scanf("%d",&n);
    int **arr;
    arr =(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
    }
    printf("Enter Adjacency Matrix (Weighted):-\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);

    int *dist;
    dist=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        dist[i]=100;
    }

    struct Node *Head=NULL;

    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node *));
    n->index=0;
    n->value=0;
    n->next=NULL;
    Head=n;
    Dijkstra(Head,arr,dist);
    for(int i=0;i<n;i++)
    {
        printf("%d",dist[i]);
    }
    return 0;
}
