#include <stdio.h>
#define MAX 80


int main() {

    int n, choice, i, r1;
    int sel; 
    float resT, inv_resT, ampT, voltT;
    int resPar[MAX];
    

    printf("PIA calculator\n");

    printf("Voltaje inical: ");
    scanf("%f",&voltT);

    printf("Enter first resistance value: ");
    scanf("%d", &r1);

    printf("Do you want to add another component? 1-YES 2-NO: ");
    scanf("%d",&sel);

    while(sel != (1 || 2)) {
        printf("Error, try again\n");
        printf("Do you want to add another component? 1-YES 2-NO: ");
        scanf("%d",&sel);
    }

    if (sel==1){

        printf("How is conected with the last component? 1-SERIE 2-PARALLEL: ");
        scanf("%d", &choice);

        while (choice != (1 || 2)) {
            printf("Error, try again\n");
            printf("How is conected with the last component? 1-SERIE 2-PARALLEL: ");
            scanf("%d", &choice);
        }

        if(choice==1) {             //SERIE
            
            print("value of (R%d): ", conteo de resistencias);
            scanf("%d",&r);
            
            for(i=0; i<n; i++) {
                resT+=r[i];
            }   
            amp= (voltT/resT);
        }
    }
    
    else if (sel==2)
    

    return(0);  
}

printf("How many resistors are there: ");
    scanf("%d", &n);
    printf("\n");

    double r[n];

    for(i=0; i<n; i++) {
        printf("Resistor %d: ", i+1);
        scanf("%lf", &r[i]);
    }
    
    

    else if(choice==2) {        //PARALELO
        for(i=0; i<n; i++){
            inv_res_tot+=(1/r[i]);
        }

        res_tot=(1/inv_res_tot);

        amp= (volt/res_tot);
    }   


    printf("\nThe total:\n(Resistance is: %.2f Ohms) (Voltaje is: %.2f Volts) (Current is: %.2f Amperes)\n", res_tot, volt, amp);

return(0);  
}
