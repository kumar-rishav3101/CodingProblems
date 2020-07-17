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
            cout<<"First Repeated Value "<<value;
            return 0;
        }
        arr[h]=new HashNode(key,value);
        return 1;
    }
};

int main()
{
    hashTable h;
    if(h.insertt(2,2))
        if(h.insertt(5,5))
            if(h.insertt(1,1))
                if(h.insertt(2,2))
                    if(h.insertt(3,3))
                        if(h.insertt(5,5))
                            if(h.insertt(1,1))
                                if(h.insertt(2,2))
                                        if(h.insertt(4,4))
                                        {
                                            cout<<"No match"
                                        }
}
//IN PLACE OF SO MANY INSERTS GIVE ARRAY VALUE
