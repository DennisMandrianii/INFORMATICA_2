/** ****************************************************************************************
* \mainpage <File Binari>
*
* @brief <Gestione dei file binari>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <Dennis Mandriani>
* @date <15/12/2022> 
* @version 1.0 <15/12/2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

#include <stdio.h>				// Libreria serve per le printf e scanf
#include <stdlib.h>				// Libreria serve per l'utilizzo di altre funzioni ex: limits.h
#include <string.h>				// Libreria per le stringhe

#define V 5						// V = Voti
#define S 20					// S = Caratteri 

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

/** ****************************************************************************************
* @brief <inserisce in coda n record con i dati richiesti all’utente. Se il file non esiste va creato e quindi effettuare l’inserimento>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @author <Dennis Mandriani>
* @version 1.0 <15/12/2022> <Descrivere le modifiche apportate>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

void inserisciRecord(char [], int);

int main()
{
	FILE *f1;
	char fileName[] = {"File.txt"};
	
}

void inserisciRecord(char fileName[], int numRecord)
{
	FILE *f1;

	int i = 0;
    struct studente buffer;

	f1 = fopen(fileName, "wb");

	if(f1 != 0)
	{
		printf("Inserisci la matricola:\n");
		scanf("%d", &buffer.matricola);

		printf("\n");

		printf("Inserisci il cognome:\n");
		scanf("%s", buffer.cognome);

		printf("\n");

		printf("Inserisci i voti:\n");
		for(i = 0; i < V; i++)
		{
			scanf("%d", &buffer.voti);
		}

		printf("\n");

		printf("DATA DI NASCITA:\n");
		printf("Inserisci il giorno:\n");
		scanf("%d", &buffer.nascita.giorno);

		printf("\n");

		printf("Inserisci il mese:\n");
		scanf("%d", &buffer.nascita.mese);

		printf("\n");


	}


}

