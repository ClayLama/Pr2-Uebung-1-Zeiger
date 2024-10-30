//Übung 1, Aufgabe 4: "vokaleZaehlen.c" (27.10.2024) (Autor: Mattis Schreiner)
//Programm zum Zählen von Vokalen innerhalb eines Strings
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 10

/// Ziel:	Zählen von Vokalen in String und Rückgabe des Werts als Int
/// Parameter: str: String, von dem die Vokale gezählt werden 
/// Return:	Anzahl Vokale
int vokaleString(char* str);

/// Ziel:	Zählen von Vokalen in Stringvektor
/// Parameter: str: Stringvektor, von dem die Vokale gezählt werden 
/// Return:	Anzahl Vokale
int vokaleStringvektor(int anzahl, char* str[]);

int main() {
	char string[LENGTH + 1] = { 0 };		//Buchstabenstring
	int anzahlVokale = 0;					//Gezählte Anzahl der Vokale String
	int anzahlVokaleStringvektor = 0;		//Gezählte Anzahl der Vokale Stringvektor

	char a[] = "Hans";						//Erstellung des Stringvektors
	char b[] = "Jutta";
	char c[] = "Lu";
	char* stringvektor[] = { a, b, c };
	int laengeStringvektor = sizeof(stringvektor) / sizeof(stringvektor[0]);

	printf("************************************************************\n");
	printf("*                                                          *\n");
	printf("*                      Vokale Zaehlen                      *\n");
	printf("*                                                          *\n");
	printf("************************************************************\n");
	printf("\n");

	srand((int)time(NULL));

	//STRING
	//Generierung und Ausagabe des Strings
	for (int i = 0; i < LENGTH; i++)
	{
		while (1) {
			string[i] = rand();
			if ((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122))
				break;
		}
	}
	string[LENGTH] = '\0';
	printf("Generierter String: \"%s\"\n", &string);

	//Zählen der Vokale
	anzahlVokale = vokaleString(string);

	//Ausgabe des Ergebnisses
	switch (anzahlVokale) {
	case 0:
		printf("In dem String befinden sich keine Vokale.");
		break;
	case 1:
		printf("In dem String befindet sich ein Vokal.");
		break;
	default:
		printf("In dem String befinden sich %d Vokale.", anzahlVokale);
	}
	printf("\n\n");


	//STRINGVEKTOR
	//Ausgabe des Stringvektors
	printf("Generierter Stringvektor: ");
	for (int i = 0; i < laengeStringvektor; i++) {
		printf("%s ", stringvektor[i]);
	}
	printf("\n");



	//Zählen der Vokale
	anzahlVokaleStringvektor = vokaleStringvektor(laengeStringvektor, stringvektor);

	//Ausgabe des Ergebnisses
	switch (anzahlVokaleStringvektor) {
	case 0:
		printf("In dem Stringvektor befinden sich keine Vokale.");
		break;
	case 1:
		printf("In dem Stringvektor befindet sich ein Vokal.");
		break;
	default:
		printf("In dem Stringvektor befinden sich %d Vokale.", anzahlVokaleStringvektor);
	}
	printf("\n\n");

	return 0;
}

/// Ziel:	Zählen von Vokalen in String und Rückgabe des Werts als Int
/// Parameter: str: String, von dem die Vokale gezählt werden 
/// Return:	Anzahl Vokale
int vokaleString(char* str) {
	int i = 0;		//Zähler der Schleifendurchläufe
	char vokale[11] = "aeiouAEIOU";
	int anzahlVokale = 0;

	while (str[i] != '\0') {
		int j = 0;		//Zähler innere Schleife
		while (vokale[j] != '\0') {
			if (str[i] == vokale[j])
				anzahlVokale++;
			j++;
		}
		i++;
	}
	return anzahlVokale;
}

/// Ziel:	Zählen von Vokalen in Stringvektor
/// Parameter: str: Stringvektor, von dem die Vokale gezählt werden 
/// Return:	Anzahl Vokale
int vokaleStringvektor(int anzahl, char* str[]) {
	int anzahlVokale = 0;

	for (int k = 0; k < anzahl; k++)
		anzahlVokale += vokaleString(str[k]);
	

	return anzahlVokale;
}