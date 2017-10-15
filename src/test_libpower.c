#include <stdio.h>
#include "libpower.h"

int main(void)
{
  printf("Voltage = 100 V, Resistance = 500, Resulting power = %f\n", calc_power_r(100., 500.));
  printf("Should've be 20\n");

  printf("Voltage = 100 V, Ampere = 0.5, Resulting power = %f\n", calc_power_i(100., 0.5));
  printf("Should be 10\n");

  return 0;
}
