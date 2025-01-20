#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    long long n;
    long long x;
    scanf("%lld %lld", &n, &x);
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long position = -1;
    long long temp = a[0];
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > temp && a[i] < x)
        {
            position = i + 1;
            temp = a[i];
        }
    }
    printf("%lld", position);
}