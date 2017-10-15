/*
 *  File: component.c
 *  Author: Jonah Ekelund
 *  
 */

int e_resistance(float orig_resistance, float *res_array)
{
    float e12Series[37] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100\
                        , 120, 150, 180, 220, 270, 330, 390, 470, 560, 680, 820, 1000\
                        , 1200, 1500, 1800, 2200, 2700, 3300, 3900, 4700, 5600, 6800, 8200, 10000};
    int count=0;
    int runOK = 1;
    int i;
    do{
        for(i=36; orig_resistance-e12Series[i]<=0 && i>=0;i--);
        if(orig_resistance-e12Series[i]>=0)
        {
            if(count == 2)
            {
               if(orig_resistance-e12Series[i]>e12Series[i+1]-orig_resistance)
                   i++;
            }
            orig_resistance = orig_resistance-e12Series[i];
            *res_array=e12Series[i];
            res_array++;
            count++;
        } 

       
    }while(i>=0&&count<3);
    return count;
    }
