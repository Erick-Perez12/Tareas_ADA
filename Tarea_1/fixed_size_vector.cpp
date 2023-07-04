#include <iostream>
using namespace std;
int gVect[100]; // Buffer to save the elements
int gnCount; // Counter to know the number of elements used

void Insert(int elem)
{
	if (gnCount < 100) // we can only insert if there is space
		gVect[gnCount++] = elem; // Insert the element at the end
}

int main() {
	Insert(3); Insert(1); Insert(5); Insert(8); Insert(11); Insert(15); Insert(19); Insert(21); Insert(2); Insert(4);
}