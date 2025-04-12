#include<bits/stdc++.h>
using namespace std;


// UVA 11683 - Laser Sculpture
int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b), b)
    {
        int last;
        scanf("%d", &last);

        int ans = a - last;

        for (int i = 1; i < b; i++)
        {
            int current;
            scanf("%d", &current);
            if( current != a)
            {
                int tmp = last - current;
                if(tmp > 0) ans += tmp;
            }
            last = current;
        }

        printf("%d\n", ans);
        
    }
    return 0;
}