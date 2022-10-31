#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//Function to take the user's input and normalise it to the same format; makes comparing "yes" and "no" answers easier
string lowerCase(string inp) {
	string data = inp;
	// convert string to back to lower case
	for_each(data.begin(), data.end(), [](char & c) {
		c = ::tolower(c);
	});
	return data; //or c
}

//This function is arbitrary and is only there for neatness. It prints a line separation.
int separate() {
	cout << "\n\n--------------------------------------------------------\n";
	return 0;
}

//Check if the user said yes or no
int validateYes(string word) {
	//A word has to be in the same format to make things easier as less permutations are needed.
	word = lowerCase(word);
	if (word == "yes" || word == "yeah" || word == "yep" || word == "yup") {
			return 1;
		}
	else {
			return 0;
	}
}

//Used for asking questions to the user
int ask(string input) {
	string inp = input;
	if (validateYes(inp) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

/* Building class (BASE CLASS)
* Subclass house, subclass Hall, subclass office, subclass warehouse
* Also a vehicle class with car, van, and truck
* And Caravan class inherits from Van and House!
*/
class Building {
	public:
		//Z axis length - how tall is the building?
		int height;
		//X axis length - how wide is the building when you look at it from the front?
		int width;
		//Y axis length - how far in does the building go? (WIdth from the side)
		int depth;
		//depth * width * height - volume of the building
		int volume;
		//Number of floors in the building
		int numOfFloors;
		//Not all buildings have a sloped roof, as well as caravans
		bool hasSlopedRoof = false;
		//You're not in it either, I assume.
		bool youAreInIt = false;
		//Constructor
		Building(int height, int width, int depth, int numOfFloors, bool hasSlopedRoof);
		//Destroyer
		~Building();

		//POLYMORPHISM1
		//Enter the building
		int askToEnter();

		//INHERITANCE1
		int Welcome(string buildingName);

		//INHERITANCE2
		int returnSize();

		//INHERITANCE3
		int exit(string buildingName);
};

//Vehicle class, which Caravan will inherit from
class Vehicle {
	int numOfWheels;
};

/*POLYMORPHISM1
* House, Office, and Halls are all buildings. But, they have different ways of letting you enter them!
* For a house, you ring the bell and hopefully a person will answer the door for you.
* For an Office, you just walk through the door during open hours.
* For Halls, you use your swipe card.
* These are all different ways of letting a person in, but they serve the same purpose!
*/
//House Subclass
class House : public Building {
	public:
		//Inherited Constructor
		House(int height, int width, int depth, int numOfFloors, bool hasSlopedRoof) : Building(height, width, depth, numOfFloors, hasSlopedRoof) {
			//Z axis length - how tall is the building?
			House::height = height;
			//X axis length - how wide is the building when you look at it from the front?
			House::width = width;
			//Y axis length - how far in does the building go? (WIdth from the side)
			House::depth = depth;
			//depth * width * height - volume of the building
			House::numOfFloors = numOfFloors;
			//Is the roof a sloped one?
			House::hasSlopedRoof = hasSlopedRoof;
		}
		//POLYMORPHISM1
		int askToEnter();
		//Are there people in here? If not then you cannot enter as nobody will be there to let you in. 
		//By default this is true to make things easier to understand.
		bool hasPeopleInIt = true;

		int exit(string buildingName);
};

//Office Subclass
class Office : public Building {
	public:
		//Inherited Constructor
		Office(int height, int width, int depth, int numOfFloors, bool hasSlopedRoof) : Building(height, width, depth, numOfFloors, hasSlopedRoof) {
			//Z axis length - how tall is the building?
			Office::height = height;
			//X axis length - how wide is the building when you look at it from the front?
			Office::width = width;
			//Y axis length - how far in does the building go? (WIdth from the side)
			Office::depth = depth;
			//depth * width * height - volume of the building
			Office::numOfFloors = numOfFloors;
			//Is the roof a sloped one?
			Office::hasSlopedRoof = hasSlopedRoof;
		}

		//POLYMORPHISM1
		int askToEnter();
		//Is it unlocked? If not then you cannot enter it.
		bool unlocked = true;
		//Do you have a valid worker ID? If not, then you do not have access.
		bool hasValidID = true;
};

//Halls Subclass
class Halls : public Building {
	public:
		//Inherited Constructor
		Halls(int height, int width, int depth, int numOfFloors, bool hasSlopedRoof) : Building(height, width, depth, numOfFloors, hasSlopedRoof) {
			//Z axis length - how tall is the building?
			Halls::height = height;
			//X axis length - how wide is the building when you look at it from the front?
			Halls::width = width;
			//Y axis length - how far in does the building go? (WIdth from the side)
			Halls::depth = depth;
			//depth * width * height - volume of the building
			Halls::numOfFloors = numOfFloors;
			//Is the roof a sloped one?
			Halls::hasSlopedRoof = hasSlopedRoof;
		}

		//POLYMORPHISM1
		int askToEnter();
		//Uni halls require you to have a swipe card to enter
		bool hasSwipeCard = true;
};

//Constructor function
Building::Building(int height, int width, int depth, int numOfFloors, bool hasSlopedRoof) {
	//Z axis length - how tall is the building?
	Building::height = height;
	//X axis length - how wide is the building when you look at it from the front?
	Building::width = width;
	//Y axis length - how far in does the building go? (WIdth from the side)
	Building::depth = depth;
	//depth * width * height - volume of the building
	Building::volume = height * depth * width;
	//Is the roof a sloped one?
	Building::hasSlopedRoof = hasSlopedRoof;
	Building::numOfFloors = numOfFloors;
}

//Destroyer function
Building::~Building() {
	Building::youAreInIt = false;
	Building::height = 0;
	Building::width = 0;
	Building::depth = 0;
	Building::volume = 0;
	Building::numOfFloors = 0;
	//cout << "\nThe building has been destroyed. CRASH!" << endl;
}


//POLYMORPHISM1
/* Here, the default declaration is declared for a generic building.
* For the subclasses, this function will be different; therefore polymorphic.
*/
int Building::askToEnter() {
	string input;
	cout << "Do you wish to enter? Please answer either 'yes' or 'no': ";
	cin >> input;
	if (validateYes(input) == 1) {
		cout << "Asking to enter...\n...";
		cout << "Entered the building. Welcome!";
	}
	else {
		cout << "No? Ok, bye then.";
	}
	return 0;
}

//POLYMORPHISM1: House, ring the bell! As opposed to the superclass, which gives a basic query.
int House::askToEnter() {
	string input;
	cout << "Do you wish to enter? Please answer either 'yes' or 'no': ";
	cin >> input;
	//If you DO want to enter AND there are people at home to open the door for you, you can get in. Otherwise, there is nobody to open the door for you :(
	cout << "\nRang the bell...\n...";
	if (validateYes(input) == 1) {
		if (House::hasPeopleInIt == 1) {
			cout << "You rang the bell, and somebody answered! Entered the building. Welcome!";
			//If you went into the house then you currently are inside the house. (Therefore you are also able to exit again)
			House::youAreInIt = true;
		}
		else {
			cout << "We rang, but nobody is at home! Sorry, there is no-one to let you in.";
		}
	}
	else {
		cout << "No? Ok, bye then.";
	}
	return 0;
}

//POLYMORPHISM1: Office, enter using your office ID to prove you work there.
int Office::askToEnter() {
	string input;
	cout << "Do you wish to enter this Office? Please answer either 'yes' or 'no': ";
	cin >> input;
	//If you DO want to enter AND you have the valid proof of employment at the office, you can enter. Otherwise, you cannot
	cout << "\nScanning your ID card...\n...";
	if (validateYes(input) == 1) {
		if (Office::hasValidID == 1) {
			cout << "You had a valid ID! So, you entered the Office. Welcome!";
			//If you went into the office then you currently are inside the office. (Therefore you are also able to exit again)
			Office::youAreInIt = true;
		}
		else {
			cout << "Sorry, but you do not have the valid ID to enter the Office.";
		}
	}
	else {
		cout << "No? Ok, bye then.";
	}
	return 0;
}

//POLYMORPHISM1: Halls, which require a swipe card as proof of residence.
int Halls::askToEnter() {
	string input;
	cout << "Do you wish to enter this Halls Block? Please answer either 'yes' or 'no': ";
	cin >> input;
	//If you DO want to enter AND you have the valid proof of residence, you can enter; otherwise, you cannot!
	cout << "\nScanning your residence swipe...\n...";
	if (validateYes(input) == 1) {
		if (Halls::hasSwipeCard == 1) {
			cout << "Entered the building. Welcome!";
			//If you went into the building then you currently are inside the building. (Therefore you are also able to exit again)
			Halls::youAreInIt = true;
		}
		else {
			cout << "Sorry, but you do not have the valid Halls Card to enter the place, so you probably don't live in this block.";
		}
	}
	else {
		cout << "No? Ok, bye then.";
	}
	return 0;
}

//INHERTANCE1
//Welcome to <buildingname>!
int Building::Welcome(string buildingName) {
	cout << "\nWelcome to " << (buildingName) << "!\n";
	return 0;
}

//INHERITANCE2
//Function for returning the size of the building
int Building::returnSize() {
	int width = Building::width;
	int height = Building::height;
	int depth = Building::depth;
	int volume = Building::volume;
	int numOfFloors = Building::numOfFloors;
	cout << "---DIMENSIONS---\n";
	cout << "Height per floor: " << height << endl;
	cout << "Full height: " << height * numOfFloors << endl;
	cout << "Width: " << width << endl;
	cout << "Depth: " << depth << endl;
	cout << "Volume of the building: " << volume << endl;
	return 0;
}

//MORE POLYMORHISM
//Exit the building
int Building::exit(string buildingName) {
	cout << "\nAsked to exit...\n...";
	if (Building::youAreInIt != false){
		cout << "\n--------\nExited the building called " << buildingName << ".\n--------\n";
	}
	else {
		cout << "\n--------\nERROR: You are not even inside " << buildingName << ". Can't exit if you aren't in there!\n--------\n";
	}
	return 0;
}

//POLYMORPHIC FOR HOUSE ONLY: ONLY PRINTS A DIFFERENT MESSAGE
int House::exit(string buildingName) {
	cout << "\nAsked to exit...\n...";
	if (House::youAreInIt != false) {
		cout << "\n--------\nExited the house called " << buildingName << ".\n--------\n";
	}
	else {
		cout << "\n--------\nERROR: You are not even inside the house called " << buildingName << ". Can't exit if you aren't in there!\n--------\n";
	}
	return 0;
}

//Multiple inheritance! A caravan can drive like a vehicle, but also has bathrooms, bedrooms and lounges & kitchens like a building!
class Caravan : public Vehicle, public House {
	public:
		int askToEnter();
};

/*INHERITANCE WITHOUT POLYMORPHISM
* You get a greeting when you enter the building, no matter which type of building it is! But the argument can vary.
* It can be "office" - 'Welcome to the office!' or house - 'Welcome to the house', and so on, but the format of the message is still the same,
* therefore the Welcome() function does NOT need to be polymorphic.
*/

int main(){
	//Base Class
	cout << "Here is the base class: Building number 1!" << endl;
	Building building1(3, 8, 7, 3, true);
	/*//Ask to exit building1, will return 'NO' as you are not even in the building!
	building1.exit("building number 1");
	*/
	building1.Welcome("building1");
	building1.askToEnter();

	//Separation line (neatness)
	separate();

	//House SubClass
	cout << "\n\nLet's build a house called house1.\n" << endl;
	House house1(3,10,6,3, true);
	//Ask to exit house1, will return 'NO' as you are not even in the building!
	//house1.exit("house1");
	house1.returnSize();
	house1.askToEnter();
	house1.Welcome("house1");
	//Ask to exit house1, will return SUCCESS as you are in the building and can therefore exit it!
	//Exit if you are in there
	if (house1.youAreInIt != false) {
		house1.exit("house1");
	}

	//Separation line (neatness)
	separate();

	//Office SubClass
	cout << "\n\nHere is an office called Office1.\n" << endl;
	Office office1(3,10,12,10, true);
	office1.askToEnter();
	//Exit if you are in there
	if (office1.youAreInIt != false) {
		office1.exit("office1");
	}

	//Separation line (neatness)
	separate();

	//Halls SubClass
	cout << "\n\nHere is a student halls building called Halls1.\n" << endl;
	Halls halls1(3, 10,30,4, true);
	halls1.exit("halls1");
	halls1.askToEnter();
	//Exit if you are in there
	if (halls1.youAreInIt != false) {
		halls1.exit("halls1");
	}

	//neatness
	separate();

	//House SubClass, but this will NOT let the user in as there is nobody at home!
	cout << "\n\nLet's build a house called house2.\n" << endl;
	House house2(3, 10, 6, 3, true);
	house2.hasPeopleInIt = false;
	house2.askToEnter();
	//Exit if you are in there
	if (house2.youAreInIt != false) {
		house2.exit("house2");
	}

	//neatness
	separate();

	//Office SubClass, but this will NOT let the user in as they do not have the appropriate ID.
	cout << "\n\nHere is an office called Office2.\n" << endl;
	Office office2(4, 12, 12, 3, false);
	office2.hasValidID = false;
	office2.askToEnter();
	//Exit if you are in there
	if (office2.youAreInIt != false) {
		office2.exit("office2");
	}

	//neatness
	separate();

	//Halls SubClass, but this will NOT let the user in as they do not have the appropriate proof of residence.
	cout << "\n\nHere is an block of halls called Halls2.\n" << endl;
	Halls halls2(4, 12, 12, 3, false);
	halls2.hasSwipeCard = false;
	halls2.askToEnter();
	//Attempt and fail to exit, as you are already outside the building
	if (halls2.youAreInIt != true) {
		halls2.exit("halls2");
	}

	//neatness
	separate();
	return 0; 
}
