#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fastPower(ll n, ll mod, ll base=3)
{
    if(n==0)
        return 1ll;

    if(n&1)
        return (3%mod * fastPower(n-1, mod)%mod)%mod;
    ll tmp = fastPower(n/2, mod);
    return (tmp%mod * tmp%mod)%mod;
}
int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll ans = fastPower(n, m);
    cout<<ans<<endl;
    printf("%lld", (ans==0? 0:ans-1));
    return 0;
}
