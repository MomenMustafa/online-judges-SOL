#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x;
    int y;

    //point();
    //point(int a, int b): x(a), y(b) {};

    static double dist(point a, point b)
    {
        double xDist = (a.x - b.x) * (a.x - b.x);
        double yDist = (a.y - b.y) * (a.y - b.y);

        return sqrt(xDist + yDist);
    }
};


int n;
bool visited[16];
point points[16];

double solve(int g, double dist)
{
    if(g>=n) return dist;

    double ans = 1e9;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            for (int j = i+1; j <n ; j++)
            {
                if(!visited[j])
                {
                    visited[j] = 1;

                    ans = min(ans, solve(g+2, dist+ point::dist(points[i], points[j])));

                    visited[j] = 0;
                }
            }
            
            visited[i] = 0;
        }
    }

    return ans;
}

int main()
{
   cin>> n;
   n*=2;

   for (int i = 0; i < n; i++)
   {
    cin>> points[i].x>>points[i].y;
   }
   //cout<<point::dist(points[0], points[1])<<endl<<sqrt(5);
   cout<<solve(0, 0);

    return 0;
}