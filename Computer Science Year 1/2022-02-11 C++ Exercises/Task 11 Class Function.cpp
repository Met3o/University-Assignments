#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;
class car {
public:
	string model;
	string brand;
	string numPlate;
	string colour;
	int mileage;
	int speed(int maxSpeed);
};

int car::speed(int maxSpeed) {
	return maxSpeed;
}

int main() {
	car* thatCar;
	thatCar = new car(); // instantiating a new car using new operator
	string colour;
	cout << "What colour is thatCar?:\t";
	cin >> colour;
	thatCar->colour = (colour);
	cout << "thatCar color is : " << thatCar->colour << endl;
	delete thatCar; //freeing car
	car Car2;
	string brand;
	int speed;
	cout << "What is the brand of the car?:\t";
	cin >> brand;
	cout << "How fast can it go?:\t";
	cin.ignore();
	if (typeid(speed).name() == "int") {
		cin >> speed;
	}
	else {
		while (typeid(speed).name() != "int") {
			cout << "Please enter a WHOLE NUMBER for speed:\t";
			cin.ignore();
			if (typeid(speed).name() == "int") {
				break;
			}
		}
		

		cout << "How fast can it go? Whole numbers only:\t";
		cin.ignore();
		cin >> speed;
	}
	Car2.brand = brand;
	cout << "\nHere is another car. Its brand is a " << Car2.brand << ", whose "
		"maximum speed is " << Car2.speed(speed) << " miles per hour! \nWOW! 😱" << endl;
	return 0;
};
