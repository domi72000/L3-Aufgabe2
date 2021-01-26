//
//	Inhalt:
//		Projekt: 			SimSTB
//		Thema:				Simulation digitaler und analoger Ein- und Ausgaben
//		Datei:				Beispieldatei f�r die Nutzung der Schnittstelle
//
//	Autor:
//		Name:				Markus Breuer
//		Organisaion:		STB
//
//	Datum:
//		Erstellt:			24.12.2018
//		Letzte �nderung:	31.07.2019
//
#define _CRT_SECURE_NO_WARNINGS									// Sicherheitswarnung ignorieren

#include <cstdlib>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <ctime>    
#include "simulation.h"

using namespace std;

int main()
{
	double	limit_oben = 0;
	double  limit_unten = 0;
	int		anzahl = 0;
	double	summe = 0;
	int		anzahl_sollbereich = 0;
	int		anzahl_groesser = 0;
	int		anzahl_kleiner = 0;


	locale::global(locale("German_germany"));						// Zeichensatz deutsch

	cout << "Messwertauswertung mit SimSTB" << endl;
	cout << "----------------------------------------" << endl << endl;

	cout << "Oberer Grenzwert: ";
	cin >> limit_oben;

	cout << "Unterer Grenzwert: ";
	cin >> limit_unten;

	while (digEin(0) != 1) {
		Sleep(10);
	}
	time_t time_start = time(0);

	while (digEin(0))
	{
		double wert = anaEin(0);
		cout << wert << endl;
		Sleep(1000);
		
	}
	time_t time_end = time(0);


	cout << "Anfang: " << ctime(&time_start);
	cout << "Ende: " << ctime(&time_end);

	cout << "Anzahl der Messwerte im Sollbereich: " << anzahl << endl;
	cout << "Anzahl der Messwerte größer oberer Grenzwert: " << anzahl_groesser << endl;
	cout << "Anzahl der Messwerte kleiner unterer Grenzwert: " << anzahl_kleiner << endl;

	cout << "Prozentualer Anteil im Sollbereich: " << " " << endl;
	cout << "Prozentualer größer oberer Grenzwert: " << " " << endl;
	cout << "Prozentualer kleiner unterer Grenzwert: " << " " << endl;



	system("Pause");
	return 0;
}
