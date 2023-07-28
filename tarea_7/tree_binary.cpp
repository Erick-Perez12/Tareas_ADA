#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

struct Node {
    Item item;
    Node* left;
    Node* right;

    Node(const Item& item) : item(item), left(nullptr), right(nullptr) {}
};

Node* createBinaryTree(vector<Item>& items, int index) {
    if (index >= items.size()) {
        return nullptr;
    }

    Node* newNode = new Node(items[index]);
    newNode->left = createBinaryTree(items, 2 * index + 1);
    newNode->right = createBinaryTree(items, 2 * index + 2);

    return newNode;
}

void knapsackBinaryTreeDFS(Node* node, int capacity, int& bestValue) {
    if (node == nullptr) {
        return;
    }
    knapsackBinaryTreeDFS(node->left, capacity, bestValue);
    knapsackBinaryTreeDFS(node->right, capacity, bestValue);

    if (node->item.weight <= capacity) {
        int valueWithoutCurrent = 0;
        knapsackBinaryTreeDFS(node->left, capacity - node->item.weight, valueWithoutCurrent);
        knapsackBinaryTreeDFS(node->right, capacity - node->item.weight, valueWithoutCurrent);

        int totalValue = node->item.value + valueWithoutCurrent;
        if (totalValue > bestValue) {
            bestValue = totalValue;
        }
    }
}

int knapsackBinaryTree(vector<Item>& items, int capacity) {
    Node* root = createBinaryTree(items, 0);
    int bestValue = 0;
    knapsackBinaryTreeDFS(root, capacity, bestValue);
    return bestValue;
}

int main() {
    int capacity = 10; 
    vector<Item> items = { {2, 3}, {3, 7}, {4, 2}, {5, 9} }; 

    int maxValue = knapsackBinaryTree(items, capacity);
    cout << "Valor total en la mochila: " << maxValue << endl;

    return 0;
}

