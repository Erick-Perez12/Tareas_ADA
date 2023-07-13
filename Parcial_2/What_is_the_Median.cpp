#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void media(std::vector<int> arr, int tam) {
    int mid = 0 + (tam - 0) / 2;
    if (tam % 2 == 0) {
        std::cout << arr[mid] << "\n";
    }
    else {
        int aux = (arr[mid] + arr[mid + 1]) / 2;
        std::cout << aux << "\n";
    }
}

void mostrar(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void fun(std::vector<int>& arreglo) {
    int tam = arreglo.size() - 1;
    mergeSort(arreglo, 0, tam);
    media(arreglo, tam);
}

int main() {
    std::vector<int> arreglo;
    std::cout << "MEDIA: \n";
    arreglo.push_back(1);
    fun(arreglo);
    arreglo.push_back(3);
    fun(arreglo);
    arreglo.push_back(4);
    fun(arreglo);
    arreglo.push_back(60);
    fun(arreglo);
    arreglo.push_back(70);
    fun(arreglo);
    arreglo.push_back(50);
    fun(arreglo);
    arreglo.push_back(2);
    fun(arreglo);
}
