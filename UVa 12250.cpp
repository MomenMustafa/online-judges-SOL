#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("output.txt","w",stdout);
    string s;
    map<string, string>m;
    m["HELLO"]="ENGLISH";
    m["HOLA"]="SPANISH";
    m["HALLO"]="GERMAN";
    m["BONJOUR"]="FRENCH";
    m["CIAO"]="ITALIAN";
    m["ZDRAVSTVUJTE"]="RUSSIAN";
    
    int line =1;
    while (cin>>s)
    {
        if(s=="#") break;
        if(line!= 1)puts("");
        if(m.find(s)!=m.end())
            cout<<"Case "<<line<<": "<<m[s];
        else cout<<"Case "<<line<<": "<<"UNKNOWN";

        line++;
    }
    
    return 0;
}