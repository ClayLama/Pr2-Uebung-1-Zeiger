//Übung 1, Aufgabe 3: "selectsort.c" (24.10.2024) (Autor: Mattis Schreiner)
//Programm zur Sortierung eines gegebenen Zahlenvektors nach Größe
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 10

/// Ziel:	Sortierung und Rückgabe eines gegebenen Zahlenvektors
/// Parameter: zahlen: Zahlenvektor, mit LENGTH anzahl an Zahlen
/// Return:	/
void selectsort(int* arr);

int main() {
	int arr[LENGTH] = { 0 };	//Zahlenvektor

	printf("************************************************************\n");
	printf("*                                                          *\n");
	printf("*                        Selectsort                        *\n");
	printf("*                                                          *\n");
	printf("************************************************************\n");
	printf("\n");

	srand((int)time(NULL));

	//Generierung und Ausagabe des Zahlenvektors
	printf("Vor dem Sortieren\n");
	for (int i = 0; i < LENGTH; i++)
	{
		arr[i] = rand();
		printf("%6d", arr[i]);
	}
	printf("\n");

	//Sortierung des Zahlenvektors
	selectsort(arr);

	//Ausgabe des Ergebnisses
	printf("Nach dem Sortieren\n");
	for (int i = 0; i < LENGTH; i++)
		printf("%6d", arr[i]);
	printf("\n");

	return 0;
}

/// Ziel:	Sortierung und Rückgabe eines gegebenen Zahlenvektors
/// Parameter: zahlen: Zahlenvektor, mit LENGTH anzahl an Zahlen
/// Return:	/
void selectsort(int* zahlen) {
	int n = LENGTH;
	int j = 0;
	int i = 0;
	int min = 0;
	int hilf = 0;

	while (j < n - 1) {
		min = j;
		i = j + 1;
		while (i < n) {
			if (zahlen[i] < zahlen[min])
				min = i;
			i++;
		}
		hilf = zahlen[j];
		zahlen[j] = zahlen[min];
		zahlen[min] = hilf;
		j++;
	}
	return;
}