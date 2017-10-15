#ifndef __COMPONENT_H__
#define __COMPONENT_H__


/*
 * Function: e_resistance
 * ----------------------------------
 *  Beräknar vilka resisitoerer i E-12 seriend
 *  som kan ersätta orig_resistance, max 3 stycken
 *
 *  return: (int) antalet resistander i arrayen res_array
 */
int e_resistance(float orig_resistance, float *res_array);


#endif
