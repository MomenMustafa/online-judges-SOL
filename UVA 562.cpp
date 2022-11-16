#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
 int coins[100];
 int total;
 int dp[100][500*100];
 int minDiff(int i, int sum)
 {
     if(sum > total/2) return 1e5;
    if(i<0){
        return abs(total-sum-sum);
    }
    if(dp[i][sum]!=-1) return dp[i][sum];

    int x=minDiff(i-1, sum+coins[i]);
    int y= minDiff(i-1, sum);
    return dp[i][sum]=min(x, y);
 }
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;scanf("%d",&coins[i++]),total+=coins[i-1]);
        memset(dp, -1, sizeof(dp));
        cout<<minDiff(n-1, 0)<<endl;
        total = 0;
    }
    return 0;
}
