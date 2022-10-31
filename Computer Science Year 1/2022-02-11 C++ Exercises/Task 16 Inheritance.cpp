 //NOTE: This file relies on '15Cake Classes.cpp' being ENABLED
#include <iostream>
using namespace std;
#include "15Cake Header.hpp"

//Parent class is cake
#pragma once
class cake {
public:
	//Constructor
	cake();
	//Destroy
	~cake();
	//Eat 😋
	int cakeEat(int sliceCount);
	//Return number of slices
	int getNumOfSlices();
	int numOfSlices;
	bool onPlate;
private:
	int numOfIngredients;
};

class birthdayCake : public cake {
	public:
		string icingColour = "Silver Blue";
		int printIcing();
};


int birthdayCake::printIcing() {
	birthdayCake::icingColour = 7;
	string icingType = "Fondant";
	cout << "Icing type is: " << icingType << " with: " << birthdayCake::icingColour << " coloured icing.";
	return 0;
}

int main() {
	birthdayCake birthday;
	birthday.printIcing();
}
