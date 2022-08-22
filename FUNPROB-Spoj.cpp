#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;


int main() {
//    freopen("lol.txt", "W", stdout);
    int ten, five;
    while(scanf("%d %d", &ten, &five)==2 && ten+five!=0)
    {
        if(five<ten)  puts("0.000000");
        else
            printf("%.6lf\n", (1.0*five-ten+1)/(1.0*five+1));
    }
    return 0;
}
