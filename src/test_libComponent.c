#include <stdio.h>

#include "libcomponent.h"

int main()
{
    
    int i,count = 0;
    float array[3];
    
    count = e_resistance(10,array);
    printf("Resistans satt till: 10\n");
    printf("Förväntat: %f\n",10.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");
    
    count = e_resistance(11.5,array);
    printf("Resistans satt till: 11.5\n");
    printf("Förväntat: %f\n",12.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");
    
    count = e_resistance(113,array);
    printf("Resistans satt till: 113\n");
    printf("Förväntat: %f %f\n",100., 12.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");
    
    count = e_resistance(1120,array);
    printf("Resistans satt till: 1120\n");
    printf("Förväntat: %f %f\n",1000., 120.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");
    
    count = e_resistance(1132,array);
    printf("Resistans satt till: 1132\n");
    printf("Förväntat: %f %f %f\n",1000.,120.,12.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");
    
    count = e_resistance(1398,array);
    printf("Resistans satt till: 1398\n");
    printf("Förväntat: %f %f %f\n",1200.,180.,18.);
    printf(" Uträknat: ");
    for(i=0;i<count;printf("%f ",array[i++]));
    printf("\n");

    return 0;
}
