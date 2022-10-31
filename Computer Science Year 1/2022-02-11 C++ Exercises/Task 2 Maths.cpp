#include <iostream>
using namespace std;
int maths() {
    cout << "Hello World!\n";
    int a, b;
    int sum;
    int difference;
    float modulo;
    float div;
    int product;
    int largest;
    string largestName;
    cout << "Enter a number please:\t";
    cin >> a;
    cout << "Pease enter another number:\t";
    cin >> b;
    if (a >= b) {
        largest = a;
        largestName = "a";
    }
    else {
        largest = b;
        largestName = "b";
    }
    sum = a + b;
    difference = a - b;
    modulo = a % b;
    div = a / b;
    product = a * b;
    cout << "The sum of a + b:\t" << sum << endl;
    cout << "The difference of a - b:\t" << difference << endl;
    cout << "The modulo of a % b:\t" << modulo << endl;
    cout << "The division of a / b:\t" << div << endl;
    cout << "The product of a * b:\t" << sum << endl;
    cout << "The larger of a & b:\t" << largestName << ", which is: " << largest << endl;
}
