#ifndef MAIN_H
#define MAIN_H

int read_integer();
int read_multiple_integers();
char read_character();
float read_float();
float* reserve_resistors(int number_resistors);
void print_replacement_resistors(float* values, int number_components);

#endif