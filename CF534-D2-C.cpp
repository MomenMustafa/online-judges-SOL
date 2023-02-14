#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;


int main()
{
    ll n, sum, SUM=0;
    scanf("%lld%lld",&n, &sum);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", arr+i), SUM+=arr[i];


    ll upper = sum-(n-1);
    for(int i=0;i<n;i++)
    {
        ll currUpper=min(upper, 1ll*arr[i]);
        ll lower=max(1ll, -1*(SUM-arr[i]-sum));
        printf("%d ", arr[i]-(currUpper-lower+1));
    }


    return 0;
}

