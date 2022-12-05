//Esercizio 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char FileIN[] = {"numeri.txt"}; 								 
	char FileOUT[] = {"pari.txt"};	
	char FileOUT1[] = {"dispari.txt"};

	char appoggio;

	FILE *pfin;
	FILE *pfout;
	FILE *pfout1;


	pfin = fopen(FileIN, "r");
    pfout = fopen(FileOUT, "w");
	pfout1 = fopen(FileOUT1, "w");


	if(pfin != 0 && pfout != 0 && pfout1 != 0)
	{
		while((appoggio = getc(pfin)) != EOF)
	{
		if(appoggio != ' ')
		{
			if(appoggio%2 == 0)
			{
				fputc(appoggio, pfout);
				fputc(' ', pfout); 	
			}
			else
			{
				fputc(appoggio, pfout1);
				fputc(' ', pfout1);
			}
		}
	}
		fclose(pfin);
		fclose(pfout);
		fclose(pfout1);
	}
}
