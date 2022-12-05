//Esercizio 2

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char FileIN[] = {"filein.txt"};	
	char FileOUT[] = {"fileout.txt"};
	
	FILE *pfIN;					//puntatore al file di input	
	FILE *pfOUT;				//puntatore al file di output
	
	char appoggio;
	
	pfIN = fopen(FileIN, "r");		//apertura file in modalità lettura
	pfOUT = fopen(FileOUT, "w");	//aperura file in modalità scrittura	
	
	if(pfIN != 0 && pfOUT != 0)		//verifica se non ci sono errori all'apertura file
	{
		while(!feof(pfIN))
		{
			appoggio = fgetc(pfIN);	
			fputc(appoggio, pfOUT);
		}
		
		fclose(pfIN);
		fclose(pfOUT);
	}
}
