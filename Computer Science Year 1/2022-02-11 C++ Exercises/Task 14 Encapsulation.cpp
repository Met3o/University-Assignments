#include <iostream>
using namespace std;

class student {
	public:
		string name;
	private:
		string behaviourRecord;
	public:
		void setBehaviour(string behaviour) {
			behaviourRecord = behaviour;
		}
		string printName() {
			return name;
		}
		string printBehaviour() {
			return behaviourRecord;
		}
};

int main() {
	student Kyle;
	Kyle.name = "Kyle";
	Kyle.setBehaviour(" raided the head teacher's office last Tuesday");
	cout << Kyle.printName() << "" << Kyle.printBehaviour();
}
