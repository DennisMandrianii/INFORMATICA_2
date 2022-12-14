/***********************************************************
                   Dennis Mandriani              
 						4H                     
 					20/09/2022             
 ************************************************************/ 
 
 // Dichiarazione Librerie
 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <limits.h>			 // Contiene le costanti INT MAX INT MIN
 #include <time.h> 			    //  Serve per generare i numeri casualmente
 
 // Dichiarazioni Costanti
 
 #define N 5				 // Dimensione del vettore: grandezza e' di cinque caselle
 #define R 3                //  Lunghezza della riga in questo caso tre
 #define C 3               //   Altezza della colonnna in questo caso tre
 #define max 20           //    Numero massimo generabile casualmente
 #define min 5           //     Numero minimo generabile casualmente
 
 // Funzioni
  
 void caricaRandomVettore(int [], int); 
 void caricaRandomMatrice(int [][C], int, int); 
 void caricaTastiera(int [], int); 
 void caricaTastieraMatrice(int [][C], int); 
 void Stampa(int [], int); 
 void StampaMatrice(int [][C], int, int); 
 void OrdinamentoBubbleSort(int [], int); 
 int  RicercaIngenua(int [], int); 
 int MaggioreMatrice(int [][C], int, int); 
 int MinoreMatrice(int [][C], int, int); 
 void caricaRandomColonna(int [][C], int, int); 
 void caricaTastieraColonna(int [][C], int, int); 
 void StampaColonna(int [][C], int, int); 
 int RicercaColonna(int [][C], int, int, int); 
 
 // Inizio del main
  
 int main() 
 { 
         int vettore[N]; 
         int matrice[R][C]; 
         int risultato, a, b; 
          
         srand(time(NULL)); 
          
         printf("Generazione di numeri casuali:\n"); 
         caricaRandomMatrice(matrice, R, C); 
         StampaMatrice(matrice, R, C); 
          
         printf("\n\n"); 
          
         printf("Inserisci dei numeri:\n"); 
         caricaTastieraMatrice(matrice, C); 
         StampaMatrice(matrice, R, C); 
          
         printf("\n"); 
          
         OrdinamentoBubbleSort(vettore, N); 
         Stampa(vettore, N); 
          
         printf("\n"); 
          
         RicercaIngenua(vettore, N); 
         Stampa(vettore, N); 
          
         printf("\n"); 
          
         risultato = MaggioreMatrice(matrice, R, C); 
         printf("%d", risultato); 
          
         printf("\n"); 
          
         risultato = MinoreMatrice(matrice, R, C); 
         printf("%d", risultato); 

         printf("\n");

         printf("Inserisci la colonna su cui vuoi caricare la matrice:\n"); 
         scanf("%d", &a); 
         caricaRandomColonna(matrice, R, a); 
         StampaMatrice(matrice, R, C); 

         printf("\n");

         printf("Inserisci la colonna che vuoi stampare:\n"); 
         scanf("%d", &a); 
         StampaColonna(matrice, R, a); 

         printf("\n");

         printf("Inserisci la colonna dove effettuare la ricerca e il numero da cercare:\n"); 
         scanf("%d %d", &a, &b); 
         risultato = RicercaColonna(matrice, R, a, b); 
         printf("Posizione\t:" "%d", risultato);
          
 } 
  
 void caricaRandomVettore(int v[], int x)  // x = dimensione 
 { 
         int i; 
          
 //        srand(time(NULL)); 
         
         for(i = 0; i < x; i++) 
         { 
                 v[i] = rand()%(max - min + 1)+ min; 
         } 
         
 } 
  
 void caricaRandomMatrice(int m[][C], int righe, int colonne) 
 { 
         int i; 
          
         for(i = 0; i < colonne; i++) 
         { 
                 caricaRandomVettore(m[i], colonne); 
         } 
 } 
  
 void caricaTastiera(int v[], int x) 
 { 
         int i; 
          
         for(i = 0; i < x; i++) 
         { 
                 scanf("%d", &v[i]);         
         } 
 } 
  
 void caricaTastieraMatrice(int m[][C], int colonne) 
 { 
         int i; 
          
         for(i = 0; i < colonne; i++) 
         { 
                 caricaTastiera(m[i], colonne); 
         } 
 } 
  
 void Stampa(int v[], int x) 
 { 
         int i; 
          
         for(i = 0; i < x; i++) 
         { 
                 printf("%d ", v[i]); 
         } 
         
         printf("\n");
 } 
  
 void StampaMatrice(int m[][C], int righe, int colonne) 
 { 
         int i; 
          
         for(i = 0; i < colonne; i++) 
         { 
                 Stampa(m[i], colonne); 
         } 
 } 
  
 void OrdinamentoBubbleSort(int v[], int x) 
 { 
         int appoggio = 0, scambio, i; 
          
         do{ 
                  
                 scambio = 0; 
                  
                 for(i = 0; i < x - 1; i++) 
                 { 
                         if(v[i] > v[i + 1]) 
                         { 
                                 appoggio = v[i]; 
                                 v[i] = v[i + 1]; 
                                 v[i + 1] = appoggio; 
                                 scambio = 1; 
                         } 
                          
                 } 
                  
           }while(scambio == 1); 
 } 
  
int RicercaIngenua(int v[], int x) 
 { 
         int indice = -1, i; 
          
         for(i = 0; i < x; i++) 
         { 
                  
                 if(v[i] == x) 
                 indice = i; 
                  
         }
		 return indice; 
 } 
  
 int MaggioreMatrice(int m[][C], int righe, int colonne) 
 { 
         int i, j, c = INT_MIN; 
          
         for(i = 0; i < righe; i++) 
         for(j = 0; j < colonne; j++) 
         {         
          
                 if(m[i][j] < c) 
                 { 
                         c = m[i][j];  //c puo' essere anche un altra lettera
                 } 
                  
         }
		 return c; 
 } 
  
 int MinoreMatrice(int m[][C], int righe, int colonne) 
 { 
         int i, j, c = INT_MAX; 
          
         for(i = 0; i < righe; i++) 
         for(j = 0; j < colonne; j++) 
         {         
          
                 if(m[i][j] > c) 
                 { 
                         c = m[i][j]; 
                 } 
                  
         }return c; 
          
 }
 
void caricaRandomColonna(int m[][C], int x, int y) 
 { 
         int i; 
  
         for(i = 0; i < x; i++) 
         { 
             m[i][y] = rand()%(max - min + 1)+ min; 
         } 
                  
 }
 
void caricaTastieraColonna(int m[][C], int x, int y) 
 {       
      int  i; 
     
      printf("inserisci un numero"); 
          
      for(i = 0; i < x; i++) 
      { 
           scanf("%d", &m[i][y]); 
      }         
          
 }
 
void StampaColonna(int m[][C], int x, int y) 
 { 
         int i; 
         for(i = 0; i < x; i++) 
         { 
                 printf("%d\n", m[i][y]); 
         } 
 }
 
int RicercaColonna(int m[][C], int x, int y, int z) 
 { 
         int i, indice = -1;
 
         for(i = 0; i < x; i++) 
         { 
                 if(m[i][y] == z) 
                 { 
                         indice = i; 
                 } 
         } 
          
         return indice;         
 }
