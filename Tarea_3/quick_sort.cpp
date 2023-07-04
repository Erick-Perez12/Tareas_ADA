#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printVector(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = { 10, 7, 8, 9, 1, 5 };
    int size = arr.size();
    std::cout << "Vector original: ";
    printVector(arr);
    quickSort(arr, 0, size - 1);
    std::cout << "Vector ordenado: ";
    printVector(arr);

    return 0;
}