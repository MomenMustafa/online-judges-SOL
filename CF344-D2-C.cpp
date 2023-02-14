#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a7a(ll a, ll b)
{
    if(b<=1)return a;
    return a/b + a7a(b, a%b);
}

int main()
{
    ll a, b;
    cin>>a>>b;
    cout<<a7a(a, b);

    return 0;
}
