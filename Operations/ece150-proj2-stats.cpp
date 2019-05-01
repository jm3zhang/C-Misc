#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>

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