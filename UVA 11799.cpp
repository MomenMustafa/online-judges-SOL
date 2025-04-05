#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>> t;
    cin.ignore();
    for (int i = 1; i <= t; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);

        int n, ans=-1e9;
        while (ss>> n)
        {
            ans = max(ans, n);
        }
        
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    


    return 0;
}