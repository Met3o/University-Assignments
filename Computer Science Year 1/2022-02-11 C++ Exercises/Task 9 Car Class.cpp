#include <string>
#include <iostream>
using namespace std;
class car {
public:
	string model;
	string brand;
	string numPlate;
	string colour;
	int mileage;
};

void main() {
	car theCar;
	theCar.colour = "orange";
	theCar.mileage = 80085;
	theCar.brand = "Honda";
	theCar.numPlate = "ME7 30R";
	theCar.model = "Civic";
	cout << "\nMy car is a:\t" << theCar.brand << theCar.model << "\nMy car's colour is:\t" << theCar.colour << "\nMy car's number plate is:\t" << theCar.numPlate << " with mileage:\t" << theCar.mileage;
}
