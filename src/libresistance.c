/*
* Filename: libresistance.c
* ----------------------------
* Description: Innehåller funktion för att beräkna den resistanser.
* Author: Robin Viktorsson
* Date: 2017-10-15
* Version: 1.0
*/

#include <stdio.h>
#include "libresistance.h"

/*
* Function: calc_resistance
* ----------------------------
*   Returnerar den total resistansen för olika kopplade resistanser.
*	Resistanserna kan kopplas parallellt eller i serie.
*
*   count = antal komponenter (resistorer)
*   conn = kopplingsmetoden som ska användas
*	array = innehåller resistansen för alla komponenter (resistorer)
*
*   Returnerar: Den totalt beräknade resistansen.
*/
float calc_resistance(int count, char conn, float *array)
{
	//Variabel
	float resistance = 0;

	//Om arrayn är tom finns det ingen anledning att fortsätta
	if (array == 0)
		return -1;

	//Låt oss beräkna resistansen
	if (conn == 'S') //Om det är en seriekoppling
	{	
		for (int i = 0; i < count; i++) //Iterera igenom alla komponenter
			resistance += array[i]; //Och addera/summera deras resistans 
	}
	else if (conn == 'P') //Om det är en parallellkoppling
	{ 		
		for (int i = 0; i < count; i++) //Iterera igenom alla komponenter
		{
			if (array[i] == 0) //Returnera 0 om resistansen är 0 eftersom float/0 = inf
				return 0;
			
			resistance += 1.0 / array[i]; //Och adderar deras resistans
		}
		resistance = 1.0 / resistance;
	}
	else //Om det varken är P eller S så har någonting blivit fel
		return -1;

	return resistance;
}