#include <iostream>
using namespace std;
int boxVolume(int length, int width = 3, int height = 2);
int main() {
	int first = 3;
	int second = 5;
	int third = 4;
	cout << boxVolume(first) << endl;
	cout << boxVolume(second) << endl;
	cout << boxVolume(third) << endl;
	return 0;
}

int boxVolume(int length, int width, int height) {
	return (length * width * height);
}
