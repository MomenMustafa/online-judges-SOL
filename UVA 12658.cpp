#include<bits/stdc++.h>
using namespace std;


// UVA 12658
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){

    
    char character[5][4*n+1];

    for (int  i = 0; i < 5; i++)
        cin >> character[i];
        

        char one[5][3] = {
        {'.', '*', '.'},
        {'.', '*', '.'},
        {'.', '*', '.'},
        {'.', '*', '.'},
        {'.', '*', '.'}
        };

        char two[5][3] = {
        {'*', '*', '*'},
        {'.', '.', '*'},
        {'*', '*', '*'},
        {'*', '.', '.'},
        {'*', '*', '*'}
        };

        char three[5][3] = {
        {'*', '*', '*'},
        {'.', '.', '*'},
        {'*', '*', '*'},
        {'.', '.', '*'},
        {'*', '*', '*'}
        };
        
        for (int k = 0; k < n; k++)
        {
            bool oneflag = true;
            bool twoflag = true;
            bool threeflag = true;
            for (int i = 0; i < 5; i++)
            {
                for (int j = k*4; j < k*4+3; j++)
                {
                    if (character[i][j] != one[i][j-k*4])
                        oneflag = false;
                    if (character[i][j] != two[i][j-k*4])
                        twoflag = false;
                    if (character[i][j] != three[i][j-k*4])
                        threeflag = false;
                }
            }
            if (oneflag)
            {
                cout << "1";
            }
            else if (twoflag)
            {
                cout << "2";
            }
            else if (threeflag)
            {
                cout << "3";
            }
        }
        puts("");
    }
        return 0;
}

/*

 .*..***.***.
 .*....*...*.
 .*..***.***.
 .*..*.....*.
 .*..***.***.

.*...*..***.***.
.*...*....*...*.
.*...*..***.***.
.*...*....*.*...
.*...*..***.***.
*/