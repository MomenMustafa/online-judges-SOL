#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>

#define ll long long
using namespace std;

class operation
{
    public:
    int l, r; ll d;
    operation(){};
    operation(int l, int r, ll d){
        this->d = d;
        this->l = l-1;
        this->r = r-1;
    };
};

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    ll arr[n];
    for(int i=0;i<n;i++)
        scanf("%lld", &arr[i]);

    operation operations[m];
    for(int i=0;i<m;i++)
        scanf("%d %d %lld", &operations[i].l, &operations[i].r, &operations[i].d);

    int repeatRange[m]={0};
    for(int i=0;i<k;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        repeatRange[x-1]+=1;
        if(y!=m)
            repeatRange[y]-=1;
    }
    for(int i=1;i<m;i++)
        repeatRange[i]+=repeatRange[i-1];

    for(int i=0;i<m;i++)
        operations[i].d*=repeatRange[i];

    ll finalForm[n]={0};
    for(int i=0;i<m;i++){
        int l=operations[i].l-1, r=operations[i].r-1;
        finalForm[l]+=operations[i].d;
        if(r+1!=n)
            finalForm[r+1]-=operations[i].d;
    }
    for(int i=1;i<n;i++)
        finalForm[i]+=finalForm[i-1];
    for(int i=0;i<n;i++)
        printf("%lld ", finalForm[i]+arr[i]);
    return 0;
}
