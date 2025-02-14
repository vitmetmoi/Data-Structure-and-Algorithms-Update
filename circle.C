#include <stdlib.h>
#include <stdio.h>

using namespace std;

int particition(long arr[], int low, int high)
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
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;
}

void Quick_sort(long arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = particition(arr, low, high);
        Quick_sort(arr, low, pivot - 1);
        Quick_sort(arr, pivot + 1, high);
    }
}

int BinarySearch(long arr[], int low, int high, long x)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else
        {
            BinarySearch(arr, low, mid - 1, x);
            BinarySearch(arr, mid + 1, high, x);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    long n, m;

    scanf("%ld %ld", &n, &m);
    long arr1[n];
    long arr2[n];
    long arr3[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &arr1[i], &arr2[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%ld", &arr3[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%ld ", &arr3[i]);
    // }

    Quick_sort(arr1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int o = BinarySearch(arr1, 0, n - 1, arr3[i]);
        if (o == -1)
        {
            printf("-1 ");
        }
        else
        {
            printf("%ld ", arr1[o]);
        }
    }
}