//Übung 1, Aufgabe 1: "produktUndSumme.c" (22.10.2024) (Autor: Mattis Schreiner)
//Programm zur Berechnung von dem Produkt und der Summe beliebig vieler Zahlen
#include <stdio.h>

/// Ziel:	Das Produkt und die Summe der gegebenen Zahlen soll berechnet werden
/// Parameter: n: Anzahl Zahlen im Zahlenvektor / zahlen: Zahlenvektor / pro: Zeiger auf das Produkt / sum: Zeiger auf die Summe
/// Return:	/
void proSum(int n, double* zahlen, double* pro, double* sum);


int main() {
	double vektorZahlen[] = {1.0, 2.0, 3.5, 2.3, 1.0};
	int n = sizeof(vektorZahlen) / sizeof(vektorZahlen[0]);
	double produkt = 0;
	double summe = 0;

	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*                 Produkt und Summe                  *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("\n");

	// Zahlenvektor ausgeben
	printf("Zahlenvektor: { ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", vektorZahlen[i]);
	}
	printf("}\n\n");

	//Berechnung von Produkt und Summe
	proSum(n, vektorZahlen, &produkt, &summe);
	//Ausgabe der Berechnungen
	printf("Das Produkt des Zahlenvektors ist %lf\n", produkt);
	printf("Die Summe des Zahlenvektors ist   %lf", summe);
	printf("\n\n");

	return 0;
}



/// Ziel:	Das Produkt und die Summe der gegebenen Zahlen soll berechnet werden
/// Parameter: n: Anzahl Zahlen im Zahlenvektor / zahlen: Zahlenvektor / pro: Zeiger auf das Produkt / sum: Zeiger auf die Summe
/// Return:	/
void proSum(int n, double* zahlen, double* pro, double* sum) {
	//Falsche Parameter
	if (n <= 0)
		return;

	*sum = 0;
	*pro = 1;

	//Berechnung Summe
	for (int i = 0; n > i; i++) {
		*sum = zahlen[i] + *sum;
	}

	//Berechnung Produkt
	for (int i = 0; n > i; i++) {
		*pro = zahlen[i] * *pro;
	}
	return;
}