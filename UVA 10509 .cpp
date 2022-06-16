#include <bits/stdc++.h>

using namespace std;

int binSrch(int n)
{
    int low = 1;
    int high = 105;

    while(low<high)
    {
        int mid = (low + high)/2 +1;

        if(mid * mid * mid <=n)
            low = mid;
        else
            high = mid-1;
    }
    return low;
}

int main()
{
    double n;
    while(scanf("%lf", &n) && (int)n)
    {
        int a = binSrch(n);
//        cout<<a<<endl;
       printf("%.4lf\n", a+(n-a*a*a)/(3*a*a));
    }
    return 0;
}
