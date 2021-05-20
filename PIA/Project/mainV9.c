#include "header.h"

void main(){

    float voltT, ResT=0, AmpT=0, voltE=0, ResE=0, AmpE=0, value;                             //values of the circuit
    int a1, a2, i, loop;                                                                     //variables for the loop
    int p=0, s=1, count=1;                                                                  //component counters

    printf("\n---------------------------------------------");
    printf("\nPIA Circuit Calculator  ~(^-^)~   \n\n");

    printf("Circuit Voltage: ");                                                              //Introduce the total voltage
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Insert resistance value of component (%d): ",count);
    
    do{                                                                                                           
        scanf("%f",&value);
        if(value<=0) {
            printf("Zero and Negative values are not valid, Try again\n");                      //negatives and zero values are not accepted 
            printf("\nInsert resistance value of component (%d): ", count);
        }
    }while(value<=0);

    SERIE[s].num = count++;
    SERIE[s].resistance = value;

    do{                                                                                         //loop
        fflush(stdin);
        printf("\nDo you want to add another component?\n(1-YES 2-NO): ");                      //ask question1
        scanf("%d",&a1);
        int j=0;

        switch(a1){

            case(1):
                do{
                    fflush(stdin);
                    printf("\nHow is conected your component?\n(1-SERIES 2-PARALLEL): ");                    //ask question2
                    scanf("%d",&a2);

                    switch(a2){

                        case(1):                                                                           //add components in series
                            printf("\nInsert resistance value of component (%d): ",count);
                            do{
                                scanf("%f",&value);
                                if(value<=0) {
                                    printf("Zero and Negative values are not valid, Try again\n");         //negatives and zero values are not accepted 
                                    printf("\nInsert resistance value of component (%d): ", count);
                                }
                            }while(value<=0);
                            
                            SERIE[++s].resistance = value;
                            SERIE[s].num = count++;
                            j++;
                            continue;

                        case(2):                                                                         //add components in parallel
                            printf("\nInsert resistance value of component (%d): ", count);
                            do{
                                scanf("%f",&value);
                                if(value<=0) {
                                    printf("Zero and Negative values are not valid, Try again\n");      //negatives and zero values are not accepted 
                                    printf("\nInsert resistance value of component (%d): ", count);
                                }
                            }while(value<=0);

                            PARALLEL[++p].resistance = value;
                            PARALLEL[p].num = count++;
                            j++;
                            continue;

                        default:
                            printf("Sorry, try again\n");              //if you introduce a wrong input the loop will continue until your answer is correct
                            continue;
                    }
                    
                }while(j==0);
                continue;

            case(2): break;                             
            default:
                printf("Sorry, try again\n");            //if you introduce a wrong input the loop will continue until your answer is correct
                continue;
        }

        if(a1 == 2) break;                             //if you chose 2 the loop breaks

    }while(1);

    SumRes(&ResT, &ResE, p, s);                         //Obtain the Equivalent resistance and Total Resistance
    AmpT = (voltT/ResT);                                
    ValSerie(&AmpT, s);                                 //Obtain all the individual values of components conected in series
    ValParallel(&AmpE, &AmpT, &voltE, &ResE, p);        //Obtain all the individual values of components conected in parallel
    PrintValues(voltT, ResT, AmpT, p, s);               //Print all the values
}
