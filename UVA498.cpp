#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fastPow(ll b, ll p)
{
    ll r=1;
    while(p)
    {
        if(p&1)
            r = r*b;

        b= b*b;
        p>>=1;
    }
    return r;
}


int main() {


	string coff, possibleX;

	while(getline(cin, coff) && getline(cin, possibleX))
    {
        stringstream Coff(coff), PossibleX(possibleX);
        vector<ll>coffs;
        ll theCoff;
        while(Coff >> theCoff)
            coffs.push_back(theCoff);
        ll order = coffs.size();

        vector<ll>matrix;
        ll x;
        while(PossibleX >> x)
        {
            ll result = 0;
            ll pw = 1;
            for(int i=coffs.size()-1;i>=0;i--)
               result+= pw*coffs[i], pw*=x;

            matrix.push_back(result);
        }

        for (int i = 0; i < matrix.size(); ++i) {
			if (i == 0)
				cout << matrix[0];
			else
				cout << " " << matrix[i];

		}

        puts("");
    }
return 0;
}
