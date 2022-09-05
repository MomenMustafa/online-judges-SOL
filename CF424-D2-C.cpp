#include <bits/stdc++.h>

using namespace std;

int f[(int)1e6+2];
int main()
{
//    freopen("tst.txt", "w", stdout);
    int n;
    int Q=0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        f[i]=f[i-1]^i;
        Q^= x^f[n%i]^ ((n/i)%2 * f[i-1]);
    }
    printf("%d", Q);
    return 0;
}
