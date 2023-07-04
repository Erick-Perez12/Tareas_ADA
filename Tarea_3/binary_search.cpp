#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int med = l + (r - l) / 2;
        if (arr[med] == x)
            return med;
        if (arr[med] > x)
            return binarySearch(arr, l, med - 1, x);
        return binarySearch(arr, med + 1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = { 3, 4, 9, 10, 11, 13, 14, 20, 31, 50};
    int x = 14;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        std::cout << "Elemento no encontrado";
    std::cout << "Elemento: "<<x<<" posicion: " << result;
    return 0;
}