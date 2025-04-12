#include<bits/stdc++.h>
using namespace std;


// Problem: UVA 12696 - The Bag
// Contest: UVA - 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
int main()
{
    int t, acceptedBags = 0;
    scanf("%d", &t);
    while (t--)
    {
        double a, b, c, w;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &w);

        bool allowed = 0;
       // printf("%lf %lf %lf %lf\n", a, b, c, w);
        if((a+b+c <= 125 && w<=7) || (a <=56 && b <= 45 && c <= 25 && w <= 7))
            allowed = true;

        acceptedBags += allowed;

        printf("%d\n", allowed);
    }
    printf("%d\n", acceptedBags);

    return 0;
}