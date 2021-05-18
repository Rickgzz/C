#include <stdio.h>
#define MAX 50

struct SERIE{

    int num;
    float resistance, voltage, current;

} SERIE[MAX];

struct PARALLEL{

    int num;
    float resistance, voltage, current;

} PARALLEL[MAX];


int main(){

    float voltT, ResT, AmpT, voltE, ResE, AmpE;
    int a1, a2, i, loop;
    int p=0, s=1, n=1;

    printf("\nPIA Circuit Calculator  ~(^-^)~   \n\n");

    printf("Circuit Voltage: ");
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Introduce resistance value component (%d): ",n);
    scanf("%f", &SERIE[s].resistance);
    SERIE[s].num = n++;


    printf("\nDo you want to add another component?\n(1-YES 2-NO): ");
    scanf("%d",&a1);
    
    if (a1 == 2)  loop=0;

    while(loop=1){

        fflush(stdin);

        if (n>2){
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
                
                printf("\nIntroduce de resistance value of the component (%d): ",n);
                scanf("%f", &SERIE[++s].resistance);
                SERIE[s].num = n++;
                continue;
            }

            else if (a2==2){

                printf("\nIntroduce de resistance value of the component (%d): ", n);
                scanf("%f", &PARALLEL[++p].resistance);
                PARALLEL[p].num = n++;
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
    
    for (i=1; i<=s; i++)    ResT += (SERIE[i].resistance);          

    for (i=1; i<=p; i++)    ResE += 1/(PARALLEL[i].resistance);     
    
    if(p>0){                                                  
        
        ResE = 1/(ResE);
        ResT += ResE;
    }
    
    AmpT = (voltT/ResT);
    
    for (i=1; i<=s; i++){                                          
        
        SERIE[i].current = AmpT;
        SERIE[i].voltage = (AmpT*(SERIE[i].resistance));
    }
    
    if(p>0){                                                  
        
        AmpE = AmpT;
        voltE = (AmpE*ResE);
    }
    
    for (i=1; i<=p; i++){
        
        PARALLEL[i].voltage = voltE;
        PARALLEL[i].current = (voltE/(PARALLEL[i].resistance));        
    } 

    printf("\n\nThe total Voltage is: %.2f volts\n", voltT);        
    printf("The total Resistance is: %.2f ohms\n", ResT);
    printf("The total Current is: %.2f amperes\n", AmpT); 

    printf("\nVoltage[V]  Resistance[R]  Current[I]\n");
    printf("\nValues of the components in SERIES:\n");
    for(i=1; i<=s; i++){

        printf("Component(%d): [V:%.1f][R:%.1f][I:%.1f]\n", SERIE[i].num, SERIE[i].voltage, SERIE[i].resistance, SERIE[i].current );
    }
    
    if (p>0){

        printf("\nValues of the components in PARALLEL:\n");
        for(i=1; i<=p; i++){

            printf("Component(%d): [V:%.1f][R:%.1f][I:%.1f]\n", PARALLEL[i].num, PARALLEL[i].voltage, PARALLEL[i].resistance, PARALLEL[i].current );
        }
    }
}

// HACER UNA FUNCION QUE OBTENGA LA RES EQUIVALENTE, UNA DE RES TOTAL Y OTRA DE VALORES ABSOLUTOS
