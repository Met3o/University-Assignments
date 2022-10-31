#include <iostream>
using namespace std;
class powerUp {
	public:
		string name;
	private:
		string powers;
};

int main() {
	powerUp Max;
	powerUp Meteo;

	Max.name = "Mega Mushroom";
	Meteo.name = "Super Mushroom";
	//Meteo.powers = "Expand & Dash!"; // Error
	//Error	C2248	'powerUp::powers': 
	//cannot access private member declared in class 'powerUp'	
	return 0;
}
