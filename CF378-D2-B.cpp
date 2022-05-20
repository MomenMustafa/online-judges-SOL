#include <stdio.h>
#include<vector>
#include<iostream>

using namespace std;
const int size=1e5+1;
int sf1[size], sf2[size];

void ReadInput(int &n)
{
    for(int i=0;i<n;i++)
        scanf("%d %d", sf1+i, sf2+i);
}
int main()
{
    int n;
    scanf("%d", &n);
    int k=n/2;
    string s1(n, '0'), s2(n, '0');
    ReadInput(n);

    /*solving for case k=0*/
    int ptr1=0, ptr2=0;
    for(int i=0;i<n;i++)
    {
        if(sf1[ptr1]<sf2[ptr2])
            s1[ptr1++]='1';
        else
            s2[ptr2++]='1';
    }
//        cout<<s1<<'\n'<<s2<<endl;

    /*solving for case k=n/2*/
    for(int i=0;i<n/2;i++)
        s1[i]=s2[i]='1';

    cout<<s1<<'\n'<<s2;
    return 0;
}

