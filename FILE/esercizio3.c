//Esercizio 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
		
	char FileIN[] = {"caratteri.txt"};
	
	//Contatori
											
	int righe = 1;
	int caratteri = 0;
	int parole = 0;
	
	FILE *pfIN;
	
	char appoggio;
	
	pfIN = fopen(FileIN, "r");	//lettura del file

	if(pfIN != 0 )		     	//controllo errori all'apertura del file
	{
		while(!feof(pfIN))			
			
		{
			appoggio = fgetc(pfIN);	
													
			if(appoggio == '.' || appoggio == ','  || appoggio == ';'  || appoggio == '?' || appoggio == '!') 	//controlla che i caratteri siano parole
			{
				parole++;			
			}
			
			if(appoggio != ' ' && appoggio != '\n')								
			{
				caratteri++;						//incrementa il contatore caratteri
			}
			if(appoggio == '\n' )								//controlla che siano presenti le righe
			{
			
				righe++;								//incrementa il contatore righe
			}	
		}	
		
		printf(" Le parole sono: %d\n I caratteri sono: %d\n Le righe sono: %d", parole, caratteri, righe);	
	}
}

