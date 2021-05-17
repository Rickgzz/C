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
    int a1, a2, loop;
    int p=0, s=1, i=0, n=1;

    printf("\nPIA Circuit Calculator  ~(^-^)~   \n\n");

    printf("Circuit Voltage: ");
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Introduce resistance value component (%d): ",n);
    scanf("%f", &SERIE[s].resistance);
    SERIE[s].num = n;


    printf("\nDo you want to add another component?\n(1-YES 2-NO): ");
    scanf("%d",&a1);
    
    if (a1 == 2)  loop=0;

    while(loop=1){

        fflush(stdin);

        if (i>0){
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
                s++;
                n++;
                printf("\nIntroduce de resistance value of the component (%d): ",n);
                scanf("%f", &SERIE[s].resistance);
                SERIE[s].num = n;
                i++;
                continue;
            }

            else if (a2==2){
                p++;
                n++;
                printf("\nIntroduce de resistance value of the component (%d): ", n);
                scanf("%f", &PARALLEL[p].resistance);
                PARALLEL[p].num = n;
                i++;
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
    
    for (i=1; i<=s; i++)    ResT += (SERIE[i].resistance);          //suma de resistencias 

    for (i=1; i<=p; i++)    ResE += 1/(PARALLEL[i].resistance);     
    
    if(p>0){
        
        ResE = 1/(ResE);
        ResT = ResE+ResT;
    }

    AmpT = (voltT/ResT);
    
    for (i=1; i<=s; i++){                                          //valores de componentes en serie
        
        SERIE[i].current = AmpT;
        
        SERIE[i].voltage = (voltT/SERIE[i].resistance);
    }
    
    AmpE = AmpT;
    voltE = (voltT/ResE);                                            //valores de componentes Eq
    
    for (i=1; i<=p; i++){
        
        PARALLEL[i].voltage = voltE;
        
        PARALLEL[i].current = (AmpE/PARALLEL[i].resistance);         //valores de componentes en paralelo
    } 

    printf("\n\nThe total Voltage is: %.2f volts\n", voltT);        //imprimir valores del circuito
    printf("The total Resistance is: %.2f ohms\n", ResT);
    printf("The total Current is: %.2f amperes\n", AmpT); 

    printf("\nValues of the components in SERIES:\n");              // imprimir valores individuales de cada compunente
    for(i=1; i<=s; i++){

        printf("Component(%d): [V:%.1f][R:%.1f][I:%.1f]\n", SERIE[i].num, SERIE[i].voltage, SERIE[i].resistance, SERIE[i].current );
    }
    
    printf("\nValues of the components in PARALLEL:\n");
    for(i=1; i<=p; i++){

        printf("Component(%d): [V:%.1f][R:%.1f][I:%.1f]\n", PARALLEL[i].num, PARALLEL[i].voltage, PARALLEL[i].resistance, PARALLEL[i].current );
    }
}


// HACER UNA FUNCION QUE OBTENGA LA RES EQUIVALENTE, UNA DE RES TOTAL Y OTRA DE VALORES ABSOLUTOS