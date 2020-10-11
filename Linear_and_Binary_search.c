/*Author:Alok Khulbay
Date:-17/08/2020
Purpose:-To self learn.
*/
#include <stdio.h>
int Linear_Search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i + 1;
        }
    }
    return -1;
}
int Binary_Search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    //Keep searching until low<=high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    //Unsorted array for Linear Search
    // int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54634, 56, 34};
    // int size = sizeof(arr) / sizeof(int);
    // int ele = 23;
    // int result = Linear_Search(arr, size, ele);
    // printf("The element %d was found at index %d\n", ele, result);
    // Sorted Array for Binary Search
    int arr[] = {1,3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 444;
    int searchindex = Binary_Search(arr, size, element);
    printf("The element %d was found at index %d\n", element, searchindex);
    return 0;
}
