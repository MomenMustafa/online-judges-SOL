#include<bits/stdc++.h>
using namespace std;
// UVA 12157
int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        int mile = 0, juice = 0;
        for (int i = 0; i < n; i++)
        {
            int minutes;
            scanf("%d", &minutes);
            ++minutes;
            mile += (minutes+29) / 30 * 10;
            juice += (minutes+59) / 60 * 15;
        }
        
        printf("Case %d: ", i);
        if (mile < juice)
            printf("Mile %d\n", mile);
        else if (juice < mile)
            printf("Juice %d\n", juice);
        else
            printf("Mile Juice %d\n", mile);
    }
    
    return 0;
}