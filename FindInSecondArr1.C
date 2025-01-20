#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long n2;
    scanf("%lld", &n2);
    long long b[n2];

    for (long long i = 0; i < n2; i++)
    {
        scanf("%lld", &b[i]);
    }
    for (long long i = 0; i < n2; i++)
    {
        char result = 'N';
        for (long long j = 0; j < n; j++)
        {

            if (b[i] == a[j])
            {
                result = 'Y';
            }
        }
        printf("%c\n", result);
    }
}