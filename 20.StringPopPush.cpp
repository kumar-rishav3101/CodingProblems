#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int K;
    cout<<"Enter Value of K :";
    cin>>K;
    string s;
    string t;
    cout<<"Enter Value of s & t :";
    cin>>s;
    cin>>t;
    int i=0;
    int length = s.size()+t.size();
    int mainlength=length;
    if(K>=length)
    {
        cout<<"1";
        cout<<"YES";
    }else
    {
        for(i=0;(i<t.size()&&i<s.size());)
        {
        if(s[i]==t[i])
        {
            length -=2;
            i++;
        }else
        {
            if(length > K)
            {
                cout<<"No";
            }else if(length == K || ((length+2*i)<=K))
            {
                cout<<"2";
                cout<<"YES";
            }else
            {
                for(int x=0;x<i;x+=2)
                {
                    if((i+x)==K)
                    {
                        cout<<"3";
                        cout<<"YES";
                        return 0;
                    }
                }
                cout<<"NO";
                return 0;
            }
        }
        }


            for(int xx=0;(xx+length)<mainlength;xx+=2)
            {
                if(xx+length==K)
                {
                    cout<<"4";
                    cout<<"YES";
                    return 0;
                }
            }
            cout<<"NO";



}
}
