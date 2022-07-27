#include <bits/stdc++.h>
#define ll long long
using namespace std;

int getNext(int v, int next[])
{
    if(next[v]==v) return v;

    return next[v] = getNext(next[v], next);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    set<int> st;
    int answer[n]={};

    for(int i=0;i<n;i++)
        st.insert(i);

    while(m--)
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        --l, --r, --x;

        vector<int>toErase;
        for( set<int>::iterator it=st.lower_bound(l);it!=st.end();it++){
                int lol= *it;
                if(lol > r) break;

                if(lol != x){

                toErase.push_back(lol); answer[lol]=x+1;
                }
        }

        for(int i=0;i<toErase.size();i++)
            st.erase(toErase[i]);

    }
        for(int i=0;i<n;i++)
            printf("%d ", answer[i]);
    return 0;
}
