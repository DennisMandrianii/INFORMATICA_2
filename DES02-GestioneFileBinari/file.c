/**************************************************************************************************************
* @brief GESTIONE DEI FILE BINARI                                                                             *                                                      
* @author Dennis Mandriani 4^H                                                                                *
* @date 21/12/2022		                                                                              *						                                                          *
/*************************************************************************************************************/

//inclusione delle librerie

#include <stdio.h>       //Input e Output
#include <stdlib.h>	    //Serve per la funzione System
#include <string.h>     //Serve per le stringhe

//define
#define S 50            //costante  utilizzata per definire spazio delle stringhe
#define V 8             //costante usata per l'array voti contenuto in struct studente
#define MAX 50          //costante con 50 utilizzata per definire spazio delle stringhe contenenti il nome del file

//Dichiarazione degli Struct 

struct data              //struct data contiene informazioni sulla data di nascita
{
    int giorno;
    char mese[S];
    int anno ;

}typedef data;

//dichiarazione dei campi di struct studente

struct studente        
{
    int matricola;
    char cognome[S];
    int voti[V];
    data nascita;

}typedef studente;

//dichiarazione delle funzioni

/** ****************************************************************************************
* @brief <La funzione inserisciRecord inserisce le informazioni all'interno del record e le scrive nel file>
* @param <una stringa e un intero(char fileName[] sarebbe il file inserito, int numRecord)>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022> 
*******************************************************************************************/

int inserisciRecord(char fileName[], int numRecord);

/** ****************************************************************************************
* @brief<La funzione stampaFile stampa sul monitor le informazioni di tutti i record presenti>
* @param <n.1 stringa (char fileName[] sarebbe il file inserito)>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022> 
*******************************************************************************************/

int stampaFile(char fileName[]);          

/** ****************************************************************************************
* @brief <La funzione ricercaRecord controlla che il record abbia il campo cognome uguale al parametro cognome, stampando in seguito età e media dei voti>
* @param <n.2 stringhe (char fileName[] sarebbe il file inserito, char cognome[]) cognome che inserisce l'utente>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022> 
*******************************************************************************************/
         
int ricercaRecord(char fileName[], char cognome[]);  

/** ****************************************************************************************
* @brief <La funzione stampaRecord Stampa le informazioni presenti nel record dando la posizione>
* @param <n.1 stringa e un intero  (char fileName[] sarebbe il file inserito, int posizione)>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022> 
*******************************************************************************************/

int stampaRecord(char fileName[], int posizione);   

/******************************************************************************************
* @brief <La funzione correggiRecord Visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l’intero record, con i nuovi dati richiesti all’utente>
* @param <n.1 stringa e un intero (char fileName[] sarebbe il file inserito, int posizione)>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022> 
*******************************************************************************************/

int correggiRecord(char fileName[], int posizione); 

/******************************************************************************************
* @brief <La funzione numeroRecordRestituisce il numero di record presenti nel file>
* @param <n.1 stringa  (char fileName[] sarebbe il file inserito)>
* @author <Dennis Mandriani>
* @version 1.0 <21/12/2022>
*******************************************************************************************/

int numeroRecord(char fileName[]);

int main()
{
    //dichiarazione variabili

    FILE *f1;                                   //puntatore al file

    char NomeFile[MAX] = {"file.txt"};           //stringa usata per contenere il nome del file 
    int r;                                      //usata per richiamare funzioni di tipo int
    int pos;                                    //usata per la posizione del record
    int scelta;                                 //usata per fare una scelta all'interno del menù dello switch case
	char stringa [S];                           //usata come parametro cognome all'interno delle funzioni
    int s;
	
    //funzione n.1

	printf("Inserisci il numero di studenti:\n");
	scanf("%d",&pos);
	
    inserisciRecord(NomeFile,pos); 

    //funzione n.2

    stampaFile(NomeFile);

    //funzione n.3
             
    printf("Inserisci il cognome per effetuare la ricerca:\n");
    scanf("%s", stringa);
            
    printf("\n");
                        
    r = ricercaRecord(NomeFile, stringa);          
    printf("Posizione: %d\n", r);

    //funzione  n.4

    printf("Inserisci il numero di posizione del record per stamparlo:\n");    
    scanf("%d", &pos);
                        
    r = stampaRecord(NomeFile, pos);
                        
    if(r == 0)        //controllo se il record è stato trovato la funzione restituisce 0
    {
        printf("Record Trovato!\n");                    
    }                  
    else
    {
        printf("Errore nell'apertura\n");
    }
                
    //funzione n.5       

    printf("Inserisci la posizione del record da modificare:\n");
    scanf("%d", &pos);
                                
    printf("\n");
                                
    r = correggiRecord(NomeFile, pos);

    //funzione n.6
    
    r = numeroRecord(NomeFile);
    printf("Numero: %d\n", r);

    return 0;
}

