#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int cases=1;
    while (cin>>n && n)
    {
        int nonZero = 0, zero = 0, num;

        for(int i =0; i <n;i++)
            {
                cin>>num;
                (num == 0)? zero++ : nonZero++;
            }

            cout<<"Case "<<cases++<<": "<<nonZero-zero<<endl;
    }
    

    return 0;
}