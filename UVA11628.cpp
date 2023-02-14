#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    //freopen("momen.txt", "w", stdout);
    int n, m;
    while(scanf("%d %d", &n, &m)==2)
    {
        if(n==0) return 0;

        int total=0;
        int arr[n][m];
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++)
                scanf("%d", &arr[i][j]);

            total+=arr[i][m-1];
        }

        for(int i=0;i<n;i++)
        {
            int div=gcd(arr[i][m-1], total);
            printf("%d / %d\n", arr[i][m-1]/div,total/div);
        }
    }

    return 0;
}
