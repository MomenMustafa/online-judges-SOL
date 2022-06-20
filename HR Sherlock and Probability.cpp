#include<bits/stdc++.h>

#define F first
#define S second
#define ll long long

using namespace std;

ll GCD(ll a, ll b) // The function runs recursive in nature to return GCD
{
    if (b == 0) // if b becomes 0 return a
        return a;
    return GCD(b, a % b); // divide to a by b to make smaller number
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){

        int n, k;
        scanf("%d %d", &n, &k);
        if(k==n)
            --k;

        char c;
        deque<int>dq;
        int cnt =0;
        for(int i=0;i<=k;i++){
            scanf(" %c", &c);

            dq.push_back(c-'0');
            cnt+= c-'0';

        }
        ll ans=1ll*cnt*cnt;
        for(int i=k+1;i<n;i++){
            cnt-= dq.front();
            dq.pop_front();
            scanf(" %c", &c);
            dq.push_back(c-'0');
            cnt+=c-'0';
            if(c=='1'){
                ans+= 2*(cnt-1)+1;
            }
        }

        if(ans == 0)
            puts("0/1");
        else{
            ll gcd =GCD(ans, 1ll*n*n);
            printf("%lld/%lld\n", ans/gcd, 1ll*n*n/gcd);
        }
    }
    return 0;
}
