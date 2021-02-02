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

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <locale>
#include <conio.h>
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
	char	Start_Zeit_String[30];
	char	End_Zeit_String[30];
	time_t	startzeit, endzeit;

	locale::global(locale("German_germany"));														// Zeichensatz deutsch

	while (true) {

		cout << "Messwertauswertung mit SimSTB" << endl;
		cout << "----------------------------------------" << endl << endl;

		Sleep(10);
		cout << "Oberer Grenzwert: ";
		cin >> limit_oben;

		cout << "Unterer Grenzwert: ";
		cin >> limit_unten;

		cout << endl;

		cout << "Warten bis DE0 = 1 ";
		while (digEin(0) != 1) {																	// Bedingung für den Start
			Sleep(10);
		}
		cout << "[OK]" << endl << endl;
		time(&startzeit);																			// Start der Messung
		
		while (digEin(0))
		{
			double wert = anaEin(0);																// die Werte werden eingelesen
			anzahl++;																				// Anzahl der Messwerte

			cout << "#" << anzahl << "	" << wert << endl;
			summe += wert;																			// Summe der Messwerte

			if (wert > limit_oben) {																// oberer Grenzwert
				anzahl_groesser++;
			}

			if (wert < limit_unten) {																// unterer Grenzwert
				anzahl_kleiner++;
			}
			Sleep(1000);																			// Messwerte jede Sekunde

		}
		time(&endzeit);																				// Ende der Messung



		// ================== AUSGABE DER ZEIT ====================== //
		cout << endl;
		ctime_s(Start_Zeit_String, 26, &startzeit);													// Zeiten in Strings schreiben
		ctime_s(End_Zeit_String, 26, &endzeit);

		cout << left << setw(20) << "Anfang:";														// Startzeit
		cout << Start_Zeit_String;

		cout << left << setw(20) << "Ende:";														// Endzeit
		cout << End_Zeit_String << endl;
		cout << endl;


		// ================== AUSGABE ANZAHL & MITTELWERT ============ //
		cout << left << setw(50) << "Anzahl der Messwerte:";
		cout << anzahl << endl;																		// Anzahl

		double mittelwert = summe / (double)anzahl;													// Mittelwerte
		cout << left << setw(50) << "Mittelwert der Messwerte:";
		cout << fixed << setprecision(2) << mittelwert << endl << endl;
		

		// ================= AUSGABE SOLLBEREICH ABSOLUT ============ //
		anzahl_sollbereich = anzahl - anzahl_groesser - anzahl_kleiner;								
		cout << left << setw(50) << "Anzahl der Messwerte im Sollbereich:";
		cout << anzahl_sollbereich << endl;
		cout << left << setw(50) << "Anzahl der Messwerte größer oberer Grenzwert:";
		cout << anzahl_groesser << endl;
		cout << left << setw(50) << "Anzahl der Messwerte kleiner unterer Grenzwert:";
		cout << anzahl_kleiner << endl << endl;


		// ================= AUSGABE SOLLBEREICH RELATIV ============ //
		double prozent_sollbereich = anzahl_sollbereich / (double)anzahl * 100;
		double prozent_groesser = anzahl_groesser / (double)anzahl * 100;
		double prozent_kleiner = anzahl_kleiner / (double)anzahl * 100;

		cout << left << setw(50) << "Prozentualer Anteil im Sollbereich:";
		cout << fixed << setprecision(2) << prozent_sollbereich << "%" << endl;
		cout << left << setw(50) << "Prozentualer größer oberer Grenzwert:";
		cout << fixed << setprecision(2) << prozent_groesser << "%" << endl;
		cout << left << setw(50) << "Prozentualer kleiner unterer Grenzwert:";
		cout << fixed << setprecision(2) << prozent_kleiner << "%" << endl << endl;


		// ================ MESSUNG WIEDERHOLEN ? ===================== //
		cout << "Enter drücken um eine neue Messung zu starten," << endl;
		cout << "E drücken um das Programm zu beenden." << endl;

		while (true) {																				// Endlosschleife
			int taste = _getch();																	// Taste einlesen
			if (taste == 13) {																		// Taste Enter
				break;																				// While Schleife verlassen
			}
			if (taste == 101 || taste == 69) {														// Taste e oder E
				return 0;																			// main Funktion verlassen
			}
			Sleep(10);
		}
		system("CLS");
	}
}
