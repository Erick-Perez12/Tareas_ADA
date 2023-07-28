#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

void knapsackCombinatorialTreeDFS(const vector<Item>& items, int index, int capacity, int currentWeight, int currentValue, int& bestValue) {
    if (index >= items.size() || currentWeight > capacity) {
        return;
    }

    knapsackCombinatorialTreeDFS(items, index + 1, capacity, currentWeight, currentValue, bestValue);

    if (currentWeight + items[index].weight <= capacity) {
        knapsackCombinatorialTreeDFS(items, index + 1, capacity, currentWeight + items[index].weight, currentValue + items[index].value, bestValue);
    }

    bestValue = max(bestValue, currentValue);
}

int knapsackCombinatorialTree(const vector<Item>& items, int capacity) {
    int bestValue = 0;
    knapsackCombinatorialTreeDFS(items, 0, capacity, 0, 0, bestValue);
    return bestValue;
}

int main() {
    int capacity = 10; 
    vector<Item> items = { {2, 3}, {3, 7}, {4, 2}, {5, 9} }; 

    int maxValue = knapsackCombinatorialTree(items, capacity);
    cout << "Valor total en la mochila: " << maxValue << endl;

    return 0;
}
