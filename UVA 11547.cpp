#include<bits/stdc++.h>

using namespace std;

int mod(int n, int m)
{
    return (n%m+m)%m;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
         n = n * 315 + 36962;
       cout<<abs((n%100)/10)<<endl;
    }
    

    
    return 0;
}