#include <stdio.h>
#include <stdlib.h>

int main()
{
	char File[] = {"nomi.txt"};
	int err, c;
	
	FILE *puntofile;						
	puntofile = fopen(File, "r");				// fopen apre il file; "r" = serve per la lettura del file				
									
	while(!feof(puntofile))
	{
			c = fgetc(puntofile);
			printf("%c", c);
	}

	printf("\n");
	fclose(puntofile);			//Chiusura file
	
	
	system("PAUSE");
}
