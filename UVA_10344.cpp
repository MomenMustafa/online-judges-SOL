#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ans=0;

bool canFind23(int a[], int idx, int sum)
{
    if(idx==5)
        return sum == 23;


    return canFind23(a, idx+1, sum+a[idx]) || canFind23(a, idx+1, sum-a[idx]) || canFind23(a, idx+1, sum*a[idx]);

}

void permutate(int a[], int l, int r)
{
    if(ans) return;

    if(l==r)
    {
       ans = canFind23(a, 1, a[0]);
       return;
    }

    for(int i=l;i<=r;i++)
    {
        swap(a[l],a[i]);
        permutate(a, l+1, r);
        swap(a[l],a[i]);
    }
}


int main()
{
    int a[5];
    while(scanf("%d %d %d %d %d", a, a+1, a+2, a+3, a+4)&&a[0]!=0)
    {
        permutate(a, 0, 4);
            puts((ans?"Possible":"Impossible"));
            ans=false;

    }
    return 0;
}
