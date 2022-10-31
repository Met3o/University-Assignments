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
};*/

class birthdayCake : public cake {
	public:
		string icingColour = "Silver Blue";
		bool hasFondant = true;
		int printIcing();
};

#include "15Cake Header.hpp"
#include <string>
#include <iostream>
using namespace std;

cake::cake() {
	onPlate = true; //Of course, the plate is going to have cake on it.
	numOfSlices = 9;
}
cake::~cake() {
	//Cannot have a cake on a plate if there is no cake at all
	onPlate = false;
	//No cake? No slices!
	numOfSlices = 0;
}
int cake::getNumOfSlices() {
	return cake::numOfSlices;
}
int cake::cakeEat(int sliceCount) {
	int c = sliceCount;
	int n = cake::getNumOfSlices();
	if (n >= c) {
		cake::numOfSlices -= c;
		cout << "\nAte " << sliceCount << " slice(s) of cake. Yum!\n";
	}
	else {
		cout << "\nSorry, cannot eat " << c << " slices of cake!"
			"there are only " << n << " slices of cake left!\n";
	}
	return 0;
}

int birthdayCake::printIcing() {
	birthdayCake::icingColour = 7;
	string icingType = "Fondant";
	cout << "Icing type is: " << icingType << " with: " << birthdayCake::icingColour << " coloured icing.";
	return 0;
}

float grandBirthdayCake::printVolume() {
	const float pi = 3.14159;
	cout << "What is the radius of your cake?:\t";
	cin >> grandBirthdayCake::cakeRadius;
	cout << "What is the height of your cake?:\t";
	cin >> grandBirthdayCake::cakeHeight;
	cout << "So, what's the celebratory occasion for this cake? :):\t";
	cin >> grandBirthdayCake::celebrationOccasion;
	float printVolume();
};
int main() {
	birthdayCake birthday;
	birthday.printIcing();
	grandBirthdayCake fiftyCake;
}

//NOTE: This should have worked at some point but didn't, because Visual studio eventually started bugging and failing to update after coding errors were removed.
