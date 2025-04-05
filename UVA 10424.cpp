#include <bits/stdc++.h>

using namespace std;

int convert(string s)
{
    int val = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //cout<<s[i]- 'a'<<' ';
        if(s[i]<='z'&&s[i]>='a') val += s[i]-'a'+1;
        else if(s[i]<='Z'&&s[i]>='A') val += s[i]-'A'+1;
    }
    return val;
}
int sumDigits(int num)
{
    int sum=0;
    do
    {
        sum = 0;
        while (num)
        {
            sum += num%10;
            num/=10;
        }
        num = sum;
    } while (sum>=10);
    return sum;
}
int main()
{
    //freopen("output.txt", "w", stdout);
    string a, b;
    while(getline(cin, a))
    {
        getline(cin, b);

        int n1, n2;
        n1 = convert(a);
        n2 = convert(b);
        n1 = sumDigits(n1), n2 = sumDigits(n2);
        //printf("%.2f %\n",100.0*min(n1, n2)/max(n1,n2));
        cout<<setprecision(2)<<setiosflags(ios_base::fixed)<< 100.0*min(n1, n2)/max(n1,n2)<<" %\n";
    }
    
    return 0;
}



