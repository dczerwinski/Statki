#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include "Gra.h"


using namespace std;


Go_Gra::Go_Gra()
{
}

Go_Gra::~Go_Gra()
{
	delete mapa_1;
	delete mapa_2;
	delete mapa_1OP;
	delete mapa_2OP;
}

int Go_Gra::PVP()
{
	Stworz_mape();
	while (true) {
		//pierwsy gracz
		system("cls");

		cout << "Ruch gracza nr. 1\n";
		system("PAUSE");
		do {
			if (check_win(mapa_2)) {
				cout << "Wygral gracz nr. 1 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}
			cout << "\nTwoja mapa: \n";
			mapa_1->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_1OP->wyswietl();

		} while (shoot(mapa_2, mapa_1OP));



		system("PAUSE");

		//drugi gracz
		system("cls");

		do {
			if (check_win(mapa_1)) {
				cout << "Wygral gracz nr. 2 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}
			cout << "\nTwoja mapa: \n";
			mapa_2->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_2OP->wyswietl();

		} while (shoot(mapa_1, mapa_2OP));

	}

}

int Go_Gra::PVE()
{
	Stworz_mape();
	system("cls");
	while (true) {
		//pierwszy gracz


		cout << "\n\nRuch gracza nr. 1\n";
		system("PAUSE");
		system("cls");
		do {
			if (check_win(mapa_2)) {
				cout << "Wygral gracz nr. 1 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}
			cout << "\nTwoja mapa: \n";
			mapa_1->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_1OP->wyswietl();

		} while (shoot(mapa_2, mapa_1OP));



		system("PAUSE");
		int l = 0;
		//drugi gracz
		system("cls");
		int a;
		int b;
		do {
			l++;
			if (check_win(mapa_1)) {
				cout << "Wygral gracz nr. 2 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}
			cout << "\nTwoja mapa: \n";
			mapa_2->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_2OP->wyswietl();
			cout << "\nNacisnij spacje aby bot wykonal strzal";
			char znak;
			while (znak = _getch()) {
				if (znak == 'c') {
					CheatModeOn();
					cout << "\nCheat Mode On\n";
				}
				if (znak == 'o') {
					CheatModeOff();
					cout << "\nCheat Mode Off\n";
				}
				if (znak == ' ') {
					break;
				}
			}

			a = (rand() % mapa_1->m);
			b = (rand() % mapa_1->n);







			cout << "\n\nBot wylosowal pozycje: ";
			int t2, t3, t1;
			if (a < 26)cout << char('A' + a) << b + 1;
			else if (a < 702) {
				t2 = a;
				t2 = t2 / 26;
				t3 = (a - t2 * 26);
				t2 = t2 - 1;
				cout << char('A' + t2) << char('A' + t3) << b + 1;
			}
			else {
				t1 = a;
				t1 = t1 / 675;
				t2 = a - 676;
				t2 = t2 / 26;
				t3 = ((a - 676) - t2 * 26);
				cout << char('A' + t1 - 1) << char('A' + t2 - 1) << char('A' + t3) << b + 1;

			}


		} while (shoot(mapa_1, mapa_2OP, a, b));

	}
}

int Go_Gra::EVE()
{
	int l = 0;
	Stworz_mape();
	system("cls");
	while (true) {
		//pierwszy gracz

		cout << "\nStrzal bota nr1.\n";
		system("PAUSE");
		system("cls");
		int a;
		int b;
		do {
			l++;
			if (check_win(mapa_2)) {
				cout << "Wygral gracz nr. 2 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}

			cout << "\nTwoja mapa: \n";
			mapa_1->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_1OP->wyswietl();
			cout << "\nNacisnij spacje aby bot wykonal strzal";
			char znak;
			while (znak = _getch()) {
				if (znak == 'c') {
					CheatModeOn();
					cout << "\nCheat Mode On\n";
				}
				if (znak == 'o') {
					CheatModeOff();
					cout << "\nCheat Mode Off\n";
				}
				if (znak == ' ') {
					break;
				}
			}

			a = (rand() % mapa_1->m);
			b = (rand() % mapa_1->n);



			cout << "\n\nBot wylosowal pozycje: ";
			int t2, t3, t1;
			if (a < 26)cout << char('A' + a) << b + 1;
			else if (a < 702) {
				t2 = a;
				t2 = t2 / 26;
				t3 = (a - t2 * 26);
				t2 = t2 - 1;
				cout << char('A' + t2) << char('A' + t3) << b + 1;
			}
			else {
				t1 = a;
				t1 = t1 / 675;
				t2 = a - 676;
				t2 = t2 / 26;
				t3 = ((a - 676) - t2 * 26);
				cout << char('A' + t1 - 1) << char('A' + t2 - 1) << char('A' + t3) << b + 1;

			}


		} while (shoot(mapa_2, mapa_1OP, a, b));
		l = 0;

		cout << "\nStrzal bota nr2.\n";
		system("PAUSE");

		//drugi gracz
		system("cls");

		do {
			l++;
			if (check_win(mapa_1)) {
				cout << "Wygral gracz nr. 2 !!!";
				system("PAUSE");
				delete this;
				return 0;
			}
			cout << "\nTwoja mapa: \n";
			mapa_2->wyswietl();
			cout << "\nMapa przeciwnika: \n";
			mapa_2OP->wyswietl();
			cout << "\nNacisnij spacje aby bot wykonal strzal";
			char znak;
			while (znak = _getch()) {
				if (znak == 'c') {
					CheatModeOn();
					cout << "\nCheat Mode On\n";
				}
				if (znak == 'o') {
					CheatModeOff();
					cout << "\nCheat Mode Off\n";
				}
				if (znak == ' ') {
					break;
				}
			}



			a = (rand() % mapa_1->m);
			b = (rand() % mapa_1->n);


			cout << "\n\nBot wylosowal pozycje: ";
			int t2, t3, t1;
			if (a < 26)cout << char('A' + a) << b + 1;
			else if (a < 702) {
				t2 = a;
				t2 = t2 / 26;
				t3 = (a - t2 * 26);
				t2 = t2 - 1;
				cout << char('A' + t2) << char('A' + t3) << b + 1;
			}
			else {
				t1 = a;
				t1 = t1 / 675;
				t2 = a - 676;
				t2 = t2 / 26;
				t3 = ((a - 676) - t2 * 26);
				cout << char('A' + t1 - 1) << char('A' + t2 - 1) << char('A' + t3) << b + 1;

			}


		} while (shoot(mapa_1, mapa_2OP, a, b));

	}
}

void Go_Gra::Stworz_mape()
{
	int m = 0, n = 0;
	bool c = true;
	while (c) {
		system("cls");
		cout << "Podaj wymiary mapy m x n:\nm=  ";
		cin >> m;
		cout << "n=  ";
		cin >> n;

		if (m*n < 6) {
			cout << "\nPodane  pole jest za male!\n";
			system("PASUE");
		}
		else c = false;
	}

	//mapy graczy
	mapa_1 = new Map(m, n);
	mapa_2 = new Map(m, n);
	//mapy do strza³ów
	mapa_1OP = new Map(m, n);
	mapa_2OP = new Map(m, n);

	cout << "Wypelnienie mapy przez 1. gracza\n";
	mapa_1->wypelnij_mape();
	cout << "\n\nWypelnienie mapy przez 2. gracza\n";
	system("PAUSE");
	mapa_2->wypelnij_mape();

	system("TIMEOUT 5");
}

void Go_Gra::CheatModeOn()
{
	for (int i = 0; i < mapa_2->m; i++) {
		for (int j = 0; j < mapa_2->n; j++) {
			if (mapa_1OP->mapa[i][j] == '.')mapa_1OP->mapa[i][j] = mapa_2->mapa[i][j];
		}
	}

	for (int i = 0; i < mapa_1->m; i++) {
		for (int j = 0; j < mapa_1->n; j++) {
			if (mapa_2OP->mapa[i][j] == '.')mapa_2OP->mapa[i][j] = mapa_1->mapa[i][j];
		}
	}
}

void Go_Gra::CheatModeOff()
{
	for (int i = 0; i < mapa_2->m; i++) {
		for (int j = 0; j < mapa_2->n; j++) {
			if (mapa_1OP->mapa[i][j] == '2' || mapa_1OP->mapa[i][j] == '3' || mapa_1OP->mapa[i][j] == '4'
				|| mapa_1OP->mapa[i][j] == '5')mapa_1OP->mapa[i][j] = '.';
		}
	}

	for (int i = 0; i < mapa_1->m; i++) {
		for (int j = 0; j < mapa_1->n; j++) {
			if (mapa_1OP->mapa[i][j] == '2' || mapa_1OP->mapa[i][j] == '3' || mapa_1OP->mapa[i][j] == '4'
				|| mapa_1OP->mapa[i][j] == '5')mapa_1OP->mapa[i][j] = '.';
		}
	}
}

bool Go_Gra::check_win(Map *mapa)
{
	if (mapa->win_lose <= 0)return true;
	return false;
}

bool Go_Gra::shoot(Map * mapa_a, Map * mapa_xOP, int a, int b)
{
	while (true) {
		if (a < 0) {
			cout << "\n\n\nGdzie chcesz strzelic?\n\n";
			this->wyswietl();
			string gdzie = "";
			string temp;
			cout << "Podaj koordynaty np. A3: ";  cin >> gdzie;
			if (gdzie == "CHEATON") {
				CheatModeOn();
				return true;
			}
			if (gdzie == "CHEATOFF") {
				CheatModeOff();
				return true;
			}
			for (int i = 0; i < gdzie.size(); i++)
				if (gdzie[i] < 'A') {
					temp = gdzie;
					temp.erase(0, i);
					gdzie.erase(i, gdzie.size() - i);
					break;
				}



			b = atoi(temp.c_str()) - 1;

			if (gdzie.size() == 1)a = gdzie[0] - 'A';
			else if (gdzie.size() == 2) {
				a = (gdzie[0] - 'A' + 1) * 26;
				a += gdzie[1] - 'A';
			}
			else if (gdzie.size() == 3) {
				a = (gdzie[0] - 'A' + 1) * 676;
				a += (gdzie[1] - 'A' + 1) * 26;
				a += gdzie[2] - 'A';
			}
		}


		if (a < 0 || a >= mapa_1->m || b < 0 || b >= mapa_1->n) {
			cout << "\nPodales zle koordynaty!\n";
			a = -1, b = -1;
		}
		else {
			int temp = mapa_a->strzal(a, b, mapa_xOP);
			zatopiony();

			if (temp == 3)cout << "\nJuz tam strzelales!\n";
			else if (temp == 2) { mapa_a->win_lose--; return true; }
			else if (temp == 1)return false;
		}

	}


}

void Go_Gra::zatopiony() {

	for (int i = 0; i < mapa_1->m; i++) {
		for (int j = 0; j < mapa_1->n; j++) {
			if (mapa_2OP->mapa[i][j] == 'X') {
				int jaki = mapa_1->mapa[i][j] - '0';
				int kierunek = 0;
				if (i + 1 < mapa_1->m) {
					if (mapa_1->mapa[i + 1][j] == mapa_1->mapa[i][j])kierunek = 2;
				}
				if (j + 1 < mapa_1->n)
					if (mapa_1->mapa[i][j + 1] == mapa_1->mapa[i][j])kierunek = 1;
				if (i + 1 < mapa_1->m && j + 1 < mapa_1->n)
					if (mapa_1->mapa[i + 1][j + 1] == mapa_1->mapa[i][j])kierunek = 4;
				if (i - 1 >= 0 && j + 1 < mapa_1->n)
					if (mapa_1->mapa[i - 1][j + 1] == mapa_1->mapa[i][j])kierunek = 3;


				int licznik2;
				bool c;

				switch (kierunek)
				{
				case 2:
				{
					int k = 1;
					while (k < jaki) {
						if (mapa_2OP->mapa[i + k][j] == 'X')c = true;
						else {
							c = false;
							k = jaki + 1;
							break;
						}
						k++;
					}
					if (c == true)
					{
						for (int l = 0; l < jaki; l++)
							mapa_2OP->mapa[i + l][j] = mapa_1->mapa[i + l][j];
					}

					break; }
				case 1:
				{int k = 1;
				while (k < jaki) {
					if (mapa_2OP->mapa[i][j + k] == 'X')c = true;
					else {
						c = false;
						k = jaki + 1;
						break;
					}
					k++;
				}
				if (c == true)
				{
					for (int l = 0; l < jaki; l++)
						mapa_2OP->mapa[i][j + l] = mapa_1->mapa[i][j + l];
				}

				break;
				}
				case 3:
				{int k = 1;
				while (k < jaki) {
					if (mapa_2OP->mapa[i - k][j + k] == 'X')c = true;
					else {
						c = false;
						k = jaki + 1;
						break;
					}
					k++;
				}
				if (c == true)
				{
					for (int l = 0; l < jaki; l++)
						mapa_2OP->mapa[i - l][j + l] = mapa_1->mapa[i - l][j + l];
				}

				break;
				}
				case 4:
				{int k = 1;
				while (k < jaki) {
					if (mapa_2OP->mapa[i + k][j + k] == 'X')c = true;
					else {
						c = false;
						k = jaki + 1;
						break;
					}
					k++;
				}
				if (c == true)
				{
					for (int l = 0; l < jaki; l++)
						mapa_2OP->mapa[i + l][j + l] = mapa_1->mapa[i + l][j + l];
				}

				break; }
				default:
					break;
				}
			}
		}
	}


	for (int i = 0; i < mapa_2->m; i++) {
		for (int j = 0; j < mapa_2->n; j++) {
			if (mapa_1OP->mapa[i][j] == 'X') {
				int jaki = mapa_2->mapa[i][j] - '0';
				int kierunek = 0;
				if (i + 1 < mapa_2->m) {
					if (mapa_2->mapa[i + 1][j] == mapa_2->mapa[i][j])kierunek = 2;
				}
				if (j + 1 < mapa_2->n)
					if (mapa_2->mapa[i][j + 1] == mapa_2->mapa[i][j])kierunek = 1;
				if (i + 1 < mapa_2->m && j + 1 < mapa_2->n)
					if (mapa_2->mapa[i + 1][j + 1] == mapa_2->mapa[i][j])kierunek = 4;
				if (i - 1 >= 0 && j + 1 < mapa_1->n)
					if (mapa_2->mapa[i - 1][j + 1] == mapa_2->mapa[i][j])kierunek = 3;


				int licznik2;
				bool c;

				switch (kierunek)
				{
				case 2:
				{
					int k = 1;
					while (k < jaki) {
						if (mapa_1OP->mapa[i + k][j] == 'X')c = true;
						else {
							c = false;
							k = jaki + 1;
							break;
						}
						k++;
					}
					if (c == true)
					{
						for (int l = 0; l < jaki; l++)
							mapa_1OP->mapa[i + l][j] = mapa_2->mapa[i + l][j];
					}

					break; }
				case 1:
				{
					int k = 1;
					while (k < jaki) {
						if (mapa_1OP->mapa[i][j + k] == 'X')c = true;
						else {
							c = false;
							k = jaki + 1;
							break;
						}
						k++;
					}
					if (c == true)
					{
						for (int l = 0; l < jaki; l++)
							mapa_1OP->mapa[i][j + l] = mapa_2->mapa[i][j + l];
					}

					break;
				}
				case 3:
				{
					int k = 1;
					while (k < jaki) {
						if (mapa_1OP->mapa[i - k][j + k] == 'X')c = true;
						else {
							c = false;
							k = jaki + 1;
							break;
						}
						k++;
					}
					if (c == true)
					{
						for (int l = 0; l < jaki; l++)
							mapa_1OP->mapa[i - l][j + l] = mapa_2->mapa[i - l][j + l];
					}

					break;
				}
				case 4:
				{
					int k = 1;
					while (k < jaki) {
						if (mapa_1OP->mapa[i + k][j + k] == 'X')c = true;
						else {
							c = false;
							k = jaki + 1;
							break;
						}
						k++;
					}
					if (c == true)
					{
						for (int l = 0; l < jaki; l++)
							mapa_1OP->mapa[i + l][j + l] = mapa_2->mapa[i + l][j + l];
					}

					break; }
				default:
					break;
				}
			}
		}
	}



}

