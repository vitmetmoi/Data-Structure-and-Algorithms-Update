#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a, b;
    scanf("%d %d", &a, &b);
    long long result1 = (a + b) * 2;
    long long result2 = a * b;

    printf("%lli %lli", result1, result2);
}