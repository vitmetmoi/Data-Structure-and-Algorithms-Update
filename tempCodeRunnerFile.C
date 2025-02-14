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