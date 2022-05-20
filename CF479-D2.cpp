#include <stdio.h>
#include<vector>
#include<iostream>
 
using namespace std;
 
pair<int, int> GetMinMax(int towers[], int n)
{
    int mx=-1, mn=1e4+5;
    int idxMax=-1, idxMin=-1;
 
    for(int i=0;i<n;i++)
    {
        if(towers[i]>mx)
            mx=towers[i], idxMax=i;
        if(towers[i]<mn)
            mn=towers[i], idxMin=i;
    }
//    cout<<mn<<' '<<mx<<"++++ ";
    return make_pair(idxMin, idxMax);
}
 
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int copyK=k;
    int towers[n];
    for(int i=0;i<n;i++)
        scanf("%d", towers+i);
 
    vector<pair<int, int>>ans;
    while(k>0){
        pair<int, int> current = GetMinMax(towers, n);
        if(towers[current.second]-towers[current.first]==0)
            break;
 
        towers[current.first]++;
        towers[current.second]--;
        ans.push_back(current);
        k--;
    }
    pair<int,int> x = GetMinMax(towers, n);
//    for(int i=0;i<n;i++)
//        cout<<towers[i]<<' ';
//    puts("");
//    cout<<x.second<<'*'<<x.first<<endl;
 
    int instability=towers[x.second] - towers[x.first];
    printf("%d %d\n", instability, copyK-k);
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n", ans[i].second+1, ans[i].first+1);
    return 0;
}

