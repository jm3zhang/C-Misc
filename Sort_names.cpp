#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
using namespace std;

int main (int numArgs, char* args[])
{
	//knowing how many names needed
    
    int n = atoi(args[1]);
    string *fName = new string[n];
    string *lName = new string[n];
    
    


	//cin all those names into the array.
    
    for (int i = 0;i < n; i++){
        
        string lNameIn;
        string fNameIn;
        cin >> fNameIn >> lNameIn;
        fName[i]=fNameIn;
        lName[i]=lNameIn;
    }
    //printf("test\n");
    /*cout << fName[2] << " " << lName[2] << endl;
    cout << fName[1] << " " << lName[1] << endl;
    cout << fName[0] << " " << lName[0] << endl;*/

	//sorted the name
    
    
    while(1){
        int t = 0;
        
        for (int b = 1;b < n; b++) {
            if (lName[b] == lName[b-1]){
                if (fName[b] < fName[b - 1]) {
                    t = 1;
                    swap(lName[b],lName[b-1]);
                    swap(fName[b],fName[b-1]);
                }
            }
            else if (lName[b] < lName[b - 1]){
                t = 1;
                swap(lName[b],lName[b-1]);
                swap(fName[b],fName[b-1]);
            }
                        //cout << lName[b] << " " << lName[b-1] << endl;
            //cout << "t: " << t << endl;
        }
        if (t == 0) {
            break;
        }

    }

    //cout result
    
    for ( int c = 0; c < n; c++) {
        
        cout << fName[c] << " " << lName[c] <<endl;
        
    }


	return 0;
}