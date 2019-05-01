#include <stdio.h>
#include <iostream>


using namespace std;


int main () {

    int c25;
    int c10;
    int c5;
    int c1;
    int Qneed = 0;
    int Tneed = 0;
    int Fneed = 0;
    int Oneed = 0;
    int a;
    int p=0;
    
    cin >> c25 >> c10 >> c5 >> c1 >> a;
    
    //cout << c25 << " " << c10 << " "<< c5  << " "<< c1 << " "<< A << endl;
    
    while (p == 0|c25 >0) {
        a -= 25;
        c25--;
        Qneed = Qneed+1;
        if (a<0) {
            Qneed -= 1;
            a +=25;
            p=1;
        }
        else if (a>=25){
            p=0;
        }
        
        else if (a<25&a>10){
            p=1;
        }
        
        else if (a<=10&a>5){
            Qneed -= 1;
            a +=25;
            p=1;
        }
        else if (a<=5&a>1) {
            Qneed -= 1;
            a +=25;
            p=1;
        }
        else if (a<=5&a>1) {
            Qneed -= 1;
            a +=25;
            p=1;
        }
        else if (a==0) {
            p=1000;
        }
    }
        
    while (p==1 | c10 >0) {
        a -= 10;
        c10--;
        Tneed = Tneed+1;
        if (a<0) {
            Tneed -= 1;
            a += 10;
            p=2;
        }
        else if (a>=10){
            p=1;
        }
        
        else if (a<10&a>=5){
            Tneed -= 1;
            a += 10;
            p=2;
        }
        
        else if (a<5&a>=1){
            Tneed -= 1;
             a += 10;
            p=2;
        }
        else if (a==0){
            p=1000;
        }
    }
    
    while (p==2|c5 >0) {
        a -= 5;
        c5--;
        Fneed = Fneed+1;
        if (a<0) {
            Tneed -= 1;
            a += 5;
            p=3;
        }
        else if (a>=5){
            p=2;
        }
        
        else if (a<5&a>=1){
            Tneed -= 1;
            a += 5;
            p=3;
        }
        else if (a==0){
            p=1000;
        }

    }
    
    while (p==3 | c1 >0) {
        a -= 1;
        c1--;
        Oneed = Oneed+1;
        if (a<0) {
            Oneed -= 1;
            p=500;
        }
        else if (a>=1){
            p=3;
        }
        else if (a==0){
            p=1000;
        }
    }
    

    if (p==1000) {
        cout << Qneed << " " << Tneed << " " << Fneed << " " << Oneed << endl;
    }
    
    else if (a>0) {
        cerr << "Error: cannot make change" << endl;
    }
    
    else if (p==500) {
        cerr << "Error: cannot make change" << endl;
    }
    
       
    return 0;
}