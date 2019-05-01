#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main () {

	int month;
	int day;

	cin >> month;
	cin >> day;

	if(month == 2 ){

		if(day == 18){
			cout << "Special" << endl;
		}

		else if(day < 18 && day > 0){
			cout << "Before" << endl;
		}

		else if(day > 18 && day < 29){
			cout << "After" << endl;
		}

	}
    
    
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if (day < 1 || day > 31){
			cerr << "There is no such date in 2015!" << endl;
        }
	}

	if(month == 4 || month == 6 || month == 9 || month ==  11){
        if (day < 1 || day > 30){
			cerr << "There is no such date in 2015!" << endl;
        }
 
	}

	else if(month < 2 && month > 0){
		cout << "Before" << endl;
	}

	else if(month > 2 && month < 12){
		cout << "After" << endl;
	}

	else{
		cerr << "There is no such date in 2015!" << endl;
	}

     return 0;
     
}