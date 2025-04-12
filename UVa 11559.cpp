#include<bits/stdc++.h>
using namespace std;

// UVA 11559 - Event Planning
int main()
{
   // freopen("output.txt", "w", stdout); // Redirect output to file
    //freopen("input.txt", "r", stdin); // Redirect input from file
    int participants, budget, hotels, weeks;
    while(scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) != EOF)
    {

        int minCost = INT_MAX;
        while (hotels--)
        {
            int costPerPerson;
            scanf("%d", &costPerPerson);
            for (int i = 0; i < weeks; i++)
            {
                int availableBeds;
                scanf("%d", &availableBeds);
                if (availableBeds >= participants)
                {

                    minCost = min(minCost, costPerPerson * participants);
                    string s;
                    getline(cin, s); // Read the rest of the line to clear the input buffer
                    //cin.ignore();
                    break;
                }
            }
        }
        
        if (minCost == INT_MAX || minCost > budget) // If no valid hotel was found
            printf("stay home\n");
        else
            printf("%d\n", minCost); // Print the minimum cost found
    }


    return 0;
}