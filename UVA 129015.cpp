#include<bits/stdc++.h>

using namespace std;


// uva129015
int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n, maxScore=-1e9;
        string s;
        vector<vector<string>>google(100);
        for (int i = 0; i < 10; i++)
        {
            cin>>s>>n;
            cin.ignore();

            google[n-1].push_back(s);
            maxScore = max(maxScore, n);
        }

         cout<< "Case #"<<i+1<<":\n";
        for (const string& url : google[maxScore-1])
        {
            cout << url << endl;
        }
        
    }
    

    return 0;
}