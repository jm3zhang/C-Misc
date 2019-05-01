#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main (int numArgs, char* args[]){
	
    //put command into strings
    
    if (numArgs < 3) {
        cerr << "Error" << endl;
        return -1;
    }
    
    string LongNum = args[1];
    string ShortNum = args[2];
    int l = LongNum.length();
    int s = ShortNum.length();
    
    
    
    //cout << LongNum << " " << ShortNum << endl;
    
    //find the longer one and add 0 to the short on
    
    if (l < s){
        swap(LongNum,ShortNum);
        reverse(ShortNum.begin(),ShortNum.end());
        while(l!=s)  {  ShortNum += "0";
            l++;}
        reverse(ShortNum.begin(),ShortNum.end());
    }
    
    
    
    /*cout << ShortNum << endl;
    cout << LongNum << endl;
    //cout << LongNum << endl;*/
    
    
    //put strings into array
    
    int intLongNum[l];
    int intShortNum[l];
    
    for (int w = 0; w<l; w++) {
        intLongNum[w] = LongNum[w]-48;
        intShortNum[w] = ShortNum[w]-48;
    }
    
    //cout << intLongNum[3]+ 1 << endl;
    
    //calculate the int
    
    int reuslt[l];
    int adding[l + 1];
    adding[0] = 0;
    
    for (int o = 0; o < l; o++) {
        
        if ((intLongNum[o]+intShortNum[o])<10){
            reuslt[o] = intShortNum[o]+ intLongNum[o];
            adding[o+1] = 0;
            
        }
                                               
        else if ((intLongNum[o]+intShortNum[o])==10) {
            reuslt[o] = 0;
            adding[o+1] = 1;
        }
                                               
        else if ((intLongNum[o]+intShortNum[o])>10){
            reuslt[o] = (intShortNum[o]+ intLongNum[o])-10;
            adding[o+1] = 1;
            
        }
        
    }
    
    if ((intLongNum[l]+intShortNum[l])>=10) {
        reuslt[0] = (intShortNum[0]+ intLongNum[0])-10;
        adding[0] = 1;
    }
    
    for (int y = 0; y<l ; y++) {
        reuslt[y] += adding[y+1];
    }
    
    for (int k = 0; k < l; k++){
        cout << reuslt[k];
    }
    
    cout << endl;

	return 0;
}