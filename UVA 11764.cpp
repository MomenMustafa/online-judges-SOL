#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int line =1;line<=t;line++)
    {
        int low, high;
        low = high = 0;

        int n;
        cin>> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        for (int i = 0; i < n-1; i++)
        {
            if(arr[i]>arr[i+1]) high++;
            else if(arr[i]<arr[i+1]) low++;
        }
        cout<<"Case "<<line<<": "<<low<<' '<<high<<endl;
    }
    
    return 0;
}