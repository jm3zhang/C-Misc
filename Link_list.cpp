#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "ece150-10-provided.h"

using namespace std;

void restoreSorted(intListEntry * &a/*they declared*/) {

	intListEntry *firstPointer = a;
	//to sort the pointers
	int pointerArray[1000000];
	int pointerCounter = 0;

	//put the elements into the array
	while(firstPointer != '\0') {
    	pointerCounter++;
        pointerArray[pointerCounter] = firstPointer->i; //declared in h
		firstPointer = firstPointer->next;
	}
	pointerCounter -= 1;

	//sort
	for (int n = 1; n < pointerCounter; n++) {
		for (int i = n; i < pointerCounter; i++) {
			//bubble sort
			if (pointerArray[n] > pointerArray[i]) {
                swap (pointerArray[n],pointerArray[i]);
			}
		}
	}
	
	firstPointer = a;
	
	//put the elements in array into pointer
    for (int i = 1; i < pointerCounter; i++)
	{
		firstPointer->i = pointerArray[i];
		firstPointer = firstPointer->next;
	}
}

/* testing
test(intListEntry * &a) {
	while (a != '\0') {
		cout << a->i << endl;
		a = a->next;
	}
}

/* getting or making the link list */
void makingList(intListEntry * &a, int newPointer) {
	//first check if the element we want to put in list is null
    if (a == '\0') {
		a = new /*new pointer*/ intListEntry;
		a->i = newPointer;
		a->next = '\0';
		return;
	}	

	intListEntry *otherPointer = '\0';
	otherPointer = a;

	while (otherPointer->next != '\0') {
		otherPointer = otherPointer->next;
	}

	intListEntry *pointer= new intListEntry;
	pointer->next = pointer;
	pointer->i = newPointer;
	pointer->next == '\0';
}

//h file
mixedFraction::mixedFraction(int w, int n, int d) {
	whole = w;
	fraction.numerator = n;
	fraction.denominator = d;
}

void mixedFraction::add(mixedFraction f) {
	whole += f.whole;
	fraction.numerator = fraction.numerator * f.fraction.denominator + f.fraction.numerator * fraction.denominator;
	fraction.denominator = f.fraction.denominator * fraction.denominator;
	
	if (fraction.denominator < 0) {
		fraction.denominator = fraction.denominator * -1;
		fraction.numerator = fraction.numerator * -1;
	}

}

void mixedFraction::simplify() {
	//the mixed fraction's numerator might be a negative int
	while (1) {
		if ( fraction.numerator < 0 && fraction.denominator > 0 && fraction.numerator + fraction.denominator < 0) {
			
			fraction.numerator = fraction.numerator + fraction.denominator;
			whole -= 1;
		}

		else {
			break;
		}
	}

	int mixedWhole = 0;

	while (1) {
	// how to simplify the mix fraction?
	// numerator - denominator is the number that can go the the whole #
	// 2/1/5 = (2 + 1/5) = 11/5
	// 3/2/1 = (3 + 2/1) = 5 
		
		if (fraction.numerator >= fraction.denominator) {
			fraction.numerator -= fraction.denominator;
			mixedWhole++;
		}
		
		else {
			break;
		}
	}

	whole = whole + mixedWhole;

	// 3/2/1 = (3 + 2/1) = 5 is a special case
	// all the fraction with a 1 as the numrator are special cases which means that the the denominator shoulb be bigger than 2

	int specialDenominator = 2;

	while ( specialDenominator <= fraction.denominator) {
		if (fraction.numerator % specialDenominator == 0 && fraction.denominator % specialDenominator == 0) {
			fraction.numerator = fraction.numerator/specialDenominator;
			fraction.denominator = fraction.denominator/specialDenominator;
			specialDenominator = 2;
		}
		else {
			specialDenominator++;
		}
	}

	if (fraction.numerator < 0 && whole != 0) {
		//absolute value
		fraction.numerator = abs(fraction.numerator);
	}
}

void mixedFraction::print() {
	
    //specialDenominator
	if (fraction.denominator == 1 || fraction.numerator == 0) {
		cout << whole << endl;
	}

	else if (whole == 0) {
		cout << fraction.numerator << "/" << fraction.denominator << endl;
	}

	//Error
	else if (fraction.denominator == 0) {
		cerr << "Error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	
	else {
		cout << whole << " " << fraction.numerator << "/" << fraction.denominator << endl;
	}
}

	
