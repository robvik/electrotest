/*
 *  File: component.c
 *  Author: Jonah Ekelund
 *
 */
#include <stdio.h>

/*
 * Function: e_resistance
 * ----------------------------------
 *  Beräknar vilka resisitoerer i E-12 seriend (mellan 10 
 *  till 10000 ohm) som kan ersätta orig_resistance, max 
 *  3 stycken.
 *
 *  return: (int) antalet resistander i arrayen res_array
 */
int e_resistance(float orig_resistance, float *res_array)
{
    //E-12 serien deklarerad som en const array
    const float e12Series[37] = { \
        10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100, \
        120, 150, 180, 220, 270, 330, 390, 470, 560, 680, 820, 1000, \
        1200, 1500, 1800, 2200, 2700, 3300, 3900, 4700, 5600, 6800, 8200, 10000};

    int count=0;//Return variablen
    int i=0;//En counter vairiabel som används internt
    int i_old = 0;

    //Sätter alla värden i res_array till noll
    for(i=2;i>=0; res_array[i--]=0);
    do{
        i_old = i;
        //Går uppifrån i e-12 arrayen och hittar 
        //första värdet då orig_resistance - e12Series[i] 
        //inte är mindre än noll
        for(i=36; orig_resistance-e12Series[i]<0 && i>=0;i--);

        if(i>=0)
        {        
            orig_resistance = orig_resistance-e12Series[i];

            //Sparar in resistansen i output arrayen
            *res_array=e12Series[i];
            res_array++;
            count++;
        }

    }while(i>=0&&count<3);//Loppar medans antallet resistorer är mindre än 3 eller i inte gått ner till 0 

    //Kollar på sista valda resistorn om det blir närmare
    //korrekt värde istället ta en med ett snäpp högre värde    
    orig_resistance = orig_resistance+e12Series[i_old];
    if(orig_resistance-e12Series[i_old] > e12Series[i_old+1]-orig_resistance) 
        *(--res_array)=e12Series[i_old+1];

    return count;
}
