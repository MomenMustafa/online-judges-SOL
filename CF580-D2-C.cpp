#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
    int id;
    vector<int> connectedTo;
    int consecutiveCats;
    int visited=0;
};

int availableResturants(node graph[], int m)
{
    queue<node>q;
    q.push(graph[0]);
    graph[0].visited=1;
    int resturants=0;
    while(!q.empty())
    {
        node current = q.front();
        q.pop();
        bool isLeafNode = true;
        for(int i=0;i<current.connectedTo.size();i++)
        {
            if(graph[current.connectedTo[i]].visited==0)
            {
                isLeafNode=false;
                graph[current.connectedTo[i]].consecutiveCats = (graph[current.connectedTo[i]].consecutiveCats==1? current.consecutiveCats+1 : 0);
                graph[current.connectedTo[i]].visited=1;
                if(graph[current.connectedTo[i]].consecutiveCats>m) continue;
                q.push(graph[current.connectedTo[i]]);
            }
        }

        if(isLeafNode&& current.consecutiveCats<=m)
            ++resturants;

    }
return resturants;
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    node graph[n];

    for(int i=0;i<n;i++)
        scanf("%d", &graph[i].consecutiveCats);

    for(int i=0;i<n-1;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x-1].connectedTo.push_back(y-1);
        graph[y-1].connectedTo.push_back(x-1);
        graph[x-1].id = x;
        graph[y-1].id = y;
    }

    cout<<availableResturants(graph, m);
    return 0;
}
