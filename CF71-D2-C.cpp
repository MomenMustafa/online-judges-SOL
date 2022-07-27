#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void divisors(int n, vector<int>& divs)
{
    for(int i=1;i*i<=n;i++)
        if(n%i==0)
        {
          divs.push_back(i);
          divs.push_back(n/i);
        }
}
int main()
{
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        s.push_back(c);
    }
 
    vector<int>divs;
    divisors(n, divs);
    string t=s;
 
    for(int it=0;it<divs.size();it++)
    {
        if(divs[it]<3) continue;
        int inc = n/divs[it];
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='0') continue;
            bool poly = true;
            int cnt=divs[it];
            for(int j=i;cnt--;j=(j+inc)%n)
            {
//                puts("ay 7aga");
                if(t[j]=='0') poly = 0;
                t[j]='0';
            }
            if(poly)
             return puts("YES"), 0;
 
        }
 
 
        t=s;
    }
    puts("NO");
    return 0;
}
