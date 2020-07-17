//ADD
//Delete
//ADD First
//ADD middle
//USE DYNAMIC ALLOCATIONS

#include<iostream>
using namespace std;

int main()
{
    int countt=0,choice=0;
    int *arrayy;
    while(1)
    {
        cout<<"Select Operations:\n";
        cout<<"1.ADD\n2.ADD at First\n3.Add at Middle\n4.Delete\n5.Display\n6.Exit";
        cin>>choice;
        switch(choice)
        {
        case 1:
            if(countt==0)
            {
                arrayy = new int[1];
                cout<<"\nEnter Value : ";
                cin>>arrayy[countt];
                countt++;
            }else
            {
                int *temp;
                temp = new int[countt+1];
                for(int i=0;i<countt;i++)
                {
                    temp[i]=arrayy[i];
                }
                cout<<"\nEnter Value : ";
                cin>>temp[countt];
                arrayy=temp;
                countt++;
            }
            break;
        case 2:
            if(countt==0)
            {
                arrayy = new int[1];
                cout<<"\nEnter Value : ";
                cin>>arrayy[countt];
                countt++;
            }else
            {
                int *temp;
                temp = new int[countt+1];
                cout<<"\nEnter Value : ";
                cin>>temp[0];
                for(int i=0;i<countt;i++)
                {
                    temp[i+1]=arrayy[i];
                }
                arrayy=temp;
                countt++;
            }
            break;
        case 3:
            if(countt==0)
            {
                arrayy = new int[1];
                cout<<"\nEnter Value : ";
                cin>>arrayy[countt];
                countt++;
            }else
            {
                int *temp;
                temp = new int[countt+1];
                int j=0;
                for(int i=0;i<countt;i++)
                {
                    if(i==(countt/2))
                    {
                        cout<<"\nEnter Value : ";
                        cin>>temp[i];
                        j++;
                    }
                    temp[i+j]=arrayy[i];
                }
                arrayy=temp;
                countt++;
            }
            break;
        case 4:
            if(countt==0)
            {
                cout<<"No Value :\n";
            }else
            {
                int *temp;
                temp = new int[countt-1];
                for(int i=0;i<countt-1;i++)
                {
                    temp[i]=arrayy[i];
                }
                arrayy=temp;
                countt--;
            }
            break;
        case 5:
            for(int i=0;i<countt;i++)
            {
                cout<<arrayy[i]<<"\t";
            }
            cout<<"\n";
            break;
        case 6:
            break;
        }

    }
}
