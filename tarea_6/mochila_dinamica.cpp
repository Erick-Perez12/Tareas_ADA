#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila(int M, vector<int>& peso, vector<int>& valor, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (peso[i - 1] <= j) {
                dp[i][j] = max(valor[i - 1] + dp[i - 1][j - peso[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][M];
}

int main() {
    int M, n;
    cout << "Capacidad de la mochila: "; cin >> M;
    cout << "Numero de elementos: "; cin >> n;
    vector<int> peso(n), valor(n);

    cout << "Peso y el valor de cada elemento:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> peso[i] >> valor[i];
    }

    int maxVal = mochila(M, peso, valor, n);
    cout << "El valor maximo es: " << maxVal << endl;

    return 0;
}
