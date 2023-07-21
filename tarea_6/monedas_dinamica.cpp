#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& moneda, int cant) {
    vector<int> dp(cant + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cant; i++) {
        for (int coin : moneda) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[cant] == INT_MAX) ? -1 : dp[cant];
}

int main() {
    int cant, n;
    cout << "Valor objetivo: "; cin >> cant;
    cout << "Numero de monedas disponibles: "; cin >> n;
    vector<int> moneda(n);
    cout << "Valores de las monedas:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> moneda[i];
    }

    int minCoins = coinChange(moneda, cant);
    cout << "Monedas minimas es: " << minCoins << endl;

    return 0;
}
