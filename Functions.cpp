#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;

int largestOfThree(float a,int b,char c){

	if (a >= b && a >= c){
		return 0;
	}

	else if (b >= a && b >= c){
		return 1;
	}

	else if (c >= a && c >= b){
		return 2;
	}

	else {
		return -1;
	}
}

int isString(char *s, int maxSize){
    
    int x = strlen(s);
    if (maxSize < 0){
        return -1;
    }
    
    else if (x==0) {
        return 0;
    }
    
    else if (maxSize >= x) {
        return x;
    }
    
    else{
        return -1;
    }
}


void interleave(int a[], int alen, int b[], int blen, int result[], int maxresultlen){
    
    if (maxresultlen >= alen + blen) {
        if (alen > blen) {
            int n=0;
            int i=0;
            while (n < blen){
                result[i] = a[n];
                result[i+1] = b[n];
                i = i + 2;
                n++;
            }
            
            while (n < alen) {
                result[n] = a[n];
                n++;
            }
        }
        
        else if (alen < blen){
            int n=0;
            int i=0;
            while (n < alen){
                result[i] = a[n];
                result[i+1] = b[n];
                i = i + 2;
                n++;
            }
            
            while (n < blen) {
                result[n] = b[n];
                n++;
            }

        }
        
        else if (alen == blen){
            int n=0;
            int i=0;
            while (n < alen){
                result[i] = a[n];
                result[i+1] = b[n];
                i = i + 2;
                n++;
            }

        }
    }
    
    else if (maxresultlen < alen + blen){
        if(maxresultlen % 2 == 1){
            int halfLen = maxresultlen/2;
            if (alen > blen && blen > halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                result[n] = a[n];
            }
            
            else if (alen > blen && blen < halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < blen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                while (n < maxresultlen) {
                    result[n] = a[n];
                    n++;
                }
            }
            
            else if (alen < blen && alen > halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                result[n] = b[n];
            }
            
            else if (alen < blen && alen < halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < alen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                while (n < maxresultlen) {
                    result[n] = b[n];
                    n++;
                }
            }
            
            else if (alen == blen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
    
            }
        }
        
        else if(maxresultlen % 2 == 0){
            int halfLen = maxresultlen/2;
            if (alen > blen && blen > halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
               
            }
            
            else if (alen > blen && blen < halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < blen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                while (n < maxresultlen) {
                    result[n] = a[n];
                    n++;
                }
            }
            
            else if (alen < blen && alen > halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }

            }
            
            else if (alen < blen && alen < halfLen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < alen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
                while (n < maxresultlen) {
                    result[n] = b[n];
                    n++;
                }
            }
            
            else if (alen == blen) {
                int i = 0;
                int n = 0;
                int t = 0;
                
                while (t < halfLen){
                    result[i] = a[n];
                    result[i+1] = b[n];
                    i = i + 2;
                    n++;
                }
                
            }
        }
        
    }
}





/*int main(){
    char *s;
    int max = 10;
    cin >> s ;
    cout <<isString(s, max) <<endl;
}*/