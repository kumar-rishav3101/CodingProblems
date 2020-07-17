#include<iostream>
#define SIZE 10
using namespace std;
class HashNode
{
public:
    int key;
    int value;
    HashNode(int key,int value)
    {
        this->key=key;
        this->value=value;
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
    int insertt(int key,int value)
    {
        int h = hashFunction(key);
        while(arr[h] != NULL && arr[h]->key !=  key)
        {
            h=hashFunction(h+1);
        }
        if(arr[h] != NULL)
        {
            delete arr[h];
        }
        arr[h]=new HashNode(key,value);
        return 1;
    }
    int get(int key)
    {
        int h = hashFunction(key);
        while(arr[h] !=NULL && arr[h]->key != key)
        {
            h=hashFunction(h+1);
        }
        if(arr[h]==NULL)
        {
            return -1;
        }
        return arr[h]->value;
    }
    void deletee(int key)
    {
        int h = hashFunction(key);
        while(arr[h] !=NULL && arr[h]->key != key)
        {
            cout<<"HERE";
            h=hashFunction(h+1);
        }
        if(arr[h]==NULL)
        {
            cout<<"NO DATA\n";
        }
        arr[h]=NULL;
    }

    void display()
    {
        cout<<"KEY\tVALUE\n";
        for(int i=0;i<SIZE;i++)
        {
            if(arr[i] != NULL)
            cout<<arr[i]->key<<"\t"<<arr[i]->value<<"\n";
        }

    }
};

int main()
{
    hashTable h;
    h.insertt(2,2)
    h.insertt(5,5)
    return 0;
    //ALL OPERATIONS IS WORKING
}
