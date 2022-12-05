#include <stdio.h>
#include <stdlib.h>

int main()
{
	char FileIN[] = {"nomi.txt"};
	char FileOUT[] = {"nomiOut.txt"};
	int c;
	
	FILE *pfIN;
	FILE *pfOUT;	
						
	pfIN = fopen(FileIN, "r");				// fopen apre il file; "r" = serve per la lettura del file								
	pfOUT = fopen(FileOUT, "w");
			
	while(!feof(pfIN))
	{
		c = fgetc(pfIN);
		fputc(c, pfOUT);
	}
	
	printf("Programma terminato \n");
	fclose(pfIN);			//Chiusura file
	fclose(pfOUT);
	
	
	system("PAUSE");
}
