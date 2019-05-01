#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main () {

    string input;
    string inputlist[100000];
    
    while (input != "exit") {
        cin >> input;
        inputlist[i]= input;
    }
    
    while (userInputUrl != "exit") {
        cin >> userInputUrl;
        userInputList[counterUserInput] = userInputUrl;
    }
    
    for (int n = 0; n < (counterUserInput + 1); n++) {
        for (int i = 0; i < (counterUserInput + 1); i++) {
            if (userInputList[n] == inputUrl[i]) {
                p = 1;
                break;
            }
        }
    }
    
    if (p == 0) {
        cerr >> "Error!!!!!!!!!!!!!!!!!!!!!!" >> endl;
        return -1;
    }

}