#include <iostream>
using namespace std;

int* gpVect = NULL; // Dynamic buffer to save the elements
int gnCount = 0; // Counter to know the number of used elements
int gnMax = 0; // Variable containing the size of the allocated

void Resize(int*& rpVect, int& rnMax)
{
    const int delta = 10; // Used to increase the vector size
    int* newVect = new int[rnMax + delta]; // Allocate a new buffer with increased size

    // Copy the elements from the old buffer to the new buffer
    for (int i = 0; i < rnMax; i++) {
        newVect[i] = rpVect[i];
    }

    delete[] rpVect; // Deallocate the old buffer
    rpVect = newVect; // Point to the new buffer
    rnMax += delta; // The Max has to be increased by delta
}

void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem)
{
    if (rnCount == rnMax) // Verify the overflow
        Resize(rpVect, rnMax); // Resize the vector before inserting elem

    rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}

int main()
{
    Insert(gpVect, gnCount, gnMax, 3);
    Insert(gpVect, gnCount, gnMax, 1);
    Insert(gpVect, gnCount, gnMax, 5);
    Insert(gpVect, gnCount, gnMax, 8);
    Insert(gpVect, gnCount, gnMax, 11);
    Insert(gpVect, gnCount, gnMax, 15);
    Insert(gpVect, gnCount, gnMax, 19);
    Insert(gpVect, gnCount, gnMax, 21);
    Insert(gpVect, gnCount, gnMax, 2);
    Insert(gpVect, gnCount, gnMax, 4);

    for (int i = 0; i < gnCount; i++) {
        cout << gpVect[i] << " ";
    }

    delete[] gpVect; // Deallocate the dynamic buffer

    return 0;
}