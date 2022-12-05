//Esercizio File Binari

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2
#define V 5
#define S 20

struct data
{
	
	int giorno;
	char mese[S];
	int anno;
	
}typedef data;

struct studente 
{
	
	int matricola;
	char cognome[S];
	int voti[V];
	data nascita;
	
}typedef studente;

void carica(char FileIN, int);

int main()
{
	char FileIN = {"carica.txt"};
	
	carica(FileIN, N);
	
	return 0;
}

void carica(char FileIN, int dim)
{
	FILE *fp;
	
	int i;
	
	struct studente buffer;
	
	fp = fopen(FileIN, "w");
	if(fp != 0)
	{
		for(i = 0; i < dim; i++)
		{
			printf("Inserisci il matricola:\n");
			scanf("%d", &buffer.matricola);
			
			printf("\n");
			
			printf("Inserisci il cognome:\n");
			scanf("%s", buffer.cognome);
			
			printf("\n");
			
			
		}
		
	}
	
	
	
}

