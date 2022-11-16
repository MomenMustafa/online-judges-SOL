#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
// int coins[100];
// int total;
// int dp[500*100+1];
// int n;

class CuttingBitString{
public:
string letters = "0123456789ABCDEF";
int dp[51];
int toInt(char c) {return letters.find(c);}
ll BaseToDecimal (string in, int base){
ll res=0;
for(size_t i=0;i<in.size();i++)
    res=res*base+toInt(in[i]);
return res;
}

string Decimal(int number, int base){
if(number == 0)
    return "0";
string res="";
for(;number;number/=base)
    res=letters[number%base] + res;
return res;
}
bool ispw5(string s)
{
    return ispw5(BaseToDecimal(s, 2));
}
bool ispw5(ll n)
{
    if(n==1)return 1;
    if(n==0)return 0;

    while(n%5==0)n/=5;

    return n==1;
}

public:
int getmin(string s)
{

        for(int i=s.size();i>=0;i--)
    {
        if(i==s.size())
        {
            dp[i]=0;
            continue;
        }

    if(s[i]=='0')
    {
        dp[i]= 1e5;
        continue;
    }

    int cnt=1e5;
    string num="";
    for(int j=i;j<s.size();j++)
    {
        num+=s[j];
        if(ispw5(num))
        {
//                cout<<num<<endl;
                cnt=min(cnt, 1+dp[j+1]);
        }
    }
     dp[i]=(cnt>=1e5? 1e5:cnt);
    }

    return (dp[0]==1e5 ? -1 :dp[0]);
}

//int getmin(string& s, int i)        /// focus here dude
//{
//    if(i==s.size())
//        return 0;
//    if(s[i]=='0') return dp[i]= 1e5;
//
//    if(dp[i]!=-1) return dp[i];
//    int cnt=1e5;
//    string num="";
//    for(int j=i;j<s.size();j++)
//    {
//        num+=s[j];
//        if(ispw5(num))
//            {
////                cout<<num<<endl;
//                cnt=min(cnt, 1+getmin(s, j+1));
//            }
//    }
//    return dp[i]=(cnt>=1e5? 1e5:cnt);
//}
//};

int main()
{
    string s;
    cin>>s;
//    cout<<s.size();
    CuttingBitString cbs;
    cout<<cbs.getmin(s)<<endl;

    return 0;
}
