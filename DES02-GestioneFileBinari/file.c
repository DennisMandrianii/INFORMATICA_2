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

/** ****************************************************************************************
* @brief <inserisce in coda n record con i dati richiesti all’utente. Se il file non esiste va creato e quindi effettuare l’inserimento>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author <autore>
* @version 1.0 <data> <Descrivere le modifiche apportate>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

void inserisciRecord(char [], int);

int main()
{
	
}

void inserisciRecord(char fileName[], int numRecord)
{

}

