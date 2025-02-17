#include <stdio.h>
#include <stdlib.h>

using namespace std;

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
            l = mid + 1;
        }
        else if (arr[mid] < x)
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
}