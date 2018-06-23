#include<bits/stdc++.h>
using namespace std;

vector<bool> primes(100001,true);

void setPrimes()
{
    for(int i = 2; i*i < 100001; ++i)
    {
        if(primes[i] == true)
        {
            for(int j = i*2; j < 100001; j += i)
                primes[j] = false;
        }
    }
}

int main()
{
    setPrimes();
    int n;
    cout << "Enter the number upto which you want to print the prime numbers : ";
    cin >> n;
    for(int i = 2; i <= n; ++i)
        if(primes[i] == true)
            cout << i << " , ";
    return 0;
}