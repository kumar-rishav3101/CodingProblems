#include<iostream>
#define SIZE 10
using namespace std;
class HashNode
{
public:
    int key;
    int value;
    HashNode *next;
    HashNode(int key,int value)
    {
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
};
class hashTable
{
public:
    HashNode **arr;
    hashTable()
    {
        arr=new HashNode*[SIZE];
        for(int i=0;i<SIZE;i++)
        {
            arr[i]=NULL;
        }
    }

    int hashFunction(int key)
    {
        return(key%SIZE);
    }

    void insertt(int key,int value)
    {
        int h = hashFunction(key);
        if(arr[h] != NULL)
        {
            HashNode *temp;
            temp=arr[h];
            while(arr[h]->key !=  key && arr[h]->next!=NULL)
            {
             arr[h]=arr[h]->next;
            }
             if(temp->key ==  key)
            {
                delete arr[h];
                arr[h]=new HashNode(key,value);
            }else
            {
            HashNode *n;
            n=new HashNode(key,value);
            arr[h]->next=n;
            arr[h]=temp;
            }
            return;
        }
        arr[h]=new HashNode(key,value);
        return;
    }

    int get(int key)
    {
        int h = hashFunction(key);
        HashNode *temp;
        temp=arr[h];
        while(temp!=NULL && temp->key != key)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            return -1;
        }
        return temp->value;
    }

    void deletee(int key)
    {
        int h = hashFunction(key);

        HashNode *temp,*temp2;
        temp=arr[h];
        while(temp!=NULL && temp->key != key)
        {
            temp2=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"NO DATA\n";
        }
        temp2->next=temp->next;
        delete temp;
    }

    void display()
    {
        cout<<"KEY\tVALUE\n";
        for(int i=0;i<SIZE;i++)
        {
            if(arr[i] != NULL)
            {
                if(arr[i]->next!=NULL)
                {
                    HashNode *temp;
                    temp=arr[i];
                    while(temp!=NULL)
                    {
                        cout<<temp->key<<"\t"<<temp->value<<"\t\t";
                        temp=temp->next;
                    }
                    cout<<"\n";
                }else
                {cout<<arr[i]->key<<"\t"<<arr[i]->value<<"\n";}
            }
        }
    }
};

int main()
{
    hashTable h;
    h.insertt(2,2);
    h.insertt(32,5);
    h.insertt(12,12);
    h.insertt(42,42);
    h.insertt(43,43);
    h.insertt(33,33);
    h.insertt(23,23);
    h.insertt(4,4);
    h.insertt(14,14);
    h.display();
    h.deletee(33);
    cout<<"\n";
    h.display();
    //cout<<h.get(2)<<"\t"<<h.get(12)<<"\t"<<h.get(42)<<"\t"<<h.get(32);
    return 0;
    //ALL OPERATIONS IS WORKING
}
