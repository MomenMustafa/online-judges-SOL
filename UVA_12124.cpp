#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

vector<vector<pair<int, int>>>vec;
map<string, int>mp;

bool canBuy(int lowestComponentQuality, int &budget)
{
    ll sum=0;
    for(int i=0;i<vec.size();i++){
       auto it = lower_bound(vec[i].begin(), vec[i].end(), make_pair(lowestComponentQuality,0));
        sum+=(*it).S;
    }
    return sum <= budget;
}

int binarySearch(int a, int b, int &budget)
{
    while(a<b)
    {
        int mid = (a+b)/2 +1;
        if(canBuy(mid, budget))
            a=mid;
        else
            b=mid-1;
    }
    return a;
}

int main() {
//    freopen("lol.txt", "W", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        vec.clear();
        mp.clear();

        int avalComponents, budget;
        scanf("%d %d", &avalComponents, &budget);
        int idx=0;
        while(avalComponents--)
        {
            string type, name;
            cin>>type>>name;
            int quality, price;
            scanf("%d %d", &price, &quality);

            if(mp.find(type)==mp.end())
            {
                mp[type]=idx++;
                vec.push_back(vector<pair<int, int>>());
            }
            vec[mp[type]].push_back({quality, price});
        }

        int maxLowestComponent=INT_MAX;
        for(int i=0;i<vec.size();i++){
            sort(vec[i].begin(),vec[i].end(),[](pair<int,int> l,pair<int,int> r)
        {
            if(l.first == r.first)
                return l.second > r.second;
            return l.first < r.first;
        });
            maxLowestComponent=min(maxLowestComponent, vec[i][vec[i].size()-1].F); // upper limit for our binary search (best possible answer)

            int dumpComponents=INT_MAX;
            vector<pair<int, int>>newList; // components after removing unnecessary components (expensive & less quality)
            for(int j=vec[i].size()-1;j>=0;j--)
            if(vec[i][j].S < dumpComponents){
                dumpComponents=vec[i][j].S;
                newList.push_back(vec[i][j]);
            }
            vec[i].clear();
            for(int j=newList.size()-1;j>=0;j--)
                vec[i].push_back(newList[j]);
        }
        printf("%d\n", binarySearch(0, maxLowestComponent, budget));
    }
    return 0;
}