void inserisciRecord(char fileName[], int numRecord) // fwrite
{
    FILE *f1;                           //puntatore al file
    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente
    int j, i;                           //Servono per i cicli For

    f1 = fopen(fileName, "wb");            //apertura del file binario in scrittura
                                                   
    if(f1 != NULL)                        //controllo degli errori sull apertura file
    {
        for(i = 0; i < numRecord; i++)
       { 
            //inserimento di tutti i campi di struct data e studente

            printf("Inserisci matricola:\n");
            scanf("%d", &buffer.matricola);

            printf("\n");

            printf("Inserisci cognome:\n");
            scanf("%s", buffer.cognome);

            printf("\n");

            printf("Inserisci i voti:\n");
            for(j = 0; j < V; j++)
            {
                scanf("%d", &buffer.voti[j]);
            }
            
            printf("\n");
            
            printf("Inserisci giorno:\n");
            scanf("%d", &buffer.nascita.giorno);
            
            printf("\n");

            printf("Inserisci mese:\n");
            scanf("%s", &buffer.nascita.mese);
            
            printf("\n");

            printf("Inserisci anno:\n");
            scanf("%d", &buffer.nascita.anno);
            
            printf("\n");

            fwrite(&buffer,sizeof(struct studente),1,f1);   //con fwrite scrivo tutti i campi richiesti sopra sul file.										
		}
        
		fclose(f1);                                         //chiusura file
    }
    else                                                 
    {
        printf("Error 404 File Not Found");
    }
}

void stampaFile(char fileName[])
{
    FILE *f1;                           //puntatore al file
    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente
    int j, n;

    f1 = fopen(fileName, "rb");            //apertura del file binario in lettura

    if(f1 != NULL)                        //controllo degli errori sull apertura file
    {
        while(!feof(f1))                //ripete finchè non è finito il file
        {   
            n = fread(&buffer, sizeof(struct studente), 1, f1);      //lettura del file
            
            if(n > 0)                    //controllo se il file è stato letto
            {
                //stampa di tutti i campi di struct data e studente

                printf("Matricola: %d\n", buffer.matricola);
                
                printf("\n");

                printf("Cognome: %s\n", buffer.cognome);
                
                printf("\n");

                for(j = 0; j < V; j++)
                {
                    printf("Voti: %d\t", buffer.voti[j]);   
                }
                
                printf("\n");
                
                printf("Giorno: %d\n", buffer.nascita.giorno);
                
                printf("\n");

                printf("Mese: %s\n", buffer.nascita.mese);
                
                printf("\n");

                printf("Anno: %d\n", buffer.nascita.anno);
            }      
    }
}
    else                        //se non è  possibile aprire il file da un messaggio di errore
    {
        printf("impossibile aprire");
    }

	fclose(f1);                 //chiusura del file
}

int ricercaRecord(char fileName[], char cognome[]) //se esistono più cognomi restituisco la posizione dell'ultimo trovato
 {
    FILE *f1;                           //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente
    int j = 0, c = 0, pos = 0, n, s, m = 0;

    f1 = fopen(fileName, "rb");            //apertura del file binario in lettura

    if(f1 != NULL)                        //controllo degli errori sull apertura file
    {
        while(!feof(f1))                //finchè non finisce il primo file
         {
            n = fread(&buffer,sizeof(struct studente), 1, f1);    //lettura del file di record
            c++;                                              //incremento contatore
            
            if(n > 0)                    //controllo che il file è stato letto
            {
            	 if(strcmp(buffer.cognome, cognome) == 0)       //restituisce 0 se le due stringhe sono uguali
		        {
		            pos = c, s = 0;                              
		
		            printf("Cognome: %s\n", buffer.cognome);
		                
		            printf("\n");
                                 
		            for(j=0;j<V;j++)                        
		            {
		                s += buffer.voti[j];                 //somma dei voti  
		            }

		            m = s/V;                                  //calcolo media

                    //stampa della media e età

		            printf("Media: %d\n", m);
		                
		            printf("\n");
		
		            printf("Giorno: %d\n", buffer.nascita.giorno);
		                
		            printf("\n");
		
		            printf("Mese: %s\n", buffer.nascita.mese);
		                
		            printf("\n");
		
		            printf("Anno: %d\n", buffer.nascita.anno);
		                
		            printf("\n");
				}
			}
         }
		fclose(f1);            
    }
    else                        
        printf("Error 404 File Not Found");
    }

    return pos;                                         //restituisce la posizione del record

}

