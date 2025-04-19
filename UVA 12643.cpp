#include<bits/stdc++.h>
using namespace std;
// UVA 12643
int fastPower(int a, int b) {
    if(b==0) return 1;
    int ans = fastPower(a,b/2);
    ans=ans*ans;
    if(b&1)
      return a*ans;
    return ans;
  }

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, one, two;

    while (scanf("%d %d %d", &n, &one, &two) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            one = (one+1) / 2;
            two = (two+1) / 2;

            if (one == two)
            {
                cout << i << endl;
                break;
            }
        }
      
    }

    return 0;
}