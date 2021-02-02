//
//	Inhalt:
//		Projekt: 			SimSTB
//		Thema:				Simulation digitaler und analoger Ein- und Ausgaben
//		Datei:				Auswerten der Messwerte der SimSTB
//
//	Autor:
//		Name:				Dominika Riedel, Dominik Gogic, Dirk Zietz
//		Organisaion:		STB
//
//	Datum:
//		Erstellt:			26.01.2021
//		Letzte Änderung:	02.02.2019
//
#define _CRT_SECURE_NO_WARNINGS																		// Sicherheitswarnung ignorieren

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


	locale::global(locale("German_germany"));														// Zeichensatz deutsch

	while (true) {

		cout << "Messwertauswertung mit SimSTB" << endl;
		cout << "----------------------------------------" << endl << endl;

		cout << "Oberer Grenzwert: ";
		cin >> limit_oben;

		cout << "Unterer Grenzwert: ";
		cin >> limit_unten;

		while (digEin(0) != 1) {																	//Bedingung für den Start
			Sleep(10);
		}
		time_t time_start = time(0);																//Start der Messung

		while (digEin(0))
		{
			double wert = anaEin(0);																//die Werte werden eingelesen
			cout << wert << endl;

			anzahl++;																				//Anzahl der Messwerte
			summe += wert;																			//Summe der Messwerte

			if (wert > limit_oben) {																// oberer Grenzwert
				anzahl_groesser++;
			}

			if (wert < limit_unten) {																// unterer Grenzwert
				anzahl_kleiner++;
			}
			Sleep(1000);																			//Messwerte jede Sekunde

		}
		time_t time_end = time(0);																	//Ende der Messung


																									//Ausgabe nach der Messung:
		cout << "Anfang: " << ctime(&time_start);													//Startzeit
		cout << "Ende: " << ctime(&time_end);														//Endzeit

		cout << "Anzahl der Messwerte: " << anzahl << endl;											//Anzahl


		double mittelwert = summe / (double)anzahl;													//Mittelwerte
		cout << "Mittelwert der Messwerte: " << mittelwert << endl;


		anzahl_sollbereich = anzahl - anzahl_groesser - anzahl_kleiner;								//Anzahl Sollbereich
		cout << "Anzahl der Messwerte im Sollbereich: " << anzahl_sollbereich << endl;
		cout << "Anzahl der Messwerte größer oberer Grenzwert: " << anzahl_groesser << endl;
		cout << "Anzahl der Messwerte kleiner unterer Grenzwert: " << anzahl_kleiner << endl;


		double prozent_sollbereich = anzahl_sollbereich / (double)anzahl * 100;						//Prozentualer Anteil:
		double prozent_groesser = anzahl_groesser / (double)anzahl * 100;
		double prozent_kleiner = anzahl_kleiner / (double)anzahl * 100;

		cout << "Prozentualer Anteil im Sollbereich: " << (int)prozent_sollbereich << "%" << endl;
		cout << "Prozentualer größer oberer Grenzwert: " << (int)prozent_groesser << "%" << endl;
		cout << "Prozentualer kleiner unterer Grenzwert: " << (int)prozent_kleiner << "%" << endl;

		cout << "Enter drücken um eine neue Messung zu starten:";
		int temp;
		cin >> temp;

	}

	system("Pause");
	return 0;
}