int stampaRecord(char fileName[], int posizione) 
{
    FILE *f1;                           //puntatore al file
    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente
    int r, n, j = 0;

    f1 = fopen(fileName, "rb");            //apertura del file binario in lettura

    if(f1 != NULL)                       //controllo degli errori sull apertura file
    {      
         r = fseek(f1, posizione * sizeof(struct studente), SEEK_SET);    //uso fseek per posizionarmi sullo struct 
         
            if(r == 0)                                                //controllo errori fseek
            {
                n = fread(&buffer, sizeof(struct studente), 1, f1);  //lettura file

                if(n > 0)                                         //controllo che il file è stato letto
                {
                    printf("Matricola: %d\n", buffer.matricola);

                    printf("Cognome: %s\n", buffer.cognome);

                    for(j = 0; j < V; j++)
                    {
                        printf("Voti: %d\n", buffer.voti[j]);
                    }

                    printf("Giorno: %d\n", buffer.nascita.giorno);
                    printf("Mese: %s\n", buffer.nascita.mese);
                    printf("Anno: %d\n", buffer.nascita.anno);
                    }

					return 0;                        //return 0  se il record è stato trovato                 
              	}
              	
              	fclose(f1);                           
	}
    else                                               
    {
        printf("impossibile aprire");
    }

	return -1;                                      //return -1 se il record non è stato trovato
}

int correggiRecord(char fileName[], int posizione)
{

    FILE *f1;                           //puntatore al file
    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente
    int j = 0, r, pos;

    f1 = fopen(fileName, "rb");            //apertura del file binario in lettura

    if(f1 != NULL)                        //controllo degli errori sull apertura file
    {   
        r = fseek(f1, posizione * sizeof(struct studente), SEEK_SET); //uso fseek per posizionarmi sullo struct 

        if(r == 0)                        //controllo errori fseek
        {
            //stampa del record tramite posizione

            printf("inserisci la posizione del record da stampare");
            scanf("%d", &pos);

            stampaRecord(fileName,pos);

            //correzione del record tramite dati richiesti all'utente

            printf("Inserisci matricola:\n");
            scanf("%d", &buffer.matricola);

            printf("\n");

            printf("Inserisci cognome:\n");
            scanf("%s", buffer.cognome);

            printf("\n");

            printf("Inserisci voti:\n");
            for(j = 0; j < V; j++)
            {
                scanf("%d", &buffer.voti[j]);
            }

            printf("Inserisci il giorno di nascita:\n");
            scanf("%d", &buffer.nascita.giorno);

            printf("\n");

            printf("Inserisci  il mese di nascita:\n");
            scanf("%s", &buffer.nascita.mese);

            printf("\n");

            printf("Inserisci anno di nascita\n");
            scanf("%d", &buffer.nascita.anno);

            r = fseek(f1, posizione * sizeof(struct studente), SEEK_SET);     //con fseek mi posiziono sul record da correggere
            
            fwrite(&buffer,sizeof(struct studente),1,f1);               //scrittura su file dei campi inseriti sopra
        }
        fclose(f1);                                               //chiusura file
    }
    else                                                            
    {
        printf("Error 404 File Not Found");
    }

}

int numeroRecord(char fileName[])
{
	struct studente buffer;							    //dichiarazione di un record
	int r;			                                    
	int n = sizeof(buffer);
	int numerorecord;								    //numero record presenti

	FILE* f1;											//puntatore al file
	
	f1 = fopen(fileName, "rb");						    //apertura del file binario in lettura
	
	if(f1 != NULL)										//se il file si apre
	{
		r = fseek(f1, 0, 2);								//posiziona il punatore alla fine del file

		r = ftell(f1);									//restituisce un intero che é la posizione corrente del puntatore.
		
		numerorecord = r/n;								//divido r e n per trovare il numero di record
		
		fclose(f1);									    //chude il file
		
		return numerorecord;							//restituisce il numero di record
	}
	else												
	{
		printf("Error 404 File Not Found");                             
	}
}
