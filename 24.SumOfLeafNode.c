#include<stdio.h>
#include<stdlib.h>
int n;
int max_height;
struct Node
{
    int data;
    int height;
    struct Node *next;
}s;

void SumOfLeafNode(int *ptr,int *count,int *value)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {

        if(count[i]==0)
        {
            sum += value[i];
        }
    }
    printf("Sum Of Leaf Nodes : %d", sum);

}

void adjacencyList(int *ptr,int source,int height,int *count)
{
    int data;
    while(1)
    {
        printf("Enter Vertex Connected to %d :",source);
        scanf("%d",&data);
        if(data==-1)
        {
            break;
        }
        if(ptr[source]==NULL)
        {
            struct Node *n;
            n=(struct Node *)malloc(sizeof(struct Node));
            n->data=data;
            n->height=height;
            n->next=NULL;
            ptr[source]=n;
            count[source] +=1;
        }else
        {
            struct Node *temp=ptr[source];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            struct Node *n;
            n=(struct Node *)malloc(sizeof(struct Node));
            n->data=data;
            n->height=height;

            n->next=NULL;
            temp->next=n;
            count[source] +=1;
        }

        adjacencyList(ptr,data,height+1,count);
    }
    if(height>max_height)
        {
                max_height=height;
        }
    if(height==0)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d :  ",i);
            struct Node *temp=ptr[i];
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
            printf("Count : %d\n" ,count[i]);
            printf("\n");
        }
    }

}

int main()
{
    printf("Enter Total No of Vertices : ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        ptr[i]=NULL;
    }
    int *count=(int *)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }
    int *value=(int *)malloc(n*sizeof(int *));
    printf("Enter value For Each Node :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value[i]);
    }

     printf("Once Entry is Over Use -1 to exit :\n");
    adjacencyList(ptr,0,0,count);
    SumOfLeafNode(ptr,count,value);
    printf("Height Of The Tree : %d ",max_height);

}
