#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(n==1) return puts("1"), 0;
    int leftDist=m-1, rightDist=n-m;
    printf("%d", (leftDist>=rightDist?m-1:m+1));
    return 0;
}
