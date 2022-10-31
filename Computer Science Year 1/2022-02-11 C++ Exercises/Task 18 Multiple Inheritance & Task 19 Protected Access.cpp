#include <iostream>
using namespace std;

//Parent Class 1
class MotorizedVehicle {
	public:
	void autos() {
		cout << "\nMotorized Vehicle: It has two wheels but auto... ";
	}
	void info() {
		cout << "\nIt is motorised!";
	}
	protected: 
	void printProtect() {
		string yesno;
		cout << "\nI'm under protection! Cool!\nAre you under protection?:\t";
		cin >> yesno;
		if (yesno == "yes") {
			cout << "\nGreat!";
		}
		else {
			cout << "\nOh rip.";
		}
	}
};

//Parent Class 2
class NonMotorizedVehicle {
	public:
		void handles() {
			cout << "\nNon Motorized Vehicle: It has two handles, ";
		}
		void printType() {
			cout << "\nNon motorised!";
		}
};

//Derived/child class
class TwoWheels : public MotorizedVehicle, public NonMotorizedVehicle {
public:
	// Also has its own functions
	void twoWheeler() {
		cout << "\nTHIS IS A TWO WHEELER!";
		TwoWheels::printProtect();
	}
};

int main() {
	TwoWheels Tw;
	Tw.handles();
	Tw.autos();
	Tw.printType();
	Tw.info();
	Tw.twoWheeler();
	//Tw.printProtect() //Error.
	return 0;
}
