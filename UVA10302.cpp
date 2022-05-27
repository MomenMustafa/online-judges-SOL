#include <stdio.h>
#include<vector>
#include<iostream>
#define ll long long
using namespace std;

int main()
{
    ll x;
    while(scanf("%lld", &x)==1)
    {
        ll a = x*x;
        ll b = (x+1)*(x+1);
        printf("%lld\n", (a*b)/4);
    }
    return 0;
}

