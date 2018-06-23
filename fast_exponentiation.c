#include<stdio.h>
#define ll long long
#define MOD 10000007

ll fast_exp(int base, int exponent)
{
    ll res = 1;
    while(exponent > 0)
    {
        if(exponent & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return res;
}

int main()
{
    int base, exponent;
    printf("\nEnter the base and the exponent : ");
    scanf("%i %i", &base, &exponent);
    printf("%i ^ %i = %lld\n\n", base, exponent, fast_exp(base, exponent));
    return 0;
}