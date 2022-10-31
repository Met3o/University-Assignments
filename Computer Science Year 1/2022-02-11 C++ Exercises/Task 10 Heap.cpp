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

int car::setColour(car::colour, string colourSet) {
	car.colour = colourSet;
	return 0;
}
// This piece of code is now INVALID 😇

int main() {
	car* thatCar;
	thatCar = new car(); // instantiating a new car using new operator
	thatCar->colour=("blue");
	cout << "thatCar color is : " << thatCar->colour << endl;
	delete thatCar; //freeing car
	return 0;
};
