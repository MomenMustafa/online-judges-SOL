#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
string a, b;
int dp[102][102];
int lcs(int i, int j)
{
    if(i<0 || j<0)
        return 0;

    int &ret=dp[i][j];

    if(ret != -1) return ret;
    if(a[i]==b[j]){
//        cout<<a[i]<<endl;
        return ret = 1+lcs(i-1, j-1);
    }
    int path1 = lcs(i-1, j);
    int path2 = lcs(i, j-1);
    ret = max(path1, path2);
    return  ret;
}

int main()
{
//    freopen("tst.txt", "w", stdout);
    int d = 1;
    while(getline(cin, a))
    {
        if(a=="#") break;
        getline(cin,b);
//        cout<<a<<endl<<b<<endl;
        for(int i=0;i<102;i++)
            for(int j=0;j<102;j++)
                dp[i][j]=-1;

        printf("Case #%d: you can visit at most %d cities.\n",d++, lcs(a.size()-1, b.size()-1));
    }
    return 0;
}
