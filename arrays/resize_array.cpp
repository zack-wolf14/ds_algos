#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std; 

int main(){
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    int *q = new int[10];

    for(int i = 0; i<5; i++){
        // printf("%d", p[i]);
        cout << p[i] << endl; 
    }

    for(int i = 0; i<5; i++){
        q[i] = p[i];
        // cout << p[i] << endl; 
    }


    delete []p;
    p = q;
    q = NULL;

    for(int i = 0; i<10; i++){
        // printf("%d", p[i]);
        cout << p[i] << endl; 
    }



    return 0;
}