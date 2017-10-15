/*
* Filename: main.c
* ----------------------------
* Description: Huvudprogram som innehåller funktioner för inmatning av nödvändiga värden samt funktionsanropningar
*			   till alla inkluderande bibliotek som krävs för att beräkna resistansen. Den här filen presentera även
*			   resultatet för användaren.
*
* Date: 2017-10-15
* Version: 1.0
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libcomponent.h"
#include "libresistance.h"
#include "libpower.h"
#include "main.h"

/*
* Function: main
* ----------------------------
* Frågan användaren efter nödvändiga värden för att beräkna resistansen som slutligen visas för användaren.
*/
int main()
{

	//Variabler och pekare
	int volt;
	float power;
	float resistance;
	char coupling_method;
	int number_components = 0;
	int number_replacement_resistors = 0;
	float* pointer_to_resistors;

	//Hämta spänningskällan (i volt)
	printf("Ange sp\x84nningsk\x84llan i V: ");
	volt = read_integer();
	printf("Volten som angavs \x84r: %d\n", volt);

	//Hämta kopplingsmetoden som kommer användas
	coupling_method = read_character();
	printf("Metoden som angavs \x84r: %c\n", coupling_method);

	//Hämta antalet komponenter som kommer användas
	number_components = read_multiple_integers();
	printf("Antal komponenter som angavs \x84r: %d\n", number_components);

	//Hämta vartdera resistors resistans i ohm
	pointer_to_resistors = reserve_resistors(number_components);

	//Beräkna den totala resistansen
	resistance = calc_resistance(number_components, coupling_method, pointer_to_resistors);
	if (resistance == -1)
		fprintf(stderr, "Invalid input.\n");

	//Beräkna effekten i watt
	power = calc_power_r(volt, resistance);

	//Allokerar plats för resistorerna
	float *pointer_replacement_resistors = malloc(number_components * sizeof(float));

	//Antalet ersättningsresistorer
	number_replacement_resistors = e_resistance(resistance, pointer_replacement_resistors);

	//Skriv ut resultatet
	printf("Ers\x84ttningsresistans:\n %.1f ohm\n", resistance);
	printf("Effekt:\n %.2f W\n", power);
	printf("Ers\x84ttningsresistanser i E12-serien kopplade i serie:\n");
	print_replacement_resistors(pointer_replacement_resistors, number_components);

	free(pointer_replacement_resistors);

    return 0;
}

/*
* Function: read_float
* ----------------------------
* Tillåter användaren att mata in ett flyttal som slutligen returneras.
* Returnerar: Ett flyttal (float)
*/
float read_float(void)
{
	float retval = 0.0;
	char ch = '\0';

	scanf("%f", &retval);
	while ((ch = getchar()) != EOF && ch != '\n');

	return retval;
}

/*
* Function: read_integer
* ----------------------------
* Tillåter användaren att mata in ett heltal som slutligen returneras.
* Returnerar: Ett heltal (integer)
*/
int read_integer(void) {

	int input_value;
	scanf("%d", &input_value);

	return input_value;
}

/*
* Function: read_integer
* ----------------------------
* Tillåter användaren att mata in flera heltal som slutligen returneras.
* Returnerar: Ett heltal (integer)
*/
int read_multiple_integers(void) {

	int input_value = 0;
	do {
		printf("Antal komponenter: ");
		scanf("%d", &input_value);
	} while (input_value <= 0);

	return input_value;
}

/*
* Function: read_character
* ----------------------------
* Tillåter användaren att mata in en karaktär som slutligen returneras.
* Returnerar: En karaktär (char)
*/
char read_character(void)
{
	char line[256];
	char ch;

	printf("Vilken koppling kommer anv\x84ndas? (S or P): ");
	do {
		if (fgets(line, sizeof line, stdin) != NULL) {
			ch = line[0];
		}
	} while (ch != 'S' && ch != 'P');

	return ch;
}

/*
* Function: reserve_resistors
* ----------------------------
* Allokerar minne för flyttal samt ber användaren att mata in uppgifter om en komponent (dess ohm)
* Returnerar: En pekare till minnet som hanterar datan om resistorerna
*/
float* reserve_resistors(int number_resistors) {

	float* pointer_to_resistor = malloc(number_resistors * sizeof(float));
	for (int i = 0; i < number_resistors; ++i) {
		printf("Komponent %d i ohm: ", i + 1);
		pointer_to_resistor[i] = read_float();
	}

	return pointer_to_resistor;
}

/*
* Function: print_replacement_resistors
* ----------------------------
* Skriver ut information om ersättningsresistorerna
*/
void print_replacement_resistors(float* values, int number_components)
{
	for (int i = 0; i < number_components; i++)
		if (values[i] > 0)
			printf("%.1f ", values[i]);

	printf("\n");
}
