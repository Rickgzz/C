#include <stdio.h>
#define MAX 50


main(){

    int a1, a2, loop, voltT, r1,rn, ResT=1, AmpT=2;
    int i =0, i2=0, j=0;
    int rvals[MAX];
    
    printf("PIA calculator\n\n");

    printf("Circuit Voltage: ");
    scanf("%d",&voltT);

    printf("Component 1 resistance value: ");
    scanf("%d", &r1);

    printf("\nDo you want to add another component?\n(1-YES 2-NO): ");
    scanf("%d",&a1);
    
    if (a1 == 2){
            loop=0;
        }

    while(loop=1){

        if (i>0){
            printf("\nDo you want to add another component?\n(1-YES 2-NO):");
            scanf("%d",&a1);
        }

        if (a1 == 2){
            break;
        }

        else if(a1 == 1){
            
            printf("\nHow is conected your component with the previous one?\n(1-SERIES 2-PARALLEL): ");
            scanf("%d",&a2);

            if (a2==1){
                printf("Introduce de resistance value of the component:\n");
                scanf("%d",&rn);
                i++;
                continue;
            }

            else if (a2==2){
                printf("Introduce de resistance value of the component:\n");
                scanf("%d",&rn);
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


    printf("\n\nThe total Voltage is: %d\n", voltT);
    printf("The total Resistance is: %d\n", ResT);
    printf("The total Current is: %d\n", AmpT); 

}
