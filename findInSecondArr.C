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
    char result = 'N';
    for (long long i = 0; i < n2; i++)
    {
        long long num;
        scanf("%lld", &num);
        result = 'N';
        for (long long j = 0; j < n; j++)
        {

            if (num == a[j])
            {
                result = 'Y';
            }
        }
        printf("%c\n", result);
    }
}