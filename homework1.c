#include<stdio.h>

int main () {
    float x= 1.5;
    int y = 20;

    while (x<=y){        
        x = x/3;
        y = y*x;
        
    }
    printf("%.2f,%d\n",x,y);
}

/* 0.06,0 */
