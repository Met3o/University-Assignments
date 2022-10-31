#include <iostream>
using namespace std;

int square(int value) {
	int x;
	x = value * value;
	cout << "\n Square int 2:\t\t" << x;
	return x;
}
float square(float value) {
	float y;
	y = value * value;
	cout << "\n Square float 1.5:\t" << y;
	return y;
}

int main() {
	float floaty;
	int inty;
	floaty = 1.5;
	inty = 2;
	square(floaty);
	square(inty);
}
