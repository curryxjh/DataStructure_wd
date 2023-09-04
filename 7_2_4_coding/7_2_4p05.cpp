#include <iostream>
int a[10] = {0, 1, 2, 4, 6, 7, 10, 12, 23, 55};
int halfSearch(int arr[], int key, int low, int high);

int main()
{
    int ln = 10;
    std::cout << halfSearch(a, 6, 1, ln) <<std::endl;
    return 0;
}

int halfSearch(int arr[], int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (key > arr[mid])
        halfSearch(arr, key, mid + 1, high);
    else if (key < arr[mid])
        halfSearch(arr, key, low, mid - 1);
    else
        return mid;
}