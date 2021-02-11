#include <stdio.h>

main ( )
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;

    printf("CELSIUS A FAHRENHEIT\n");

    while (celsius <= upper) {
        fahr = ((9*celsius)/5)+32 ;
        printf("%6.0f %12.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

}

/*printf("%d\t%d\n", fahr, celsius);*/
/*printf("%3d %6d\n", fahr, celsius);*/