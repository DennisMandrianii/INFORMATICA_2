#include <stdio.h>
#include <stdlib.h>

int main()
{
	char FileIN[] = {"nomi.txt"};
	char FileOUT[] = {"nomiMaiuscoli.txt"};
	char appoggio;

	
	FILE *pfIN;
	FILE *pfOUT;
	
	pfIN = fopen(FileIN, "r");
	pfOUT = fopen(FileOUT, "w");
	
	if(pfIN != 0 && pfOUT != 0)
	{
		while(!feof(pfIN))
		{
			appoggio = fgetc(pfIN);
			
			if(appoggio >= 'a' && appoggio <= 'z')
			{
				appoggio -= 32;
			}			
			appoggio = fputc(appoggio, pfOUT);
		}
		
		fclose(pfIN);
		fclose(pfOUT);
	}
}
