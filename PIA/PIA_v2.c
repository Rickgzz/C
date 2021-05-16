#include <stdio.h>
#define MAX 50


struct resistencias{

    float valueS, valueP;

} resistencias[MAX];

int main(){
    float voltT, ResT=1, AmpT=2;
    int a1, a2, loop, r1, rn;
    int i =0, i2=0, j=0, n=1;
    int rvals[MAX];
    
    printf("PIA calculator\n\n");

    printf("Circuit Voltage: ");
    scanf("%f",&voltT);
    fflush(stdin);

    printf("Introduce resistance value [1] component: ");
    scanf("%f", &resistencias[n].valueS);

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
                printf("\nIntroduce de resistance value of the [%d] component: ",n);
                scanf("%f", &resistencias[n].valueS);
                i++;
                continue;
            }

            else if (a2==2){
                printf("\nIntroduce de resistance value of the [%d] component: ", n);
                scanf("%f", &resistencias[n].valueP);
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

    printf("\n\nThe total Voltage is: %.2f\n", voltT);
    printf("The total Resistance is: %.2f\n", ResT);
    printf("The total Current is: %.2f\n", AmpT); 
}