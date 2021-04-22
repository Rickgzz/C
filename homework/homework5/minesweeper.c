#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void show(int OUT [ROWS][COLUMNS],int u[ROWS][COLUMNS]) {

    int i, j;
    printf("\n"); 

    for (int h=0 ;h<NUM+1;h++) {    
       printf("%d\t",h);   
    }
    printf("\n");

    for (i = 0; i<ROWS; i++) {

        for (j = 0; j<COLUMNS; j++) {

            if (j == 0)printf("%d\t", i+1);
            if (u[i][j] == 0)printf("#\t");
            else if (u[i][j] == 1) {

                if (OUT[i][j] == 0)printf("0\t");
                else printf("%d\t", OUT [i][j]);
            }
            else if (u[i][j] == -1) {
                printf("-1\t");
            }
        }
        printf("\n");
    }
}

int find(int OUT [ROWS][COLUMNS], int i, int j) {

    int l, c,lmin,cmin, lmax, cmax, num = 0;
    l = lmin = (i - 1) >= 0 ? (i - 1) : 0;                 
    c = cmin = (j - 1) >= 0 ? (j - 1) : 0;
    lmax = ((i + 1) < ROWS ? (i + 1) : 4);                   
    cmax = ((j + 1) < COLUMNS ? (j + 1) : 4);

    for (l = lmin; l <= lmax; l++) {
        for (c = cmin; c <= cmax; c++) {

            if (l == i&&c == j)continue;                
            if (OUT[l][c] == -1)num++;                     
        }
    }
    return num;
}

void init(int OUT[ROWS][COLUMNS]){
    int n = 9, l, c, i, j;
    srand(time(NULL));       

    for (i = 0; i< 10; i++) {
        for (j = 0; j< 10; j++) {
            OUT[i][j] = 0;                                
        }
    }
    while (n--) {

        l = rand() % 10;
        c = rand() % 10;
        if (OUT[l][c] != -1)OUT[l][c] = -1;                
        else n++;
    }
    for (i = 0; i< 10; i++) {
        for (j = 0; j< 10; j++) {
            if (OUT[i][j] != -1) {
                OUT[i][j] = find(OUT, i, j);               
            }
        }
    }
}

void open(int OUT[ROWS][COLUMNS],int u[ROWS][COLUMNS], int i, int j) {
    u[i][j] = 1;
    if (OUT[i][j] == 0) {
        if (i - 1 >= 0 && u[i - 1][j] != 1)open(OUT, u, i - 1, j);   
        if (j - 1 >= 0 && u[i][j - 1] != 1)open(OUT, u, i, j - 1);   
        if (i + 1 <= 4 && u[i + 1][j] != 1)open(OUT, u, i + 1, j);  
        if (j + 1 <= 4 && u[i][j + 1] != 1)open(OUT, u, i, j + 1);  
    }
}

void menu(int OUT[ROWS][COLUMNS],int u[ROWS][COLUMNS]) {

    int chs,i,j;
    int bombs = 9;                                 
    int num = 0;                                    
    while (1) {

        system("cls");
        show(OUT,u);
        printf("There's %d bombs left\n",bombs);
        printf("1.Scan  2.Check  3.Uncheck \n");
        printf("Choose an option: ");
        scanf("%d", &chs);

        if (chs > 3 || chs < 1) {
            printf("Introduce the correct option\n");
            system("pause");
            continue;
        }
        printf("Introduce the coordinates (x y): ");
        scanf("%d %d", &j, &i);

        if (i < 1 || i>10 || j< 1 || j>10) {
            printf("Introduce the correct coordinates\n");
            system("pause");
            continue;
        }
        i--;            
        j--;
        if (chs == 1) {
            if (OUT[i][j] == -1) {
                if (num == 0) {     
                    init(OUT);
                    show(OUT, u);
                    open(OUT, u, i, j);
                    num++;
                    continue;
                }
                else {
                    printf("YOU LOSE!!! \n");
                    break;
                }
            }
            if (u[i][j] == 1)  {
                printf("This location has already been scanned\n");
                system("pause");
                continue;
            }
            open(OUT, u, i, j);
            num++;
        }
        else if(chs == 2) {
            if (u[i][j] == 1) {
                printf("This location has already been scanned \n"); 
                system("pause");
                continue;
            }
            u[i][j] = -1;
            bombs--;            
        }
        else if (chs == 3) {
            if (u[i][j] != -1) {
                printf("The location isn't checked\n");       
                system("pause");
                continue;
            }
            u[i][j] = 0;
            bombs++;
        }
    }
}

int main(){
    int OUT[ROWS][COLUMNS] = { 0 };        // Guarde la matriz bidimensional de información sobre bombas
    int u[ROWS][COLUMNS] = { 0 };          // Guardar una matriz de información bidimensional
    init(OUT);             			       // Inicialización de matriz
    menu(OUT, u);            		       // Ingresa al menú
    return 0;
}
//CREDITS ISRAEL VERA
