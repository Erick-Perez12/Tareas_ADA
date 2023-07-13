#include <iostream>
#include <vector>

using namespace std;

void retirar(int test,vector<int>& res) {
    int tam;
    while (test--) {
        cout << "Tamaño: "; cin >> tam;
        vector<int> aux(tam);
        for (int i = 0; i < tam; i++) {
            cin >> aux[i];
        }
        if (tam <= 2) {
            res.push_back(tam);
        }
        else {
            int sum = aux[0];
            int count = 2;
            for (int i = 1; i < tam - 1; ++i){
                if (sum < aux[i] && sum + aux[i] < aux[i + 1]){
                    sum += aux[i];
                    ++count;
                }
            }
            res.push_back(count);
        }
    }
}

void mostrar(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
}

int main()
{
    vector<int>resultados;
    int t;
    cout << "INPUT \n";
    cout << "casos de prueba: "; cin >> t;
    retirar(t,resultados);
    cout << "OUTPUT \n";
    mostrar(resultados);
    return 0;
}
