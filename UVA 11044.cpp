#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        n-=2, m-=2;
        n = (n+2)/3; m = (m+2)/3;
        printf("%d\n", n*m);
    }
    
    return 0;
}