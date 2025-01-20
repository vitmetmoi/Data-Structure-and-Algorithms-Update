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
    for (long long i = n - 1; i >= 0; i--)
    {
        if (a[i] == x)
        {
            position = i + 1;
            break;
        }
    }
    printf("%lld", position);
}