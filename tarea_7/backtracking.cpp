#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int peso;
    int valor;
};

void knapsackBacktracking(vector<Item>& items, int capacity, vector<int>& solution, vector<int>& bestSolution, int& bestValue, int index) {
    if (index >= items.size() || capacity == 0) {
        int totalValue = 0;
        for (int i = 0; i < items.size(); ++i) {
            totalValue += solution[i] * items[i].valor;
        }

        if (totalValue > bestValue) {
            bestValue = totalValue;
            bestSolution = solution;
        }
        return;
    }

    knapsackBacktracking(items, capacity, solution, bestSolution, bestValue, index + 1);
    if (items[index].peso <= capacity) {
        solution[index] = 1;
        knapsackBacktracking(items, capacity - items[index].peso, solution, bestSolution, bestValue, index + 1);
        solution[index] = 0; 
    }
}

int main() {
    int capacity = 10; 
    vector<Item> items = { {2, 3}, {3, 7}, {4, 2}, {5, 9} }; 

    vector<int> solution(items.size(), 0);
    vector<int> bestSolution(items.size(), 0);
    int bestValue = 0;

    knapsackBacktracking(items, capacity, solution, bestSolution, bestValue, 0);

    cout << "capacidad: 10 \nitems con su peso: {2, 3}, {3, 7}, {4, 2}, {5, 9} \n";
    cout << "Elementos seleccionados en la mochila:" << endl;
    for (int i = 0; i < items.size(); ++i) {
        if (bestSolution[i] == 1) {
            cout << "Peso: " << items[i].peso << ", Valor: " << items[i].valor << endl;
        }
    }

    cout << "Valor total en la mochila: " << bestValue << endl;

    return 0;
}
