#include <stdio.h>
#include<map>
#include<iostream>
#define ll long long
using namespace std;

int main()
{
    freopen("tst.txt", "w", stdout);
    int n, a, b;
    while(scanf("%d", &n)==1 && n)
    {
        scanf("%d %d", &a, &b);
        int x =0;
        map<ll, int>s;
        int steps =0;
        while(s.find(x)==s.end())
        {
//            cout<<x<<endl;
            s[x]=steps++;
            x=(((1ll*(a%n) * (x%n))%n * (x%n))%n + 1ll*b)%n;
        }
        ll repeated = s.size()-s[x];
        printf("%d\n", n-repeated);

    }
    return 0;
}

