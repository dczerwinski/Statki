#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Gra.h"

using namespace std;

void menu();



int main() {
	while (true) {
		system("cls");
		Go_Gra *g = new Go_Gra;

		int wybor = 0;
		menu();
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			g->PVP();
			break;
		case 2:
			g->PVE();
			break;
		case 3:
			g->EVE();
			break;
		case 5:
			delete g;
			exit(0);
			break;
		default:
			cout << "Nie ma takiej opcji!!";
			system("TIMEOUT 5");
			system("cls");
			break;
		}
	}

	return 0;
}

void menu()
{
	cout << "   _____ _        _   _    _     " << endl;
	cout << "  / ____| |      | | | |  (_)   " << endl;
	cout << " | (___ | |_ __ _| |_| | ___    " << endl;
	cout << " \___ \| __/ _` | __| |/ / |    " << endl;
	cout << " ____) | || (_| | |_|   <| |    " << endl;
	cout << "|_____/ \__\__,_|\__|_|\_\_|    " << endl << endl << endl;
	cout << "1.Gracz vs Gracz\n";
	cout << "2.Gracz vs Bot\n";
	cout << "3.Bot vs Bot\n";

	cout << "5.Exit\n";
}
