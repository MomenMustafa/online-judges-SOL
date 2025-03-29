#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
short winds[10][1000];
int dp[10][1000+5]; 
int x;
int solve(int i, int alt)
{
  //  if(alt > 9 || alt < 0) return -INF;

    if(dp[alt][i]!= -1) return dp[alt][i];
    
    if(i == x)
        if(alt == 9) return 0;
        else return -INF;

    int mn = -INF;
    if(alt > 0) // up
        mn = max (solve(i+1, alt-1)  - 60 + winds[alt][i], mn);
 
    mn = max(mn,solve(i+1, alt) - 30 + winds[alt][i]);  //same

    if(alt < 9) // down
        mn = max(mn,solve(i+1, alt+1) - 20 + winds[alt][i]);

    return dp[alt][i] = mn;
}

int solve2(int i, int alt)
{
    for(int j=0;j<9;j++) dp[j][x] = -INF;
    dp[9][x] = 0;

    for( i=x-1;i>=0;i--)
    {
        for(alt=9; alt>= 0 ; alt--)
        {
            int mn = -INF;
            if(alt > 0) // up
                mn = max (dp[alt-1 ][i+1] - 60 + winds[alt][i], mn);
         
            mn = max(mn,dp[alt][i+1] - 30 + winds[alt][i]);  //same
        
            if(alt < 9) // down
                mn = max(mn,dp[alt+1][i+1] - 20 + winds[alt][i]);

            dp[alt][i] = mn;
        }
    }
    return dp[9][0];
}

// void path(int i, int alt)
// {
//     if(alt > 9 || alt < 0) return;

//     if(i == x)
//         if(alt == 9) return ;
//         else return;

//     int & ret = dp[alt][i];

//     cout<< ret<<' ';
//     if(ret == 1) // up
//     {
//         path(i+1, alt-1);
//     }
//     else if(ret == 2)
//     {
//         path(i+1, alt);
//     }
//     else 
//         path(i+1, alt+1);

// }

/*
    alt+1, i+1 
     dp[alt][i] = max(dp[alt+1][i+1], dp[alt][i])
     dp[alt-1][i-1] = max(dp[alt][i], dp[alt-1][i-1])
     dp[alt+1][i-1] = max(dp[alt][i], dp[alt+1][i-1])
     dp[alt][i-1] = max(dp[alt][i], dp[alt][i-1])

    dp[alt][i] = max(dp[alt+1][i+1], dp[alt-1][i+1], dp[alt][i+1])

*/
int main()
{
    int t;

    cin>> t;
    while (t--)
    {
        cin>>x;
        x/=100;
       // memset(dp, -1, sizeof dp);

        for(int i=0;i<10;i++)
            for (int j = 0; j < x; j++)
                cin>>winds[i][j];
            

        cout<<-solve2(0,9);
        puts("\n");
      // path(0, 9);
    }
    
    return 0;
}