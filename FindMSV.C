#include <stdlib.h>
#include <stdio.h>

using namespace std;

int search(long arr[], int n, long x)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            index = i;
            return index;
        }
    }
    return index;
}

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

int main()
{
    long n, m;

    scanf("%ld %ld", &n, &m);
    long arr1[n];
    long arr2[n];
    long arr3[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &arr1[i], &arr2[i]);
        arr3[i] = arr2[i];
    }

    Quick_sort(arr3, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        long msv;
        scanf("%ld", &msv);
        int index = search(arr1, n, msv);
        if (index == -1)
        {
            printf("-1 ");
        }
        else
        {
            int index2 = search(arr3, n, arr2[index]);

            printf("%ld ", index2 + 1);
        }
    }
}