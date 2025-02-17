#include <stdio.h>
#include <stdlib.h>

using namespace std;

int particiant(int arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;
    return i;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = particiant(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}