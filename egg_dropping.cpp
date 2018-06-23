# include <bits/stdc++.h>
# include <stdio.h>
# include <limits.h>
using namespace std;
 
/* Function to get minimum number of trials needed in worst
  case with n eggs and k floors (worst case scenario).*/
int eggDrop(int eggs, int floors)
{
    /* A 2D table where entery eggFloor[eggs][floors] will represent minimum
       number of trials needed for e eggs and f floors (worst case scenario). */
    int eggFloor[eggs+1][floors+1];
    int res;
 
    // ** NOTE : We need one trial for one floor and 0 trials for 0 floors
    for (int e = 1; e <= eggs; e++)
    {
        eggFloor[e][1] = 1;
        eggFloor[e][0] = 0;
    }
 
    // ** NOTE : We always need j trials for one egg and j floors.
    for (int f = 1; f <= floors; f++)
        eggFloor[1][f] = f;
 
    // Fill rest of the entries in table using optimal substructure property
    for (int e = 2; e <= eggs; e++)
    {
        for (int f = 2; f <= floors; f++)
        {
            eggFloor[e][f] = INT_MAX;
            for (int k = 1; k <= f; k++)
            {
                res = 1 + max(eggFloor[e-1][k-1], eggFloor[e][f-k]);
                if (res < eggFloor[e][f])
                    eggFloor[e][f] = res;
            }
        }
    }
 
    // eggFloor[n][k] holds the result
    return eggFloor[eggs][floors];
}
 
int main()
{   
    int e, f;
    cout << "\nEnter the number of eggs : ";
    cin >> e;
    cout << "Enter the number of floors : ";
    cin >> f;
    printf ("The Minimum number of trials in worst case with %d eggs and %d floors is %d\n", e, f, eggDrop(e, f));
    return 0;
}
