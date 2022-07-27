#include <bits/stdc++.h>

using namespace std;

bool discovered[(int)1e3+5];
vector<int>primes;
void seive(int n)
{
    discovered[0]=discovered[1]=1;
    primes.push_back(2);
    for(int i=2;i<n;i+=2)
        discovered[i]=1;

    for(int i=3;i<=n;i+=2)
        if(!discovered[i])
        {
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i)
                discovered[j]=1;
        }

}

int main()
{
    int n;
    scanf("%d", &n);
    if(n==1)
        return puts("0"), 0;

    seive(n);
    int sz = primes.size();
    for(int i=0;i<sz;i++)
    {
        int x = primes[i]*primes[i];
        while(x<=n)
            primes.push_back(x),x*=primes[i];
    }

    printf("%d\n", primes.size());
    for(int i=0;i<primes.size();i++)
        printf("%d ", primes[i]);


    return 0;
}
