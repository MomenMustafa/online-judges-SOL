#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

int main()
{
    int r, b;
    scanf("%d%d",&r, &b);

    int mn=min(r, b);

    int p, v;
    p=abs(r-b) + (mn-1);
    v=mn;
    printf("%d %d", p, v);
}

