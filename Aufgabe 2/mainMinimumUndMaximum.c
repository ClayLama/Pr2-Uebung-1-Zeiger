//Übung 1, Aufgabe 2: "minimumUndMaximum.c" (24.10.2024) (Autor: Mattis Schreiner)
//Programm zur Bestimmung von dem minimalen und maximalen Wert eines Vektors
#include <stdio.h>

/// Ziel:	Bestimmung des Minimal- und Maximalwerts eines Zahlenvektors
/// Parameter: a: Zahlenvektor /n: Anzahl Zahlen im Zahlenvektor /  min: Zeiger auf den Minimalwert / max: Zeiger auf den Maximalwert
/// Return:	/
void minMax(double a[], int n, double* min, double* max);


int main() {
	double vektorZahlen[] = { 1.0, 2.0, 3.5, 2.3, 1.0 };		//Zahlenvektor für Testzwecke
	int n = sizeof(vektorZahlen) / sizeof(vektorZahlen[0]);		//Bestimmung der Länge des Zahlenvektors
	double maximum = 0;
	double minimum = 0;											

	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*               Minimum und Maximum                  *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("\n");
	
	// Zahlenvektor ausgeben
	printf("Zahlenvektor: { ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", vektorZahlen[i]);
	}
	printf("}\n\n");

	minMax(vektorZahlen, n, &minimum, &maximum);

	//Ausgabe der Berechnungen
	printf("Der Maximalwert des Vektors ist %lf\n", maximum);
	printf("Der Minimalwert des Vektors ist %lf", minimum);
	printf("\n\n");

	return 0;
}


/// Ziel:	Bestimmung des Minimal- und Maximalwerts eines Zahlenvektors
/// Parameter: a: Zahlenvektor /n: Anzahl Zahlen im Zahlenvektor /  min: Zeiger auf den Minimalwert / max: Zeiger auf den Maximalwert
/// Return:	/
void minMax(double a[], int n, double* min, double* max) {
	//Anfangswert
	*min = a[0];
	*max = a[0];

	//Bestimmung des Minimums und Maximums
	for (int i = 1; i < n; i++) {
		if (*min > a[i])
			*min = a[i];
		if (*max < a[i])
			*max = a[i];
	}
	return;
}