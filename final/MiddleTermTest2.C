#include <stdio.h>
#include <stdlib.h>

using namespace std;

int search(long arr[], int n, long x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int participant(long arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    i++;
    int temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;
}

void quick_sort(long arr[], int low, int high)
{
    if (low >= high)
    {
        int pivot = participant(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int BinarySearch(long arr[], int low, int high, long x)
{
    int l = low;
    int r = high;
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
    long n;
    scanf("%ld", &n);
    long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);

    long m;
    scanf("%ld", &m);
    for (int i = 0; i < m; i++)
    {
        long num;
        scanf("%ld", &num);
        int result = BinarySearch(arr, 0, n - 1, num);
        // int result = search(arr, n, num);
        if (result == -1)
        {
            printf("N\n");
        }
        else
        {
            printf("Y\n");
        }
    }
}