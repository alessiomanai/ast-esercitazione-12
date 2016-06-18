#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#define MAX_CIFRE 4
#define RADICE_SIZE 10

    /***AST 12: confronto dei metodi di ordinamento

        L’obiettivo di questa esercitazione è quella di confrontare i
        vari tipi di ordinamento contando il numero di confronti e di
        scambi per diversi tipi di dati di input
        Valutare il tempo di esecuzione di ciascun algoritmo
        Per l’esperimento utilizzare i seguenti ordinamenti e schemi
        di dati di input:

        */

    /***variabili globali e strutture*/

typedef struct list_node *list_pointer;

typedef struct list_node {
	int chiave[MAX_CIFRE];
	list_pointer link;
} lista;

typedef struct nodo nodo;

typedef struct nodo {
	int key;
	nodo* link;
} nodo;

int *inversamenteordinata;
int *casuale;
int dinput;
int confronti = 0;
int scambi = 0;
clock_t start, end;
double tempo;

nodo *listOrdinata = NULL; //lista con interi ordinata
nodo *listQuasiOrd = NULL; //lista con interi quasi ordinata
nodo *listInverOrd = NULL; //lista con interi inversamente ordinata
nodo *listNonOrd = NULL; //lista con interi non ordinata



    /***dichiarazioni di funzioni*/

void SWAP(int *f1,int *f2);
void selezione(int lista[],int n);
void selezione_inversa(int lista[],int n);
int dimensione();
void adatta(int lista[],int radice,int n);
void merge(int lista[],int ordinata[],int i, int m, int n);
void passo_merge(int lista[], int ordinata[], int n, int lungh);
void mergesort(int lista[], int n);
list_pointer crea_nodo(list_pointer *,int);
list_pointer radice_sort(list_pointer ptr);
void inserzione(int lista[],int);
void heapsort(int lista[], int);
void Quicksort(int A[], int, int);
nodo *creaListNonOrd (nodo* list, int dim);
void Radixsort(nodo* list);
nodo* creaNodo(nodo* vecchio);


    /***avvio del codice*/

