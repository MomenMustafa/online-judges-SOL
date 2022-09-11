#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;


int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    int p[n];
    for(int i=0;i<n;i++)
        scanf("%d", p+i);

    ll ans=0;
    for(int i=0;i<n-2;i++)
    {
//        cout<<*(upper_bound(p+i,p+n, 1ll*d+p[i]))<<endl;
       int upper = (upper_bound(p+i,p+n, 1ll*d+p[i])-p)-1;
       int range = upper - i - 1;
       ans += (range+1)*1ll*range/2;
    }
    printf("%lld", ans);
    return 0;
}
