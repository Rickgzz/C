#include <stdio.h>
#define MAX 50


struct SERIE{

    float resistance, voltage, current;

} SERIE[MAX];

struct PARALLEL{

    float resistance, voltage, current;

} PARALLEL[MAX];


int main(){

    float voltT, ResT, ResE, AmpT;
    int a1, a2, loop;
    int p=0, s=1, i=0, n=1;

    printf("\nPIA calculator\n\n");

    printf("Circuit Voltage: ");
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Introduce resistance value [1] component: ");
    scanf("%f", &SERIE[s].resistance);

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
            n++;
            printf("\nHow is conected your component with the previous one?\n(1-SERIES 2-PARALLEL): ");
            scanf("%d",&a2);

            if (a2==1){
                s++;
                printf("\nIntroduce de resistance value of the [%d] component: ",n);
                scanf("%f", &SERIE[s].resistance);
                i++;
                continue;
            }

            else if (a2==2){
                p++;
                printf("\nIntroduce de resistance value of the [%d] component: ", n);
                scanf("%f", &PARALLEL[p].resistance);
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
    
    for (i=1; i<=s; i++){
        
        ResT += (SERIE[i].resistance);
    }
    
    printf("\nvalor de p: %d\n",p);

    for (i=1; i<=p; i++){
        
        ResE += 1/(PARALLEL[i].resistance);     // HACER UNA FUNCION QUE OBTENGA LA RES EQUIVALENTE, UNA DE RES TOTAL Y OTRA DE VALORES ABSOLUTOS
    }

    ResE = 1/(ResE);
    ResT = ResE+ResT;

    AmpT = (voltT/ResT);

    printf("\n\nThe total Voltage is: %.2f\n", voltT);
    printf("The total Resistance is: %.2f\n", ResT);
    printf("The total Current is: %.2f\n", AmpT); 
}