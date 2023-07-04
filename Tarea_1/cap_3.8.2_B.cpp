#include <iostream>
float Addition(float a, float b) {
	return a + b;
}
float Subtraction(float a, float b) {
	return a - b;
}
float Multiplication(float a, float b) {
	return a * b;
}
float Division(float a, float b) {
	return a / b;
}

typedef float (*lpfnOperation)(float, float);
lpfnOperation vpf[4] = { &::Addition, &::Subtraction,
&::Multiplication, &::Division };

int main() {
	float a, b, c; int opt;
	std::cout << "enter the operands \n";
	std::cin >> a >> b;
	std::cout << "OPT-> 0 - Addition, 1 - Subtraction, 3 - Multiplication, 4 - Division \n";
	std::cin >> opt;
	c = (*vpf[opt])(a, b);
	std::cout << "resultado: " << c;
}