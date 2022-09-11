#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int a[100005];
int sum[100005];
bool better(int i) /// current bit is better than the sum of all lower bits
{
    if(i==0) return true;
//    cout<<sum[i-1]<<' '<<a[i]<<endl;
    return sum[i-1]<a[i];
}
int sumRemainingBits(int &i, vector<int>&v)
{
    int sumBits=0;
    for(;i>=0;i--)
        sumBits+=a[v[i]];

    return sumBits;
}
int solve(int& n, vector<int>&v)
{
    int ans=0;
    int mx1=0, mx2=0;
    for(int i=v.size()-1;i>=0;i--)
    {
//        cout<<v[i]<<endl;
//        if(better(v[i]))
//        {
//            ans +=sumRemainingBits(i, v);
//            cout<<ans<<"sdf\n";
//            break;
//        }
        mx1+= a[v[i]];
        mx2=max(mx1-a[v[i]]+(v[i]==0?a[0]:sum[v[i]-1]), mx2);
        ans=max(mx1, mx2);
//        cout<<ans<<endl;
    }
    return ans;
}
void comulativeSum(int n)
{
    sum[0]=a[0];
    for(int i=1;i<n;i++) sum[i]+=sum[i-1]+a[i];
}
int main(){
   int n;
   scanf("%d", &n);
   for(int i=0;i<n;i++) scanf("%d", a+i);
    comulativeSum(n);
   char c;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
       scanf(" %c", &c);
       if(c=='1') v.push_back(i);
   }
//    cout<<v.size()<<endl;
   printf("%d",solve(n, v));
    return 0;
}
