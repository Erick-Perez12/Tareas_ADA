#include <iostream>
using namespace std;

int* gpVect = NULL; // Dynamic buffer to save the elements
int gnCount = 0; // Counter to know the number of used elements
int gnMax = 0; // Variable containing the size of the allocated

void resize()
{
    int newMax = (gnMax == 0) ? 1 : gnMax * 2;
    int* newVect = new int[newMax];
    for (int i = 0; i < gnCount; i++) {
        newVect[i] = gpVect[i];
    }
    delete[] gpVect;

    gpVect = newVect;
    gnMax = newMax;
}

void Insert(int elem)
{
    if (gnCount == gnMax) {
        resize();
    }

    gpVect[gnCount++] = elem;
}

int main()
{
    Insert(3); Insert(1); Insert(5); Insert(8); Insert(11); Insert(15); Insert(19); Insert(21); Insert(2); Insert(4);
    for (int i = 0; i < gnCount; i++) {
        cout << gpVect[i] << " ";
    }
    cout << endl;
    delete[] gpVect;

    return 0;
}