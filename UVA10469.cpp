#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;
ll a, b, n, m=2000000011, pa, pb, s;

inline ll gcd(ll a, ll b) {
	if(a&&b)
		while((a%=b)&&(b%=a));
	return a^b;
}

ll Lcm(ll a, ll b){
    return a*b/gcd(a, b);
}
int main() {
    //freopen("tst.txt", "w", stdout);
	unsigned int a, b;
	while(scanf("%d %d", &a, &b)==2)
    {
        int ans=0;
        int bitNum=0;
        while(a||b)
        {
//            bitset<8>num1(a), num2(b);
//            cout<<num1<<endl<<num2<<endl;
            int bit1 = a&1, bit2 = b&1;
            int bit3=bit1^bit2;
            ans= ans|(bit3<<bitNum++);
            a>>=1 , b>>=1;
        }
        printf("%d\n", ans);
    }

return 0;
}
