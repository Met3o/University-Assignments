#include <iostream>
using namespace std;
#include <fstream>
#include <string>
//ofstream: create; write;
//ifstream: read;
//fstream: create; read; write;
//Will open text file in the same directory as this solution container, NOT the subfolder here where this program/other cpp programs are

int main() {
	//Write to the text file
	ofstream writeText("testText.txt");
	writeText << "Test Line 1";
	writeText.close();

	//String for outputting the read text
	string read;

	//Reading this text file into the 'read' string and printing it out
	ifstream readText("testText.txt");
	while (getline(readText, read)) {
		cout << read;
	}

	//Close it
	readText.close();
}
