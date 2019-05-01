#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

extern float avg(float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float median(float item[], int size);
extern float aad(float item[], float m, int size);

using namespace std;

float avg(float item[], int size){
    
    float sum = 0;
    
    for (int i = 0; i < size; i++) {
        
        sum += item[i];
    }
    
    return sum/(float)size;
    
}

float stdDev(float item[], float a, int size){
    
    float sum = 0;
    float v;
    
    for (int i = 0; i < size ; i++) {
        
        sum += pow(item[i] - a, 2);
        
    }
    
    v = sum/(float)size;
    
    return sqrt(v);
    
}

float median(float item[], int size){
    
    for (int n = 1; n < size; n++) {
        
        for (int i = 1; i < size; i++) {
            
            if (item[i] < item[i-1]){
                swap(item[i],item[i-1]);
            }
            
        }
    }
    
    if (size % 2 == 1){
        return item[size/2];
    }
    
    else if (size % 2 == 0){
        return (item[(size/2)-1] + item[size/2])/2;
    }
}

float aad(float item[], float m, int size){
    
    float sum = 0;
    
    for (int i = 0; i < size; i++) {
        
        sum += abs(item[i] - m);
        
    }
    
    return sum/(float)size;
}

int main (int Argc, char *Argv[]) {

    ifstream infile;
    infile.open("ece150-proj2-input.txt");
    
    char URL[10000];
    int sizeOfUrl;
    int priorityOfUrl;
    string inputUrl[10000];
    int inputSize[10000];
    int counterInput = 0;
    int inputpriority[10000];
    string userInputUrl;
    string userInputList[10000];
    int counterUserInput = 0;
    int p = 0;
    
    
    
    
    while(infile >> URL >> sizeOfUrl >> priorityOfUrl){
        if (sizeOfUrl <= 0 || priorityOfUrl < 0){
            cerr << "..." << endl;
            return -1;
        }
        inputUrl[counterInput] = URL;
        inputSize[counterInput] = sizeOfUrl;
        inputpriority[counterInput] = priorityOfUrl;
        counterInput++;
        
    }
    infile.close();
    
    while (userInputUrl != "exit") {
        cin >> userInputUrl;
        userInputList[counterUserInput] = userInputUrl;
        counterUserInput++;
    }

    
    /*for (int i = 0; i < (counterUserInput - 1); i++) {
        cout << "test";
        cout << userInputList[i] << " " << "111" << endl;
    }
    
    for (int i = 0; i < (counterInput); i++) {
        cout << inputUrl[i] << endl;
    }*/
    
    for (int n = 0; n < counterUserInput - 1; n++) {
        for (int i = 0; i < counterUserInput - 1; i++) {
            if (userInputList[n] != inputUrl[i]) {
                p = 1;
            }
            else if (userInputList[n] == inputUrl[i]){
                p = 0;
                break;
            }
        }
        if( p== 1){
            break;
        }
    }
    
    //cout << p << endl;
    
    if (p == 1) {
        cerr << "Error!!!!!!!!!!!!!!!!!!!!!!" << endl;
        return -1;
    }
    
    /*else if (p==0){
    cout << "0000" << endl;
    }
    cout << counterUserInput - 1 << " " << counterInput << endl;*/
    
    float sizeList[counterUserInput-1];
    float priorityList[counterUserInput-1];
    
    for (int n = 0; n < (counterUserInput - 1); n++) {
        for (int i = 0; i < (counterUserInput - 1); i++) {
            if (userInputList[n] == inputUrl[i]) {
                sizeList[n] = inputSize [i];
                priorityList[n] = inputpriority[i];
            }
        }
    }
    
    /*for (int i = 0; i < (counterUserInput -1); i++) {
        cout << sizeList[i] << " " << priorityList[i] << endl;
    }*/
    
    float avgSize;
    float medianSize;
    float stdDevSize;
    float aadSize;
    float avgPriority;
    float medianPriority;
    float stdDevPriority;
    float aadpriority;
    float avgDelay;
    float medianDelay;
    float stdDevDelay;
    float aadDelay;
    
    avgSize = avg(sizeList,counterUserInput - 1);
    medianSize = median(sizeList,counterUserInput - 1);
    stdDevSize = stdDev(sizeList,avgSize,counterUserInput - 1);
    aadSize = aad(sizeList,medianSize,counterUserInput - 1);
    avgPriority = avg(priorityList,counterUserInput - 1);
    medianPriority = median(priorityList,counterUserInput - 1);
    stdDevPriority = stdDev(priorityList,avgPriority,counterUserInput - 1);
    aadpriority = aad(priorityList,medianPriority,counterUserInput - 1);
    
    for (int i = 0; i < counterUserInput - 1; i++) {
        sizeList[i] *= 0.8;
    }
    
    avgDelay = avg(sizeList,counterUserInput - 1);
    medianDelay = median(sizeList,counterUserInput - 1);
    stdDevDelay = stdDev(sizeList,avgSize,counterUserInput - 1);
    aadDelay = aad(sizeList,medianSize,counterUserInput - 1);
    
    srand(time(NULL));
    int r[counterUserInput - 1];
    for(int i = 0; i < counterUserInput - 1; i++){
        r[i] = rand();
    }
    
    cout << avgSize << " " << medianSize << " " << stdDevSize << " " << aadSize << endl;
    cout << avgPriority << " " << medianPriority << " " << stdDevPriority << " " << aadpriority << endl;
    cout << avgDelay << " " << medianDelay << " " << stdDevDelay << " " << aadDelay << endl;
    
}
