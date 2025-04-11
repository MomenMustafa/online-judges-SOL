#include<bits/stdc++.h> 

using namespace std;

int main()
{
    int b, n;

    while (cin>>b>>n && b)
    {
            int money[b];
            for(int i=0;i<b;i++)
                cin>>money[i];

            int d,c,v;
            while (n--)
            {
                cin>>d>>c>>v;
                money[d-1] -=v;
                money[c-1] +=v;
            }

            bool flag = false;
            for (int i = 0; i < b; i++)
            {
                if(money[i]<0) flag=true;
            }

            puts((flag)?"N":"S");
            
            
            
    }
    
    return 0;
}