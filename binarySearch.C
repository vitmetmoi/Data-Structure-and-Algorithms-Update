#include <stdio.h>
#include <stdlib.h>

using namespace std;

int binarySearch(long long arr[], int l, int r, int x)
{
    int left = l;
    int right = r;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {

            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

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
    int result = binarySearch(a, 0, n - 1, x);
    printf("%d", result + 1);
}