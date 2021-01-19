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
	bool	ende = false;
	double	wert, threshold_top, threshold_bottom;

	locale::global(locale("German_germany"));						// Zeichensatz deutsch

	cout << "Messwertauswertung mit SimSTB" << endl;
	cout << "----------------------------------------" << endl << endl;

	cout << "Oberer Grenzwert: ";
	cin >> threshold_top;

	cout << "Unterer Grenzwert: ";
	cin >> threshold_bottom;

	while (digEin(0) != 1) {
		Sleep(10);
	}
	time_t time_start = time(0);

	while (digEin(0))
	{
		wert = anaEin(0);											// Einlesen eines analogen Eingabesignals über Kanal 0
		cout << wert << endl;
		Sleep(1000);
		ende = digEin(0);											// Einlesen eines digitalen Eingabesignals über Kanal 0
		
	}
	time_t time_end = time(0);


	cout << "Anfang: " << ctime(&time_start);
	cout << "Ende: " << ctime(&time_end);

	cout << "Beispielprogramm beendet" << endl << endl;
	system("Pause");
	return 0;
}
