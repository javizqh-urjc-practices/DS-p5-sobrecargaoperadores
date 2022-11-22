/* main.cpp
Practical exercise 5.
Coleccion class test program.
*/
#include <iostream>
#include "Coleccion.h"

using namespace std;

int main() {
	Coleccion integers1 (7); // seven-element Coleccion
	Coleccion integers2; // 10-element Coleccion by default

	// print integers1 size and contents
	cout << "Size of Coleccion integers1 is " << integers1.getSize() << "\nColeccion after initialization: " << integers1 << endl;
	// print integers2 size and contents
	cout << "\nSize of Coleccion integers2 is " << integers2.getSize() << "\nColeccion after initialization: " << integers2 << endl;

	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;
	cin >> integers1 >> integers2;
	cout << "\nAfter input, the Coleccions contain:\n" << "integers1: " << integers1 << "\nintegers2: " << integers2;

	// use overloaded inequality (!=) operator
	cout << "\n\nEvaluating: integers1 != integers2" << endl;
	if (integers1 != integers2) cout << "integers1 and integers2 are not equal" << endl;

	// create Coleccion integers3 using integers1 as an initializer; print size and contents
	Coleccion integers3 (integers1); // invokes copy constructor
	cout << "\nSize of Coleccion integers3 is " << integers3.getSize() << "\nColeccion after initialization:" << integers3 << endl;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Coleccion is smaller
	
	cout << "\nintegers1: " << integers1 << "\nintegers2: " << integers2 << endl;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers" << endl;
	if (integers1 == integers2) cout << "integers1 and integers2 are equal" << endl;
	else cout << "integers1 and integers2 are not equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1[5] is " << integers1 [5];
	
	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1 [5] = 1000;
	cout << "integers1:" << integers1 << endl;
} // end main
