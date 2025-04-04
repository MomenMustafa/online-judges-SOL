#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    int line =1;
    while (t--)
    {
        int l,w,h;
        cin>>l>>w>>h;
        
        cout<<"Case "<<line++<<": ";
        if(l<=20 && w<= 20 && h<= 20)
            cout<<"good\n";
        else
            cout<<"bad\n";
    }
    
    return 0;
}