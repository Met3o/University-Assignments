#include <iostream>
#include <string>
using namespace std;

class Car {
	public:
		string colour;
		int returnSpeed(int speed) {
			return (speed);
		}
};

class Truck : public Car {
	public:
		string colour;
		int returnSpeed(int speed) {
			return (speed - 5);
		}
		void printName() {
			cout << "\nThis truck's name is Tay!\n";
		}
};

class Van : public Truck {
	public:
		string colour;
		int returnSpeed(int speed) {
			return (speed - 3);
		}
};

int main() {
	Car myCar;
	myCar.colour = "red";
	Truck myTruck;
	myTruck.colour = "white";
	Van myVan;
	myVan.colour = "red";
	cout << "Here is my truck! it is " << myTruck.colour << ", and drives at " << myTruck.returnSpeed(70) << " mph!";
	cout << "\nHere is my van! its name is " << myVan.colour << ", and drives at " << myVan.returnSpeed(70) << " mph!";
	myTruck.printName();
	cout << "\nHere is my car! it is " << myCar.colour << ", and drives at " << myCar.returnSpeed(70) << " mph!";
	return 0;
}
