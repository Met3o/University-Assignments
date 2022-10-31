#include <iostream>
using namespace std;

int main() {
	string nationalBird = "Nightingale";
	string& bird = nationalBird;
	cout << "\n" <<  & bird << "\n";
	string* ptr = &bird; // pointer variable ptr which stores the address of bird
	//It can get memory address of a variable
	cout << ptr; // Output the memory address of nationalBird with the pointer (00C9F704)
	//change the value of the pointer
	*ptr = "Toucan"; // change the value
	// output the new value of pointer toucan
	cout << *ptr << "\n";
	//output of new value of nationalBird
	cout << nationalBird << "\n"; //00AFFE2C
}
