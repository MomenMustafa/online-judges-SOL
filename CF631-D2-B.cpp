#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

int main()
{
     int n, m, k;
     scanf("%d%d%d", &n, &m, &k);

     int paper[n][m];
     memset(paper, 0, sizeof(paper));

     while(k--)
     {
         int op, dimension, color;
         scanf("%d %d %d", &op, &dimension, &color);
         int deltaR = op==2;
         int deltaC = !deltaR;
         int length = (op==2 ? n:m);
//         cout<<op<<endl;
         int r=(op==1? dimension-1:0);
         int c=(op==2? dimension-1:0);

//         cout<<r<<' '<<c<<' '<<deltaR<<' '<<deltaC<<' '<<length<<endl;
         for(int i=0;i<length;i++)
         {
            paper[r][c]=color;
            r+=deltaR;
            c+=deltaC;
         }
     }

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
            printf("%d ", paper[i][j]);

         puts("");
     }
    return 0;
}

