#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fastPow(ll b, ll p)
{
    ll r=1;
    while(p)
    {
        if(p&1)
            r = r*b;

        b= b*b;
        p>>=1;
    }
    return r;
}

int n, a, b;
inline ll f(int x)
{
    return ((((1ll*a%n)*1ll*(x%n))%n * (x%n))%n +b)%n;
}
int main() {

	while(scanf("%d", &n)==1 && n)
    {
        scanf("%d %d", &a, &b);
        ll slow = b;
        ll fast = f(slow);

        cout<<"being\n";
        while(slow != fast)
            slow = f(slow), fast=f(f(fast));
        cout<<"fsd "<< fast<<endl;
        ll ans=0;
        slow=b;
        while (slow!=fast);
            slow=f(slow), fast=f(fast), ++ans;

        printf("%lld\n", ans);
    }
return 0;
}
