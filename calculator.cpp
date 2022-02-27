/*
 * calculator.cpp
 *
 *  Created on: Sep 2, 2021
 *      Author: Jakob
 */


#include <iostream>
#include <limits>
using namespace std;

//pass by reference used for functions

void add(float &a, float &b) {
	cout << a << " + " << b << " = " << a+b; //Function pulls x and y that user input and outs the sum of them

}

void sub(float &a, float &b) {
	cout << a << " - " << b << " = " << a-b; //Function that is called if people choose subtraction

}

void mult(float &a, float &b) {
	cout << a << " x " << b << " = " << a*b; //Function that is called if people choose multiplication

}

void div(float &a, float &b) {
	cout << a << " / " << b << " = " << a/b; //Function that is called if people choose division

}

int main () {


	int *userInput = new int; //used to read what operator the user chooses
	float *userNum1 = new float; //the first number that the user enters, using pointer variables
	float *userNum2 = new float; // the second number that the user enters
	do {

	cout<<"\n\n-SIMPLE CALCULATOR by Jakob Tiger-\n\n";
	cout<<"To begin enter the number of the operation you would like to use\n\n";
	cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n\n";
	cin >> *userInput; //collects users choice for operation
	if(*userInput>=1 && *userInput<5){ // if user enters 1-5 switch operation is started, if not user is presented with error
	cout << "Now enter the two numbers you would like to apply the operation to.\n\n";
	cin >> *userNum1; //collects the users numbers
	cin >> *userNum2;

	switch (*userInput) {
	case 1:
		add(*userNum1, *userNum2); //call to function add to get the sum of the users numbers
		break;

	case 2:
		sub(*userNum1, *userNum2);//call to function to get the difference of the numbers
		break;

	case 3:
		mult(*userNum1, *userNum2);//call to function to multiply the numbers
		break;

	case 4:
		div(*userNum1, *userNum2);//call to function to divide the numbers
		break;
	}

	}

	else if (*userInput > 5){ // if anything > 5 is entered for operation selection error message is displayed
		cout << "Error: Not a valid operator selection. Please restart.\n";
		cin.clear();//clears error flag on cin if user enters non integer
		cin.ignore(10000, '\n'); //skips to the next line to ignore any other invalid inputs on that line, up to 10k characters
	}
	delete userNum1; //Deallocating variables for restart to not run out of memory
	delete userNum2;
	}while(*userInput!=5);

	if (*userInput == 5) // when 5 is selected do loop is finished and program is terminated
		cout << "Program exited";
	return 0;

}



