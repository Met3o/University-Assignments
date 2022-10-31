//Declaring a class can kept in a header file that can be called in main file, advantage is that you can use this header fill overand overand again without changing
//Define a class with constructorand destructor
//With the cake example, you can see the header file with declaring the class, defining a cake with a class by using constructorand destructor
//Use cake as a classand print then use eating the cake
//Create a second cake
//Change the Cake constructor to allow setting the number of slices using a default of eight, if not provided

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
int recursiveMenu() {
	cake Cake1;
	int numChoice;
	cout << "Here is some cake with 9 slices!";
	cout << "\nChoose how many slices you want to eat:\t";
	cin.ignore();
	cin >> numChoice;
	if (Cake1.cakeEat(1)); //Eating cake!
	if (Cake1.cakeEat(5)); //Eating more cake!
	cake Cake2;
	return 0;
}

int main() {
	recursiveMenu();
}
