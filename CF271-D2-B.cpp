#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

bool prime[100000+1];
vector<int>primes;
void seive(int n)
{
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    primes.push_back(2);
    for(int i=4;i<=n;i+=2) prime[i]=0;
//    puts("passed");
    for(int i=3;i<=n;i+=2)
    if(prime[i]){
            primes.push_back(i);
            for(ll j=1ll*i*i;j<=n;j+=i) prime[j]=0;
    }
}
int steps(int x, int idx)
{
    if(idx==0) return primes[idx]-x;
    if(idx == primes.size()) return 100003 - x;

    return primes[idx]-x;
}
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d", &matrix[i][j]);

    seive(1e5);
//    cout<< lower_bound(primes.begin(), primes.end(), 2) - primes.begin()<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int idx = lower_bound(primes.begin(), primes.end(), matrix[i][j]) - primes.begin();
            matrix[i][j]= steps(matrix[i][j], idx);
//            cout<<matrix[i][j]<<' ';
        }
//        puts("");
    }

    int ans = 1e9;
    for(int i=0;i<n;i++){
        int tmp=0;
        for(int j=0;j<m;j++)
            tmp+=matrix[i][j];

        ans=min(ans,tmp);
    }

    for(int i=0;i<m;i++){
        int tmp=0;
        for(int j=0;j<n;j++)
            tmp+=matrix[j][i];

        ans=min(ans,tmp);
    }
    printf("%d", ans);
    return 0;
}