void case1(){   ///ordinamento per selezione

    int i, j;

    casuale = (int*) malloc(500*sizeof(int));

    for (i=0; i< 500; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t500 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 500);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 500);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(500*sizeof(int));
    for(i=0, j = 499; (i < 500 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 500);


    printf("\tQuasi ordinata\n");
    for (i=0; i<500; i++){
        if(i > 500/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 500);



	///1000

    casuale = (int*) malloc(1000*sizeof(int));

    for (i=0; i<1000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t1000 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 1000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 1000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(1000*sizeof(int));
    for(i=0, j = 999; (i < 1000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 1000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<1000; i++){
        if(i > 1000/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 1000);


    ///2000

    casuale = (int*) malloc(2000*sizeof(int));

    for (i=0; i<2000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t2000 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 2000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 2000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(2000*sizeof(int));

    for(i=0, j = 2000-1; (i < 2000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 2000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<2000; i++){
        if(i > 2000/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 2000);


    ///5000

    casuale = (int*) malloc(5000*sizeof(int));

    for (i=0; i<5000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t5000 elementi\n");


    printf("\tCasuale\n");
    selezione(casuale, 5000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 5000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(5000*sizeof(int));

    for(i=0, j = 5000-1; (i < 5000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 5000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<5000; i++){
        if(i > 5000/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 5000);




    ///10000
    casuale = (int*) malloc(10000*sizeof(int));

    for (i=0; i<10000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t10000 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 10000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 10000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(10000*sizeof(int));

    for(i=0, j = 10000-1; (i < 10000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 10000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<10000; i++){
        if(i > 10000/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 10000);




    ///20000
    casuale = (int*) malloc(20000*sizeof(int));

    for (i=0; i<20000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t20000 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 20000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 20000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(20000*sizeof(int));

    for(i=0, j = 20000-1; (i < 20000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 20000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<20000; i++){
        if(i > 20000/2)
            casuale[i] = rand()%9999;
        }

    selezione(casuale, 20000);



///50000
    casuale = (int*) malloc(50000*sizeof(int));

    for (i=0; i<50000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t50000 elementi\n");

    printf("\tCasuale\n");
    selezione(casuale, 50000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    selezione(casuale, 50000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(50000*sizeof(int));

    for(i=0, j = 50000-1; (i < 50000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    selezione(inversamenteordinata, 50000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<50000; i++){
        if(i > 50000/2)
            casuale[i] = rand()%9999;
        }
    selezione(casuale, 50000);



}

void case2(){   ///ordinamento per inserzione


    int i, j;

    casuale = (int*) malloc(500*sizeof(int));

    for (i=0; i< 500; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t500 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 500);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 500);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(500*sizeof(int));
    for(i=0, j = 499; (i < 500 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 500);


    printf("\tQuasi ordinata\n");
    for (i=0; i<500; i++){
        if(i > 500/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 500);



	///1000

    casuale = (int*) malloc(1000*sizeof(int));

    for (i=0; i<1000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t1000 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 1000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 1000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(1000*sizeof(int));
    for(i=0, j = 999; (i < 1000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 1000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<1000; i++){
        if(i > 1000/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 1000);


    ///2000

    casuale = (int*) malloc(2000*sizeof(int));

    for (i=0; i<2000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t2000 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 2000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 2000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(2000*sizeof(int));

    for(i=0, j = 2000-1; (i < 2000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 2000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<2000; i++){
        if(i > 2000/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 2000);


    ///5000

    casuale = (int*) malloc(5000*sizeof(int));

    for (i=0; i<5000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t5000 elementi\n");


    printf("\tCasuale\n");
    inserzione(casuale, 5000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 5000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(5000*sizeof(int));

    for(i=0, j = 5000-1; (i < 5000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 5000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<5000; i++){
        if(i > 5000/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 5000);




    ///10000
    casuale = (int*) malloc(10000*sizeof(int));

    for (i=0; i<10000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t10000 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 10000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 10000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(10000*sizeof(int));

    for(i=0, j = 10000-1; (i < 10000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 10000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<10000; i++){
        if(i > 10000/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 10000);




    ///20000
    casuale = (int*) malloc(20000*sizeof(int));

    for (i=0; i<20000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t20000 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 20000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 20000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(20000*sizeof(int));

    for(i=0, j = 20000-1; (i < 20000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 20000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<20000; i++){
        if(i > 20000/2)
            casuale[i] = rand()%9999;
        }

    inserzione(casuale, 20000);



///50000
    casuale = (int*) malloc(50000*sizeof(int));

    for (i=0; i<50000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t50000 elementi\n");

    printf("\tCasuale\n");
    inserzione(casuale, 50000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    inserzione(casuale, 50000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(50000*sizeof(int));

    for(i=0, j = 50000-1; (i < 50000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    inserzione(inversamenteordinata, 50000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<50000; i++){
        if(i > 50000/2)
            casuale[i] = rand()%9999;
        }
    inserzione(casuale, 50000);
}

void case3(){   ///ordinamento per heap

    int i, j;

    casuale = (int*) malloc(500*sizeof(int));

    for (i=0; i< 500; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t500 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 500);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 500);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(500*sizeof(int));
    for(i=0, j = 499; (i < 500 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 500);


    printf("\tQuasi ordinata\n");
    for (i=0; i<500; i++){
        if(i > 500/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 500);



	///1000

    casuale = (int*) malloc(1000*sizeof(int));

    for (i=0; i<1000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t1000 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 1000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 1000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(1000*sizeof(int));
    for(i=0, j = 999; (i < 1000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 1000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<1000; i++){
        if(i > 1000/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 1000);


    ///2000

    casuale = (int*) malloc(2000*sizeof(int));

    for (i=0; i<2000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t2000 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 2000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 2000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(2000*sizeof(int));

    for(i=0, j = 2000-1; (i < 2000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 2000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<2000; i++){
        if(i > 2000/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 2000);


    ///5000

    casuale = (int*) malloc(5000*sizeof(int));

    for (i=0; i<5000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t5000 elementi\n");


    printf("\tCasuale\n");
    heapsort(casuale, 5000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 5000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(5000*sizeof(int));

    for(i=0, j = 5000-1; (i < 5000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 5000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<5000; i++){
        if(i > 5000/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 5000);




    ///10000
    casuale = (int*) malloc(10000*sizeof(int));

    for (i=0; i<10000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t10000 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 10000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 10000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(10000*sizeof(int));

    for(i=0, j = 10000-1; (i < 10000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 10000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<10000; i++){
        if(i > 10000/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 10000);




    ///20000
    casuale = (int*) malloc(20000*sizeof(int));

    for (i=0; i<20000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t20000 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 20000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 20000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(20000*sizeof(int));

    for(i=0, j = 20000-1; (i < 20000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 20000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<20000; i++){
        if(i > 20000/2)
            casuale[i] = rand()%9999;
        }

    heapsort(casuale, 20000);



///50000
    casuale = (int*) malloc(50000*sizeof(int));

    for (i=0; i<50000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t50000 elementi\n");

    printf("\tCasuale\n");
    heapsort(casuale, 50000);
    ///ora è ordinata
    printf("\tOrdinata\n");
    heapsort(casuale, 50000);

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(50000*sizeof(int));

    for(i=0, j = 50000-1; (i < 50000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    heapsort(inversamenteordinata, 50000);


    printf("\tQuasi ordinata\n");
    for (i=0; i<50000; i++){
        if(i > 50000/2)
            casuale[i] = rand()%9999;
        }
    heapsort(casuale, 50000);


}

void case4(){   ///quicksort

    int i, j;

    casuale = (int*) malloc(500*sizeof(int));

    for (i=0; i< 500; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t500 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    Quicksort(casuale, 0, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;
	///ora è ordinata

    printf("\tOrdinata\n");
    start = clock();
    Quicksort(casuale, 0, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(500*sizeof(int));
    for(i=0, j = 499; (i < 500 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<500; i++){
        if(i > 500/2)
            casuale[i] = rand()%9999;
        }
        start = clock();
    Quicksort(casuale, 0, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



	///1000

    casuale = (int*) malloc(1000*sizeof(int));

    for (i=0; i<1000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t1000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    Quicksort(casuale, 0, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

	///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    Quicksort(casuale, 0, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;
    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(1000*sizeof(int));
    for(i=0, j = 999; (i < 1000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<1000; i++){
        if(i > 1000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    Quicksort(casuale, 0, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///2000

    casuale = (int*) malloc(2000*sizeof(int));

    for (i=0; i<2000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t2000 elementi\n");

    printf("\tCasuale\n");
        start = clock();
    Quicksort(casuale, 0, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///ora è ordinata
    printf("\tOrdinata\n");
        start = clock();
    Quicksort(casuale, 0, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(2000*sizeof(int));

    for(i=0, j = 2000-1; (i < 2000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
        start = clock();
    Quicksort(inversamenteordinata, 0, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<2000; i++){
        if(i > 2000/2)
            casuale[i] = rand()%9999;
        }
        start = clock();
    Quicksort(casuale, 0, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///5000

    casuale = (int*) malloc(5000*sizeof(int));

    for (i=0; i<5000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t5000 elementi\n");


    printf("\tCasuale\n");
        start = clock();
    Quicksort(casuale, 0, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///ora è ordinata
    printf("\tOrdinata\n");
        start = clock();
    Quicksort(casuale, 0, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(5000*sizeof(int));

    for(i=0, j = 5000-1; (i < 5000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<5000; i++){
        if(i > 5000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    Quicksort(casuale, 0, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



    ///10000
    casuale = (int*) malloc(10000*sizeof(int));

    for (i=0; i<10000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t10000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    Quicksort(casuale, 0, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    Quicksort(casuale, 0, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(10000*sizeof(int));

    for(i=0, j = 10000-1; (i < 10000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<10000; i++){
        if(i > 10000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    Quicksort(casuale, 0, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;




    ///20000
    casuale = (int*) malloc(20000*sizeof(int));

    for (i=0; i<20000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t20000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    Quicksort(casuale, 0, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



    printf("\tOrdinata\n");
    start = clock();
    Quicksort(casuale, 0, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(20000*sizeof(int));

    for(i=0, j = 20000-1; (i < 20000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<20000; i++){
        if(i > 20000/2)
            casuale[i] = rand()%9999;
        }

    start = clock();
    Quicksort(casuale, 0, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



///50000
    casuale = (int*) malloc(50000*sizeof(int));

    for (i=0; i<50000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t50000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    Quicksort(casuale, 0, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    Quicksort(casuale, 0, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(50000*sizeof(int));

    for(i=0, j = 50000-1; (i < 50000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    Quicksort(inversamenteordinata, 0, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<50000; i++){
        if(i > 50000/2)
            casuale[i] = rand()%9999;
        }

    start = clock();
    Quicksort(casuale, 0, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


}

void case5(){   ///mergesort


    int i, j;

    casuale = (int*) malloc(500*sizeof(int));

    for (i=0; i< 500; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t500 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    mergesort(casuale, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;
	///ora è ordinata

    printf("\tOrdinata\n");
    start = clock();
    mergesort(casuale, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(500*sizeof(int));
    for(i=0, j = 499; (i < 500 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<500; i++){
        if(i > 500/2)
            casuale[i] = rand()%9999;
        }
        start = clock();
    mergesort(casuale, 500);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



	///1000

    casuale = (int*) malloc(1000*sizeof(int));

    for (i=0; i<1000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t1000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    mergesort(casuale, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

	///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    mergesort(casuale, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;
    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(1000*sizeof(int));
    for(i=0, j = 999; (i < 1000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<1000; i++){
        if(i > 1000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    mergesort(casuale, 1000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///2000

    casuale = (int*) malloc(2000*sizeof(int));

    for (i=0; i<2000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t2000 elementi\n");

    printf("\tCasuale\n");
        start = clock();
    mergesort(casuale, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///ora è ordinata
    printf("\tOrdinata\n");
        start = clock();
    mergesort(casuale, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(2000*sizeof(int));

    for(i=0, j = 2000-1; (i < 2000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
        start = clock();
    mergesort(inversamenteordinata, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<2000; i++){
        if(i > 2000/2)
            casuale[i] = rand()%9999;
        }
        start = clock();
    mergesort(casuale, 2000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///5000

    casuale = (int*) malloc(5000*sizeof(int));

    for (i=0; i<5000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t5000 elementi\n");


    printf("\tCasuale\n");
        start = clock();
    mergesort(casuale, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    ///ora è ordinata
    printf("\tOrdinata\n");
        start = clock();
    mergesort(casuale, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(5000*sizeof(int));

    for(i=0, j = 5000-1; (i < 5000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tQuasi ordinata\n");
    for (i=0; i<5000; i++){
        if(i > 5000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    mergesort(casuale, 5000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



    ///10000
    casuale = (int*) malloc(10000*sizeof(int));

    for (i=0; i<10000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t10000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    mergesort(casuale, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    mergesort(casuale, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(10000*sizeof(int));

    for(i=0, j = 10000-1; (i < 10000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<10000; i++){
        if(i > 10000/2)
            casuale[i] = rand()%9999;
        }
    start = clock();
    mergesort(casuale, 10000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;




    ///20000
    casuale = (int*) malloc(20000*sizeof(int));

    for (i=0; i<20000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t20000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    mergesort(casuale, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



    printf("\tOrdinata\n");
    start = clock();
    mergesort(casuale, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(20000*sizeof(int));

    for(i=0, j = 20000-1; (i < 20000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<20000; i++){
        if(i > 20000/2)
            casuale[i] = rand()%9999;
        }

    start = clock();
    mergesort(casuale, 20000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;



///50000
    casuale = (int*) malloc(50000*sizeof(int));

    for (i=0; i<50000; i++){
        casuale[i] = rand()%INT_MAX;
    }
    printf("\n\t50000 elementi\n");

    printf("\tCasuale\n");
    start = clock();
    mergesort(casuale, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    ///ora è ordinata
    printf("\tOrdinata\n");
    start = clock();
    mergesort(casuale, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

    printf("\tInversamente ordinata\n");

    inversamenteordinata = (int*) malloc(50000*sizeof(int));

    for(i=0, j = 50000-1; (i < 50000 && j >= 0); i++, j--){
        casuale[i] = inversamenteordinata[j];
    }
    start = clock();
    mergesort(inversamenteordinata, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


    printf("\tQuasi ordinata\n");
    for (i=0; i<50000; i++){
        if(i > 50000/2)
            casuale[i] = rand()%9999;
        }

	start = clock ();
    mergesort(casuale, 50000);
    end = clock ();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;


}


nodo* creaNodo(nodo* vecchio)
{
    nodo* nuovo;

    nuovo = (nodo*) malloc(sizeof(nodo));

    nuovo->link = NULL;

    return nuovo;
}

nodo *creaListOrdinata (nodo* list, int dim)
{
    list = (nodo*) malloc(sizeof(nodo));

    nodo* w = list;
    int i;
    int prec;

    for(i=0; i<dim; i++)
    {
        w->link = creaNodo(w);
        w = w->link;
    }

    list->key = prec = rand()%5;

    for(w=list->link; w!=NULL; w=w->link)
    {
        w->key = prec + 1 + rand()%4;
        prec = w->key;
    }

    return list;
}

nodo *creaListQuasiOrd (nodo* list, int dim)
{
    list = (nodo*) malloc(sizeof(nodo));

    nodo* w = list;
    int i;
    int prec;

    for(i=0; i<dim; i++)
    {
        w->link = creaNodo(w);
        w = w->link;
    }

    list->key = prec = rand()%5;

    for(i=0, w=list->link; w!=NULL; w=w->link, i++)
    {
        if(i<dim/2)
        {
            w->key = prec + 1 + rand()%4;
            prec = w->key;
        }
        else
        {
            w->key = rand()%(dim*5);
        }
    }

    return list;
}

nodo *creaListInverOrd (nodo* list, int dim)
{
    list = (nodo*) malloc(sizeof(nodo));

    nodo* w = list;
    int i;
    int prec;

    for(i=0; i<dim; i++)
    {
        w->link = creaNodo(w);
        w = w->link;
    } //Ora w punta all'ultimo elemento della lista!!

    prec = dim*5 + rand()%100;

    for(w=list; w!=NULL; w=w->link)
    {
        w->key = prec - 1 - rand()%6;
        prec = w->key;
    }

//    for(w=list; w!=NULL; w=w->link)
//        printf("%d  ", w->key);

    return list;
}

nodo *creaListNonOrd (nodo* list, int dim)
{
    list = (nodo*) malloc(sizeof(nodo));

    nodo* w = list;
    int i;
    int prec;

    for(i=0; i<dim; i++)
    {
        w->link = creaNodo(w);
        w = w->link;
    }

    list->key = prec = rand()%5;

    for(w=list->link; w!=NULL; w=w->link)
    {
        w->key = rand()%(dim*5);
    }

    return list;
}



void case6(){   ///radixsort


    printf("\n\t500 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 500);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 500);
    listInverOrd = creaListInverOrd (listInverOrd, 500);
    listNonOrd = creaListNonOrd (listNonOrd, 500);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t1000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 1000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 1000);
    listInverOrd = creaListInverOrd (listInverOrd, 1000);
    listNonOrd = creaListNonOrd (listNonOrd, 1000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t2000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 2000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 2000);
    listInverOrd = creaListInverOrd (listInverOrd, 2000);
    listNonOrd = creaListNonOrd (listNonOrd, 2000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t5000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 5000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 5000);
    listInverOrd = creaListInverOrd (listInverOrd, 5000);
    listNonOrd = creaListNonOrd (listNonOrd, 5000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t10000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 10000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 10000);
    listInverOrd = creaListInverOrd (listInverOrd, 10000);
    listNonOrd = creaListNonOrd (listNonOrd, 10000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t20000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 20000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 20000);
    listInverOrd = creaListInverOrd (listInverOrd, 20000);
    listNonOrd = creaListNonOrd (listNonOrd, 20000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

        printf("\n\t50000 elementi\n");

    listOrdinata = creaListOrdinata (listOrdinata, 50000);
    listQuasiOrd = creaListQuasiOrd (listQuasiOrd, 50000);
    listInverOrd = creaListInverOrd (listInverOrd, 50000);
    listNonOrd = creaListNonOrd (listNonOrd, 50000);

    printf("\tCasuale\n");
    Radixsort(listNonOrd);
    printf("\tOrdinata\n");
    Radixsort(listOrdinata);
    printf("\tInversamente ordinata\n");
    Radixsort(listInverOrd);
    printf("\tQuasi ordinata\n");
    Radixsort(listQuasiOrd);

}


int main(){

    int scelta;

    srand(time(NULL));

    while(1){

        printf("\tAST 12: confronto dei metodi di ordinamento\nSeleziona tra:\n"
                "1) Ordinamento per selezione\n2) Inserzione\n3) Ordinamento heap\n"
                "4) Quicksort\n5) Ordinamento per fusione\n6) Ordinamento con radice (con radice = 10)"
                "\nScelta: ");

        scanf("%d", &scelta);

        printf("\n");

        switch(scelta){

        case 1: ///ordiamento selezione
                printf("\tOrdinamento per selezione\n");
                case1();
                printf("\n");
                printf("\n");

            break;

        case 2: ///inserzione
                printf("\tOrdinamento per inserzione\n");
                case2();
                printf("\n");
                printf("\n");

            break;

        case 3:
                printf("\tHeapsort\n");
                case3();
                printf("\n");
                printf("\n");

            break;

        case 4: printf("\tQuicksort\n");
                case4();
                printf("\n");
                printf("\n");

            break;

        case 5: printf("\tMergesort\n");
                case5();
                printf("\n");
                printf("\n");

            break;

        case 6: printf("\tRadixsort\n");
                case6();
                printf("\n");
                printf("\n");

            break;

        default: return 1;

        }
    }

    return 0;
}


void selezione(int lista[],int n){

	int i, j, min;
	start = clock ();

	for(i=0; i<n-1; i++){

		min = i;

		for(j=i+1; j<n; j++){

		    confronti++;

            if(lista[j] >= lista[min]) {
                min = j;
                scambi++;
                }
		}

		SWAP(&lista[i],&lista[min]);

	}
	end = clock ();

	tempo = (double)(end - start)/CLOCKS_PER_SEC;

	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);

	confronti = 0; scambi = 0;

}

void selezione_inversa(int lista[],int n){

	int i,j,min;

	for(i=0;i<n-1;i++){

		min = i;

		for(j=i+1;j<n;j++){
            confronti++;
			if(lista[j]>lista[min])
                min=j;
		}

		SWAP(&lista[i],&lista[min]);
	}
	//printf("confronti = %d , scambi = %d \n",confronti,scambi);
	confronti=0; scambi=0;
}

void SWAP(int *f1,int *f2){

    int tmp=*f1;

    *f1=*f2;

    *f2=tmp;

}


void inserzione(int lista[],int n)
{
	int i,j;
	int prossimo;

	start = clock ();

	for(i=0;i<n;i++){

		prossimo=lista[i];
		confronti++;

		for(j=i-1; j>=0 && prossimo<lista[j]; j--,confronti++,scambi++){

			lista[j+1]=lista[j];

			}

		lista[j+1]=prossimo;

		scambi++;
	}

	end = clock ();

	tempo = (double)(end - start)/CLOCKS_PER_SEC;

	printf("confronti = %d, scambi = %d, tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;
}


void heapsort(int lista[],int n){

	int i;

	start = clock ();

	for(i=n/2 ;i>0 ;i--)
		adatta(lista, i, n);

	for(i=n-1; i>0; i--){

		SWAP(&lista[1], &lista[i+1]);

		scambi++;

		adatta(lista, 1, i);
	}

	end = clock ();

	tempo = (double)(end - start)/CLOCKS_PER_SEC;

	printf("confronti = %d, scambi = %d, tempo = %f\n",confronti,scambi,tempo);

	confronti = 0; scambi = 0;
}


void adatta(int lista[],int radice,int n){

	int figlio, chiaveradice;
	int temp;

	temp = lista[radice];

	chiaveradice = lista[radice];

	figlio = 2*radice;

	while(figlio<=n){

		confronti++;

		if( (figlio<n) && (lista[figlio] < lista[figlio+1]) )
			figlio++;

		confronti++;

		if(chiaveradice>lista[figlio])
            break;

		else {
			lista[figlio/2] = lista[figlio];
			figlio *= 2;
		}
	}

	scambi++;

	lista[figlio/2] = temp;
}

int Perno(int A[], int primo, int ultimo){

	int i = primo;
	int j = ultimo+1;
	int pivot = A[primo];

	do{
		do {
            i++;
            confronti++;

        } while(A[i]<pivot && i<j);

		do {
            j--;
            confronti++;
        } while(A[j]>pivot && j>primo);

		if(i<j) {
            SWAP(&A[i],&A[j]);
            scambi++;
        }
	} while(i<j);

	scambi++;

	SWAP(&A[primo],&A[j]);

	return j;
}


void Quicksort(int A[], int u, int v){

    int q;

	confronti++;

	if(u==v) return;

	else{
		q=Perno(A,u,v);

		confronti++;

		if(u<q)
            Quicksort(A,u,q-1);

        confronti++;

		if(q<v)
            Quicksort(A,q+1,v);
    }
}


void merge(int lista[], int ordinata[], int i, int m, int n){

	int j,k,t;

	j = m+1;
	k = i;

	while(i<=m && j<=n){

		if(lista[i]<=lista[j])
			ordinata[k++] = lista[i++];

		else {
            ordinata[k++] = lista[j++];
            }

		confronti++;
		scambi++;
	}

	if(i > m){
        for(t=j;t<=n;t++){
            ordinata[k+t-j] = lista[t];
            scambi++;
            }
        }
	else {
        for(t=i;t<=m;t++){
            ordinata[k+t-i] = lista[t];
            scambi++;
        }
    }
}

void passo_merge(int lista[], int ordinata[], int n, int lungh){

	int i, j;

	for(i=0;i<=n-2*lungh;i+=2*lungh)
		merge(lista, ordinata, i, i+lungh-1, i+2*lungh-1);

	if(i+lungh<n){

		confronti++;
		merge(lista,ordinata,i,i+lungh-1,n-1);
	}

	else
        for(j=i;j<n;j++)
            ordinata[j] = lista[j];
}

void mergesort(int lista[],int n){

	int lungh = 1;
	int extra[100000];

	confronti++;

	while(lungh<n){

		passo_merge(lista,extra,n,lungh);

		lungh*=2;

		passo_merge(extra,lista,n,lungh);

		lungh*=2;
	}
}


list_pointer radice_sort(list_pointer ptr){

	list_pointer davanti[RADICE_SIZE], dietro[RADICE_SIZE];
	int i, j, cifra;

	for(i=MAX_CIFRE-1; i>=0; i--){

		for(j=0; j<RADICE_SIZE; j++)
			davanti[j] = dietro[j] = NULL;

		while(ptr) {

			confronti++;

			cifra = ptr->chiave[i];

			if(!davanti[cifra])
                davanti[cifra] = ptr;
			else
                dietro[cifra]->link = ptr;

			dietro[cifra] = ptr;

			scambi++;

			ptr = ptr->link;

		}

		ptr = NULL;

		for(j=RADICE_SIZE-1;j>=0;j--){

			if(davanti[j]) {

				dietro[j]->link = ptr;
				ptr = davanti[j];
			}
        }
	}

	return ptr;
}
/*
list_pointer crea_nodo(list_pointer *root,int num){

	list_pointer temp;
	list_pointer aux;

	temp = (list_pointer)malloc(sizeof(lista));

	temp->chiave[0] = (num/1000);
	temp->chiave[1] = (num/100) - (num/1000)*10;
	temp->chiave[2] = (num/10) - (num/100)*10;
	temp->chiave[3] = (num) - (num/10)*10;

	temp->link = NULL;

    return temp;
}
*/

void Radixsort(nodo* list)
{
    nodo *davanti[RADICE_SIZE], *dietro[RADICE_SIZE];
    int i, j, cifra;

    start = clock();

    for(i = MAX_CIFRE-1; i>=0; i--)
    {
        for(j=0; j<RADICE_SIZE; j++)
        {
            davanti[j] = NULL;
            dietro[j] = NULL;
        }

        while(list!=NULL)
        {
            confronti++;
            cifra = (int)((list->key)/(int)pow(10, MAX_CIFRE-1-i))%10;

            if (davanti[cifra] == NULL)
            {
                davanti[cifra] = list;
            }
            else
            {
                dietro[cifra]->link = list;
            }

            dietro[cifra] = list;

            scambi++;

            list = list->link;
        } /// ristabilisce la lista concatenata per il passo succ

        list = NULL;

        for (j=RADICE_SIZE-1; j>=0; j--)
        {
            if(davanti[j]!=NULL)
            {
                dietro[j]->link = list;
                list = davanti[j];
            }
        }
    }

    end = clock();
	tempo = (double)(end - start)/CLOCKS_PER_SEC;
	printf("confronti = %d , scambi = %d , tempo = %f\n",confronti,scambi,tempo);
	confronti = 0; scambi = 0;

	return;
}
