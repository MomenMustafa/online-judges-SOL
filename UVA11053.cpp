#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, a, b;
inline ll f(int x)
{
    return ((((1ll*a%n)*1ll*(x%n))%n * (x%n))%n +b)%n;
}
int main() {

	while(scanf("%d", &n)==1 && n)
    {
        scanf("%d %d", &a, &b);
        ll slow = f(0);
        ll fast = f(f(0));

        while(slow != fast)
            slow = f(slow), fast=f(f(fast));

        slow=0;
        while (slow!=fast)
            slow=f(slow), fast=f(fast);
            
        ll ans=1;
        fast = f(slow);
        while(fast != slow)
            fast=f(fast), ++ans;
            

        printf("%lld\n", n-ans);
    }
return 0;
}
