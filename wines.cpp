#include <bits/stdc++.h>
using namespace std;

int N;     // number of wines
int pi[1001];     // prices of wines
int cache[1001][1001];     // storing the optimal profit to use it later for greater performance

// function to calculate profit
int profit(int beg, int end)
{
    // there are no more wines on the shelf
    if(beg > end)
        return 0;

    // if value is already present in the 2D array then just return that
    if(cache[beg][end] != -1)
        return cache[beg][end];

    // year is defined statically to reduce time complexity
    int year = N - (end - beg);

    // store and return the optimal value, recursively calculate the better answer
    return cache[beg][end] = max(profit(beg+1, end) + year*pi[beg], profit(beg, end-1) + year*pi[end]);
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << "\nEnter the number of bottles : ";
    cin >> N;

    cout << "Enter the prices of the wines on the shelf (left to right) : ";
    for(int i = 0; i < N; cin >> pi[i], ++i);

    cout << "The maximum profit you can get by selling the wines = " << profit(0, N-1) << "\n\n";
    return 0;
}