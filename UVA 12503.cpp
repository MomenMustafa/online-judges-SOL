#include <iostream>
#include <vector>
#include <string>

using namespace std;
// UVA12503
// The problem is about simulating a robot's movement based on given commands.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); // Ignore the newline character after reading n
        int arr[100] = {0}, p = 0;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin>>s;

            if(s == "LEFT")
                arr[i] = -1;
            else if(s == "RIGHT")
                arr[i] = 1;
            else
            {
                int idx;
                scanf(" AS %d", &idx);
                arr[i] = arr[idx-1];
            }
            p += arr[i];
        }
        printf("%d\n", p);
    }

    return 0;
}