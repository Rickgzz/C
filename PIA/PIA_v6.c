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

void SumRes(float*, float*, int, int);
void ValSerie(float*, int);
void ValParallel(float*, float*, float*, float*, int);
void PrintValues(float, float, float, int, int);

int main(){

    float voltT, ResT=0, AmpT=0, voltE=0, ResE=0, AmpE=0;
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
    
    SumRes(&ResT, &ResE, p, s);
    AmpT = (voltT/ResT);
    ValSerie(&AmpT, s);
    ValParallel(&AmpE, &AmpT, &voltE, &ResE, p);
    PrintValues(voltT, ResT, AmpT, p, s);
}

void SumRes(float* rT, float* rE, int p, int s){       
    int i;

    for (i=1; i<=s; i++)    *rT += (SERIE[i].resistance);          
    for (i=1; i<=p; i++)    *rE += 1/(PARALLEL[i].resistance);

    if(p>0){          
  
        *rE = 1/(*rE);
        *rT += *rE;
    }
}

void ValSerie(float* aT, int s){
    int i;

    for (i=1; i<=s; i++){                                          
        
        SERIE[i].current = *aT;
        SERIE[i].voltage = (*aT*(SERIE[i].resistance));
    }
}

void ValParallel(float* aE, float* aT, float* vE, float* rE, int p){
    int i;

    if(p>0){                                                  
        *aE = *aT;
        *vE = (*aE)*(*rE);
    }
    
    for (i=1; i<=p; i++){
        PARALLEL[i].voltage = *vE;
        PARALLEL[i].current = (*vE/(PARALLEL[i].resistance));        
    } 
}       

void PrintValues(float vT, float rT, float aT, int p, int s){
    int i;

    printf("\n\nThe total Voltage is: %.2f volts\n", vT);       
    printf("The total Resistance is: %.2f ohms\n", rT);
    printf("The total Current is: %.2f amperes\n", aT); 

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