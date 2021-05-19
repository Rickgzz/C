#include "header.h"

void SumRes(float* rT, float* rE, int p, int s){                            //Obtain the Equivalent resistance and Total Resistance
    int i;

    for (i=1; i<=s; i++)    *rT += (SERIE[i].resistance);          
    for (i=1; i<=p; i++)    *rE += 1/(PARALLEL[i].resistance);

    if(p>0){          
  
        *rE = 1/(*rE);
        *rT += *rE;
    }
}

void ValSerie(float* aT, int s){                                              //Obtain all the individual values of components conected in series
    int i;

    for (i=1; i<=s; i++){                                          
        
        SERIE[i].current = *aT;
        SERIE[i].voltage = (*aT*(SERIE[i].resistance));
    }
}

void ValParallel(float* aE, float* aT, float* vE, float* rE, int p){        //Obtain all the individual values of components conected in parallel
    int i;

    if(p>0){                                                                //get Equivalent values       
        *aE = *aT;
        *vE = (*aE)*(*rE);
    }
    
    for (i=1; i<=p; i++){
        PARALLEL[i].voltage = *vE;
        PARALLEL[i].current = (*vE/(PARALLEL[i].resistance));        
    } 
}       

void PrintValues(float vT, float rT, float aT, int p, int s){                     //Print all the values
    int i;
    printf("\n---------------------------------------------");                     //Print total values

    printf("\n\nThe total Voltage is: %.2f volts\n", vT);       
    printf("The total Resistance is: %.2f ohms\n", rT);
    printf("The total Current is: %.2f amperes\n", aT); 

    printf("\n---------------------------------------------\n");

    printf("\nVoltage[V]  Resistance[R]  Current[I]\n");
    printf("\nValues of the components in SERIES:\n");                         //Print values in series
    for(i=1; i<=s; i++){

        printf("Component(%d): [V:%4.1f] [R:%4.1f] [I:%4.1f]\n", SERIE[i].num, SERIE[i].voltage, SERIE[i].resistance, SERIE[i].current );
    }
    
    if (p>0){

        printf("\nValues of the components in PARALLEL:\n");                    //Print values parallel
        for(i=1; i<=p; i++){

            printf("Component(%d): [V:%4.1f] [R:%4.1f] [I:%4.1f]\n", PARALLEL[i].num, PARALLEL[i].voltage, PARALLEL[i].resistance, PARALLEL[i].current );
        }
    }
    printf("\n---------------------------------------------\n");

}
