/*
Trapped in 2D Dungeon and need to find the quickest way out.
Only movement allowed is the adjacent cells
takes 1 min to move b/w cells
Find minimum time to reach the exit */

/*
Some cells may contains rocks denoted by #
S-Denotes start point
E-Denotes exit
.-Empty space

S . . # . . .
. # . . . # .
. # . . . . .
. . # # . . .
# . # E . # .

*/

#include<stdlib.h>
#include<stdio.h>

#define SIZE 40
int n;
int rows,column;
int **height;
struct queue
{
    int row[SIZE];
    int column[SIZE];
    int l;
    int r;
} q;
void enqueue(int rows,int column)
{

    if(q.l==-1)
    {
        q.l++;
        q.r++;
    }
    printf("\nInside Enqueue");
    q.row[q.r]=rows;
    q.column[q.r]=column;
    printf("\nRow Push : %d",q.row[q.r]);
    printf("\nColumn Push : %d",q.column[q.r]);
    q.r++;
}

int dequeuerow()
{
    if(q.l>q.r)
    {
        q.l=-1;
        q.r=-1;
        return -1;
    }
    int data=q.row[q.l];
    return data;
}

int dequeuecolumn()
{
    if(q.l>q.r)
    {
        q.l=-1;
        q.r=-1;
        return -1;
    }
    int data=q.column[q.l];
    q.l++;
    return data;
}


void bfs(char **arr,int startr,int startc,int **visited)
{
    if (visited[startr][startc])
        return;
    visited[startr][startc]=1;
    for(int i=-1; i<=1; i+=2)
    {
        if(startr+i>=0 && startr+i<rows)
        {
            if(arr[startr+i][startc]=='E')
            {
                printf("\nEscaped in %d",height[startr][startc]+1);
                q.l=-1;
                q.r=-1;
                exit(0);
            }

            if(arr[startr+i][startc]=='.')
            {
                if(visited[startr+i][startc]!=1)
                {
                    enqueue(startr+i,startc);
                    height[startr+i][startc]=height[startr][startc]+1;
                    visited[startr+i][startc]=1;
                }

            }

        }
        if(startc+i>=0 && startc+i<column)
        {
            if(arr[startr][startc+i]=='E')
            {
                printf("\nEscaped in %d",height[startr][startc]+1);
                exit(0);
            }
            if(arr[startr][startc+i]=='.')
            {
                if(visited[startr][startc+i]!=1)
                {
                     enqueue(startr,startc+i);
                     height[startr][startc+i]=height[startr][startc]+1;
                     visited[startr][startc+i]=1;
                }

            }
        }
    }
    while(1)
    {
        int data=dequeuerow();
        int data2=dequeuecolumn();
        printf("\n\n\n\t\t\t%d\t\t%d\n\n",data,data2);
        if(data==-1)
            break;
        visited[data][data2]=0;
        bfs(arr,data,data2,visited);
    }

    printf("No Chance");
    exit(0);
    return;

}

int main()
{
    q.l=-1;
    q.r=-1;
    char flush;
    printf("Enter Rows and Column values :");
    scanf("%d%d",&rows,&column);
    char **arr=(char **)malloc(rows*sizeof(char *));
    int **visited=(int **)malloc(rows*sizeof(int *));
    height=(int **)malloc(rows*sizeof(int *));
    for(int r=0; r<rows; r++)
    {
        arr[r]=(char *)malloc(column*sizeof(char));
    }

    for(int r=0; r<rows; r++)
    {
        visited[r]=(int *)malloc(column*sizeof(int));
    }
    for(int r=0; r<rows; r++)
    {
        height[r]=(int *)malloc(column*sizeof(int));
    }

    int startr,startc;
    printf("Enter Details Of Dungeon :-\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<column; j++)
        {
            scanf("%c",&flush);
            arr[i][j]=getchar();
            if(arr[i][j]=='S')
            {
                startr=i;
                startc=j;
            }
        }

    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<column; j++)
        {
            visited[i][j]=0;
        }

    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<column; j++)
        {
            height[i][j]=0;
        }

    }

    bfs(arr,startr,startc,visited);
}
