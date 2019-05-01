#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;


int main () {
    
    ifstream infile;
    infile.open("ece150-proj1-input.txt");
    
    ofstream outfile;
    outfile.open("ece150-proj1-output.txt");
    
    char URL[1000];
    float averageURL;
    float priority;
    float sumavgURL = 0;
    float sumprioriry = 0;
    int numavgURL = 0;
    int numpriority =0;
    float AverageSize;
    float Expecteddelayforpriorit;
    float Expectedtotaldelay;
    int p = 0;
    
    
    while(infile >> URL >> averageURL >> priority){
        
        if (priority >= 0 && priority <=5 && averageURL > 0){
        sumavgURL = sumavgURL + averageURL;
        sumprioriry = sumprioriry + priority;
            
        }
        else {
            p=1;
        }
        numavgURL = numavgURL + 1;
        numpriority = numpriority + 1;
    }
    infile.close();
    
    
    if (priority==0 || averageURL==0){
        p=1;
    }
    
    if (p==0){
        AverageSize = sumavgURL/numavgURL;
        Expecteddelayforpriorit = sumprioriry/numpriority;
        Expectedtotaldelay = ((sumavgURL*8)/10+sumprioriry)/numpriority;

    }
    
    else if (p==1){
        AverageSize = 0;
        Expecteddelayforpriorit = 0;
        Expectedtotaldelay = 0;
    }
    
    outfile << "Average size = " << AverageSize << endl;
    outfile << "Expected delay for priorit = " << Expecteddelayforpriorit << endl;
    outfile << "Expected total delay = " << Expectedtotaldelay << endl;
    outfile.close();
    
    
    return 0;
}