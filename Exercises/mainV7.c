#include "header.h"

int main(){

    float voltT, ResT=0, AmpT=0, voltE=0, ResE=0, AmpE=0, value;
    int a1, a2, i, loop;
    int p=0, s=1, count=1;

    printf("\nPIA Circuit Calculator  ~(^-^)~   \n\n");

    printf("Circuit Voltage: ");
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Insert resistance value of component (%d): ",count);
    
    do{
        scanf("%f",&value);
        if(value<=0) {
            printf("Zero and Negative values are not valid, Try again\n");
            printf("\nInsert resistance value of component (%d): ", count);
        }
    }while(value<=0);

    SERIE[s].num = count++;
    SERIE[s].resistance = value;

    printf("\nDo you want to add another component?\n(1-YES 2-NO): ");
    scanf("%d",&a1);
    
    if (a1 == 2)  loop=0;

    while(loop=1){

        fflush(stdin);

        if (count>2){
            printf("\nDo you want to add another component?\n(1-YES 2-NO): ");
            scanf("%d",&a1);
        }

        if (a1 == 2){
            break;
        }

        else if(a1 == 1){
            printf("\nHow is conected your component?\n(1-SERIES 2-PARALLEL): ");
            scanf("%d",&a2);

            if (a2==1){
                
                printf("\nInsert resistance value of component (%d): ",count);

                do{
                    scanf("%f",&value);
                    if(value<=0) {
                        printf("Zero and Negative values are not valid, Try again\n");
                        printf("\nInsert resistance value of component (%d): ", count);
                    }
                }while(value<=0);

                SERIE[++s].resistance = value;
                SERIE[s].num = count++;
                continue;
            }

            else if (a2==2){

                printf("\nInsert resistance value of component (%d): ", count);
                    
                do{
                    scanf("%f",&value);
                    if(value<=0) {
                        printf("Zero and Negative values are not valid, Try again\n");
                        printf("\nInsert resistance value of component (%d): ", count);
                    }
                }while(value<=0);
            
                PARALLEL[++p].resistance = value;
                PARALLEL[p].num = count++;
                continue;
            }

            else if (a2 != 1 && a2 != 2){
                printf("Sorry, try again2\n");
                continue;
            }
        }

        else if (a1 != 1 && a1 != 2){
            printf("Sorry, try again1\n");
            continue;
        }
    }
    
    SumRes(&ResT, &ResE, p, s);
    AmpT = (voltT/ResT);
    ValSerie(&AmpT, s);
    ValParallel(&AmpE, &AmpT, &voltE, &ResE, p);
    PrintValues(voltT, ResT, AmpT, p, s);
}
