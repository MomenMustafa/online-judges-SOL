#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline int digitsNum(unsigned ll x){
    int digits=0;
    while(x) ++digits, x/=10;
    return digits;
}

ll nines(int digits)
{
     ll num=0;
    while(digits--)
        num= num*10 + 9;
    return num;
}
 ll reversing(ll rev, int rightMostZerors)
{
    ll ans=0;
    while(rev)
    {
        ans= ans*10 + rev%10;
        rev/=10;
    }

    while(rightMostZerors--) ans*=10;
    return ans;
}
ll getRigthMostDigits(int n, ll tmp)
{
    ll reversed = 0;
    int rightMostZeros=0;
    bool rightMost = true;
    while(n--)
    {
        if(tmp%10==0&&rightMost) ++rightMostZeros;
        else rightMost = false;

        reversed = reversed * 10 + tmp%10;
        tmp/=10;
    }

    return reversing(reversed, rightMostZeros);
}
int main()
{
    ll p, d;
    cin>>p>>d;

    if(d == 0)
        return cout<<p, 0;
    int digitsOfd = digitsNum(d);
    ll nine = nines(digitsOfd);
    ll tmp = p - nine;
//    cout<<tmp<<endl;
//    cout<<getRigthMostDigits(digitsOfd, tmp)<<endl;
    if(nine<p&&getRigthMostDigits(digitsOfd, tmp)<=d)
       cout<< p - getRigthMostDigits(digitsOfd, tmp);
    else
    {
        nine/=10;
        tmp=p-nine;
        cout<< p - getRigthMostDigits(digitsOfd-1, tmp);
    }
    return 0;
}
