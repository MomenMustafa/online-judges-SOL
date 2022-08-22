#include <bits/stdc++.h>
#define ll long long

using namespace std;

int row, col;
vector<vector<int>>ans;
vector<int>queens(8, 0);
int rDiagonals[20];
int lDiagonals[20];

void reset()
{
    for(int i=0;i<8;i++)
        queens[i]=0;
}

void Queen(int r)
{
   if(r==row)
        Queen(r+1);

   if(r==8){
    ans.push_back(queens);
    return;
   }

   for(int i=0;i<8;i++)
   {
       if(queens[i]==0&& rDiagonals[r-i+8]==0 && lDiagonals[r+i]==0)
       {
           queens[i]=r+1;
           rDiagonals[r-i+8]=lDiagonals[r+i]=1;
           Queen(r+1);
           queens[i]=0;
           rDiagonals[r-i+8]=lDiagonals[r+i]=0;
       }
   }
}

int main() {
    freopen("tst.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &row, &col);
        --row, --col;
        queens[col]=row+1;
        rDiagonals[row-col+8]=lDiagonals[row+col]=1;
        Queen(0);
        sort(ans.begin(), ans.end());
        puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        for(int i=0;i<ans.size();i++)
        {
            printf("%2d      ", i+1);
            for(int j=0;j<8;j++){
                printf("%d", ans[i][j]);
                if(j+1!=8)
                    printf(" ");
            }


            puts("");
        }
        if(n) puts("");
        rDiagonals[row-col+8]=lDiagonals[row+col]=0;
        ans.clear();
        reset();
    }

    return 0;
}
