#include <bits/stdc++.h>

using namespace std;

vector<int>ans, tmp, graph[100];
bool color[100];

bool canBeBlack(int node)
{
    for(int i=0;i<graph[node].size();i++)
        if(graph[node][i]==node ||color[graph[node][i]]==1)
            return false;

    return true;
}

void backtrack(int curr)
{
   if(tmp.size()>ans.size())
        ans = tmp;

   if(curr<0)
    return;

   if(curr+1+tmp.size()<ans.size())
        return;

   for(int i=curr;i>=0;i--)
   {
       if(canBeBlack(i))
       {
           color[i]=1;
           tmp.push_back(i);
           backtrack(i-1);
           color[i]=0;
           tmp.pop_back();
       }
   }
}

int main()
{
    freopen("tst.txt", "w", stdout);
    int m, n, k;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d %d",&n, &k);
        while(k--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        backtrack(n-1);
        printf("%d\n", ans.size());
        for(int i=0;i<ans.size();i++)
            if(i+1<ans.size())
            printf("%d ", ans[i]+1);
            else
                printf("%d", ans[i]+1);

        if(m)
        puts("");

        ans.clear(), tmp.clear();
        memset(color, 0, sizeof(color));
        for(int i=0;i<n;i++)
            graph[i].clear();
    }
    return 0;
}
