#include <iostream>
using namespace std;

void swap(int& first, int& second) {
	int temp;
	temp = first;
	first = second;
	second = temp;
	cout << "\nSwapped the two numbers around in memory!\n";
}

void showNums(int x, int y) {
	int n = x;
	int o = y;
	cout << "\nFirst number:\t" << n << "\n";
	cout << "Second number:\t" << o << "\n";
}
int main() {
	int a, b;
	cout << "\nPlease enter a number:\t\n";
	cin >> a;
	cout << "\nPlease enter another number:\t\n";
	cin >> b;
	showNums(a, b);
	swap(a, b);
	showNums(a, b);
}
