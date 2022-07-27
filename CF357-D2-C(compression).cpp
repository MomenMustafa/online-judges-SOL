#include <bits/stdc++.h>
#define ll long long
using namespace std;

int getNext(int v, int next[])
{
    if(next[v]==v) return v;

    return next[v] = getNext(next[v], next);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int next[n], answer[n+1];

    for(int i=0;i<n;i++)
        next[i]=i, answer[i]=-1;
    next[n]=n;


    while(m--)
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        --l, --r, --x;

        int cur= getNext(l, next);
        while(cur <=r)
        {
            if(cur == x)
                cur+=1;
            else
            {
                answer[cur]=x;
                next[cur]=cur+1;
            }

            cur = getNext(cur, next);
        }

    }
    for(int i=0;i<n;i++)
        printf("%d ", answer[i]+1);
    return 0;
}
