#include <bits/stdc++.h>

using namespace std;

short dx[] = {0,1};
short dy[] = {1,0};
int dp[(int)1e3+1][(int)1e3+1];
bool grid[(int)1e3+1][(int)1e3+1];
int r, c;
bool valid(int x, int y)
{
    return !(x==r || y==c || x<0 || y < 0 || grid[x][y]==1);
}

int solve(int row, int col)
{
    if( !valid(row, col)) return 0;           //invalid path
    if( row == r-1 && col == c-1 ) return 1;  //base case

    if(dp[row][col]!=-1) return dp[row][col];
    int paths=0;
    for(int i=0;i<2;i++)
    {
        paths+= solve(row+dx[i], col+dy[i]);
    }

    return dp[row][col]=paths;
}

int solve2(int row, int col)
{

    for(int i=r-1;i>-1;i--)
    {
        for(int j=c-1;j>-1;j--)
        {
            if(i==r-1 && j == c-1) dp[i][j]=1;
            else
            {
                int paths=0;
                for(int k=0;k<2;k++)
                {
                    if(valid(i+dx[k],j+dy[k]))
                    {
                        paths+=dp[i+dx[k]][j+dy[k]];
                    }
                }

                dp[i][j] = paths;
            }
        }
    }

    return dp[0][0];
}

int main()
{
    int t;
    cin>>t;
    bool f= false;
    while(t--)
    {

        cin>>r>>c;
        cin.ignore();
        memset(grid, 0, sizeof grid);
        memset(dp, -1,sizeof dp);
        for(int i=0;i<r;i++)
        {
            string row; int block;
            getline(cin,row);
            stringstream ss(row);
            ss>>block;               /// row number
            while(ss>>block)
            {
                grid[i][block-1]=1;
            }
        }

///  input processing is finished


      if(f)puts("");
      int ans = solve2(0,0);
      cout<<ans<<endl;
      f = true;

        /*cout<<solve(0,0);
        if(t)puts("");
        ;*/
    }
    return 0;
}
