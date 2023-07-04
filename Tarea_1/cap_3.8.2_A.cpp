#include <iostream>

int Addition(float a, float b){
	return a + b;
}
int Subtraction(float a, float b) {
	return a - b;
}
int Multiplication(float a, float b) {
	return a * b;
}
int Division(float a, float b) {
	return a / b;
}

int main() {
	float a, b, c; int opt;
	std::cout << "enter the operands \n";
	std::cin >> a >> b;
	std::cout << "OPT-> 0 - Addition, 1 - Subtraction, 3 - Multiplication, 4 - Division \n";
	std::cin >> opt;
	switch (opt)
	{
	case 0: c = Addition(a, b); break;
	case 1: c = Subtraction(a, b); break;
	case 2: c = Multiplication(a, b); break;
	case 3: c = Division(a, b); break;
		// more cases operations go here
	}
	std::cout << "resultado: " << c;
}