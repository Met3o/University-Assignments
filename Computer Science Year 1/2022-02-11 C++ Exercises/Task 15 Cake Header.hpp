#pragma once
#include <iostream>
#include <string>
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

//16Inheritance
class birthdayCake : public cake {
	public:
		int icingColour;
		int printIcing();
};

//17Multilevel Inheritance Generations
class grandBirthdayCake : public birthdayCake {
	public:
		const float pi = 3.14159;
		int cakeRadius;
		int cakeHeight;
		int numOfDecorations;
		string celebrationOccasion;
		float printVolume();
};
