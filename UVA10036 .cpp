#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

class Division
{
    vector<int>numbers;
    int k;
    int8_t dp[100+1];

    int Mod(int n){return ((n%k)+k)%k;}
public:
    ///Division(){memset(dp, -1, sizeof(dp));}
//    bool IsDivisable(int i, int sum)
//    {
//        if(i==numbers.size())
//            return sum == 0;
//
//        int8_t &ret=dp[i][sum];
//        if(ret!=-1) return ret;
//
//        if(IsDivisable(i+1, (sum+numbers[i])%k)|| IsDivisable(i+1, (sum-numbers[i])%k))
//            return ret = true;
//
//        return ret = false;
//    }
    bool IsDivisable()
    {
        int p=1;
        for(int i=numbers.size();i>=0;i--)
        {
            p = !p;
            for(int sum=k;sum>=0;sum--)
            {
                if(i==numbers.size())
                {
                    dp[sum] = (sum == 0);
                    continue;
                }

                if(dp[Mod((sum+numbers[i]))]==1||dp[Mod((sum-numbers[i]))]==1)
                {
                    dp[sum] = 1;
                    continue;
                }

                 dp[sum] = 0;
            }
        }
        return dp[0];
    }
    void SetNums(vector<int>nums){numbers=nums;}
    void SetK(int k){this->k = k;}
};
int main()
{
    freopen("tst.txt", "w", stdout);
    int t;
    int n, k;
    scanf("%d", &t);
    while(t--)
    {
        vector<int>nums;
        Division div;
        short arr[n][k];
        scanf("%d %d", &n, &k);

        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d", &x);
            nums.push_back(x);
        }

        div.SetNums(nums);
        div.SetK(k);
        puts((div.IsDivisable()==1? "Divisible":"Not divisible"));
    }
    return 0;
}
