#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        arr[num] = arr[num] + 1;
    }

    for (int i = 0; i < 100; i++)
    {

        printf("%d ", arr[i]);
    }
}