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