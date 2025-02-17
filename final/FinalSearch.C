#include <stdio.h>
#include <stdlib.h>

using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

int binary_search(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = binary_search(arr, 0, n - 1, x);
    if (result != -1)
    {
        result++;
    }
    printf("%d", result);
}