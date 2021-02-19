#include <stdio.h>
#define FROM 3
#define TO 40
#define STEP 3
#define EVEN 0

int parity(int v);
int main() {
    int j;
    int count =0;
    for (j= FROM; j<TO; j=j+STEP ) {
        
        if (parity(j)== EVEN) {
            count = count + 1;
        }
    }
    printf("%d\n", count);
}

int parity(int v) {
    return v%2 ;
}
