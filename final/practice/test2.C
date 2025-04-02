#include <stdio.h>
#include <stdlib.h>

using namespace std;

int participant(long arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            long tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    i++;
    long tmp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = tmp;
    return i;
}

void quick_sort(long arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = participant(arr, low, high);
        quick_sort(arr, pivot + 1, high);
        quick_sort(arr, low, pivot - 1);
    }
}

int binary_search(long arr[], int low, int high, long target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] == target)
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    long arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%ld ", arr[i]);
    // }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        long num;
        scanf("%ld", &num);
        int result = binary_search(arr, 0, n - 1, num);
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