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
    int a1;
    int c25a, c10a, c5a,c1a;
    
    
    cin >> c25 >> c10 >> c5 >> c1 >> a;
    
    a1=a;
    c25a=c25;
    c10a=c10;
    c5a=c5;
    c1a=c1;
    
    if (c25a*25+c10a*10+c5a*5+c1a*1>=a) {
        
    
        while (c25>0 && a1>=25){
            a1 -= 25;
            c25--;
            Qneed++;
        }
        
        while (c10>0 && a1>=10){
            a1 -= 10;
            c10--;
            Tneed++;
        }
    
    while (c5>0 && a1>=5){
        a1 -= 5;
        c5--;
        Fneed++;
    }
    
    while (c1>0 && a1>=1){
        a1 -= 1;
        c1--;
        Oneed++;
    }
        
    //greed code
    //cout << Qneed << " " << Tneed  << " " << Fneed << " " << Oneed << endl;
    
    if (a1>0){
        /*30-25=5
        reture the 25*/
        Qneed -= 1;
        /* 1 3 1 0 30
            1 0 1 0*/
        Fneed = 0;
        Tneed = 0;
        Oneed = 0;
        
        a=a-25*Qneed;
            
        //30 0 3 0 0
        while(c10a>0 && a>=10){
            a -= 10;
            c10a--;
            Tneed++;
        }
        while(c5a>0 && a>=5){
            a -= 5;
            c5a--;
            Fneed++;
        }
        while(c1a>0 && a>=1){
            a -= 1;
            c1a--;
            Oneed++;
        }
        
        if (a==0){
            cout << Qneed << " " << Tneed  << " " << Fneed << " " << Oneed << endl;
        }
    
        else {
            cerr << "Error: cannot make change" << endl;
        }
        
        
    }
    
    else {
        
        if (a1==0){
            cout << Qneed << " " << Tneed  << " " << Fneed << " " << Oneed << endl;
        }

    }
    }
    
    else {
        cerr << "Error: cannot make change" << endl;
    }

    
    return 0;
    
}