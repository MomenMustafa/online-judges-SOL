#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
using namespace std;

long long sum(ull n)
{
    ull sum = (n / 2) * (n + 1);
    if (n % 2 != 0) sum += (n + 1) / 2;

    return sum;
}

long long binSearch(ull n)
{
    ull l=0, r=1414213562+1;

    while (l<r)
    {
        ull mid = l +  (r-l)/2+1; 

        if(sum(mid)<= n)
         l = mid;
        else
         r = mid-1;
    }
    return l;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while (t--)
    {
        
        ull n, i;
        cin>> n;
       
       // cout<<binSearch(n)<<endl;

       cout<<(int)(-1+sqrt(1+8*n))/2<<endl;
    }
    
    return 0;
}