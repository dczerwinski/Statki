#include "Mapa.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

Map::Map(int m, int n)
{
	this->m = m;
	this->n = n;
	this->win_lose = 0;
	stworz_mape();
}

Map::Map()
{
	this->m = 0;
	this->n = 0;
	this->win_lose = 0;
}

Map::~Map()
{
	mapa = vector < vector <char>>();
}

void Map::stworz_mape()
{
	for (int i = 0; i < this->m; i++) {
		vector<char> row;
		for (int j = 0; j < this->n; j++)
			row.push_back('.');
		mapa.push_back(row);
	}
}

bool Map::auto_rozstawienie(int *statki)
{
	int a = 0, b = 0, jak, jaki_statek;
	srand(time(NULL));
	int l = 0;
	for (int i = 5; i >= 2; i--) {
		while (statki[i] != 0) {

			jaki_statek = i;
			//losowanie statku
			jak = rand() % 4 + 1;
			a = (rand() % this->m);
			b = (rand() % this->n);

			if (rozstaw(a, b, jaki_statek, jak)) {
				statki[i]--;
			}
			l++;

			if (l == 100000) {

				return false;

			}
		}
	}
}


bool Map::manual_rozstawienie(int *statki)
{
	int a = 0, b = 0, jak, jaki_statek;
	//Wybranie statku ktory chcemy ustawic
	//
	bool sprawdzenie_danych = true;
	while (sprawdzenie_danych)
	{
		cout << "\nStatki jakie wybrales i ich ilosc: \n";
		for (int i = 2; i < 6; i++)
			cout << "Rozmiar: " << i << "    ilosc dostpenych: " << statki[i] << endl;

		cout << "\nO jakim rozmiarze statek chcesz ustawic? Przypominam statki sa w wielkosci 2-5\n";
		cin >> jaki_statek;
		if (jaki_statek < 2 || jaki_statek>5) {
			cout << "Nie matakiego rozmiaru statku!\n";
		}
		else
		{
			if (statki[jaki_statek] > 0) {
				sprawdzenie_danych = false;
			}
			else
			{
				cout << "Nie masz dostepnych takich statkow! Sprobuj ponownie\n";
			}
		}
	}


	//w jaki sposb chcemy go ustawic
	sprawdzenie_danych = true;

	while (sprawdzenie_danych) {
		cout << "Do rozstawienia dostepne sa cztery opcje: \n";
		cout << "1. Poziomo w prawo\n";
		cout << "2. Pionowo w dol\n";
		cout << "3. Na skos w lewo\n";
		cout << "4. Na skos w prawo\n";
		cout << "Ktora opcje wybierasz?   ";
		cin >> jak;
		if (jak >= 1 && jak <= 4)sprawdzenie_danych = false;
		else cout << "\n Nie ma takiej opcji!\n";
	}


	//i gdzie chcemy go ustawic
	sprawdzenie_danych = true;
	while (sprawdzenie_danych) {
		cout << "\n\n\nGdzie chcesz rozstawic?\n\n";
		this->wyswietl();
		string gdzie = "";
		string temp;
		cout << "Podaj koordynaty np. A3: ";  cin >> gdzie;
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

		if (a < 0 || a >= this->m || b < 0 || b >= this->n)cout << "\nPodales zle koordynaty!\n";
		else sprawdzenie_danych = false;

	}

	//czy sie udalo ustawic?
	if (rozstaw(a, b, jaki_statek, jak)) {
		cout << "Statek ustawiony Prawidlowo!";
		statki[jaki_statek]--;
		system("PAUSE");
		return true;
	}
	else {
		cout << "Cos poszlo nie tak. Byc moze zle umiesciles statek i wyszedl poza mape lub dotyka innego statku.";
		cout << "Sprobujmy ponownie";
		system("PAUSE");
		manual_rozstawienie(statki, jaki_statek, jak);
	}
	return false;
}

void Map::manual_rozstawienie(int * statki, int jaki_statek, int jak)
{
	//i gdzie chcemy go ustawic
	bool sprawdzenie_danych = true;
	int a = 0, b = 0;
	while (sprawdzenie_danych) {
		cout << "\n\n\nGdzie chcesz rozstawic?\n\n";
		this->wyswietl();
		string gdzie = "";
		string temp;
		cout << "Podaj koordynaty np. A3: ";  cin >> gdzie;
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


		sprawdzenie_danych = false;

	}

	//czy sie udalo ustawic?
	if (rozstaw(a, b, jaki_statek, jak)) {
		cout << "Statek ustawiony Prawidlowo!";
		statki[jaki_statek]--;
		system("PAUSE");
	}
	else {
		cout << "Cos poszlo nie tak. Byc moze zle umiesciles statek i wyszedl poza mape lub dotyka innego statku.";
		cout << "Sprobujmy ponownie";
		system("PAUSE");
		manual_rozstawienie(statki, jaki_statek, jak);
	}
}

bool Map::rozstaw(int a, int b, int jaki_statek, int jak)
{

	switch (jak)
	{
	case 1: //w prawo
	{
		if (a >= this->m)return false;
		if ((jaki_statek + b) > this->n)return false;
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= (b + jaki_statek + 1); j++) {
				if (i >= 0 && j >= 0 && i < this->m && j < this->n) {
					if (mapa[i][j] != '.')return false;
				}
			}
		}

		for (int i = b; i < (b + jaki_statek); i++)
			this->mapa[a][i] = char(jaki_statek + '0');
		break;
	}
	case 2://w dol
	{
		if (b >= this->n)return false;
		if ((jaki_statek + a) > this->m)return false;

		for (int i = a - 1; i <= (a + jaki_statek + 1); i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (i >= 0 && j >= 0 && i < this->m && j < this->n) {
					if (mapa[i][j] != '.')return false;
				}
			}
		}

		for (int i = a; i < (a + jaki_statek); i++)
			this->mapa[i][b] = char(jaki_statek + '0');
		break;
	}
	case 3://na skos w lewo
	{
		if (a >= this->m)return false;
		if ((jaki_statek + b) >= this->n)return false;
		if (a - jaki_statek <= 0)return false;

		for (int k = 0; k < jaki_statek; k++) {
			for (int i = a - 1; i <= a + 1; i++) {
				for (int j = b - 1; j <= (b + 1); j++) {
					if (i >= 0 && j >= 0 && i < this->m && j < this->n && (i - k) >= 0 && (j + k) < this->n)
						if (mapa[i - k][j + k] != '.')return false;
				}
			}
		}

		for (int i = 0; i < jaki_statek; i++)
			this->mapa[a - i][b + i] = char(jaki_statek + '0');

		break;
	}
	case 4://na skos w prawo
	{
		if (a + jaki_statek >= this->m)return false;
		if ((jaki_statek + b) >= this->n)return false;
		for (int k = 0; k < jaki_statek; k++) {
			for (int i = a - 1; i <= a + 1; i++) {
				for (int j = b - 1; j <= (b + 1); j++) {
					if (i >= 0 && j >= 0 && (i + k) < this->m && j < this->n && (j + k) < this->n)
						if (mapa[k + i][j + k] != '.')return false;
				}
			}
		}
		;
		for (int i = 0; i < jaki_statek; i++)
			this->mapa[a + i][b + i] = char(jaki_statek + '0');

		break;
	}
	default:
		return false;
		break;
	}
}

void Map::wypelnij_mape()
{
	int ile;
	float aile = this->m*this->n;
	aile = this->m*this->n*0.38
		;

	system("cls");
	cout << "Statki moga pokrywac maxymalnie 0,4 powierzchni planszy a wiec: " << aile << " pol" << endl;

	int statki[6];
	int suma_statkow = 0;
	bool _b = true;

	while (_b) {
		int temp = 0;
		for (int i = 2; i < 6; i++) {
			cout << "Ile statkow o dlugosci " << i << " ?";
			cin >> statki[i];

			temp = temp + (i*statki[i]);

			suma_statkow = suma_statkow + statki[i];
		}
		if (temp > aile) {
			cout << "Podane przez ciebie statki zajmuja zbyt duzo powierzchni!!\n Wprowadz statki ponownie.";
			suma_statkow = 0;
			this->win_lose = 0;
		}
		else
		{
			_b = false;
			cout << "Prawidlowo wprowdzona liczba statkow!" << endl;
			this->win_lose = temp;
		}
	}


	while (!(_b)) {
		cout << "\n\nRodzaj rozstawienia statkow: ";
		cout << "\n1. Automatycznie\n2.Manualnie\n";
		cin >> ile;

		switch (ile)
		{
		case 1:

			int tab[6];
			for (int i = 2; i < 6; i++)
				tab[i] = statki[i];
			while (auto_rozstawienie(tab) == false) {
				zeruj_mape();
				for (int i = 2; i < 6; i++)
					tab[i] = statki[i];

			}
			cout << "\nTwoje rozstawienie: \n";
			this->wyswietl();
			system("PAUSE");
			_b = true;
			break;
		case 2:
			while (suma_statkow > 0)
				if (manual_rozstawienie(statki))suma_statkow--;
			_b = true;
			break;
		default:
			cout << "Nie ma takiej opcji!";
			break;
		}

	}


}

void Map::zeruj_mape() {
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			this->mapa[i][j] = '.';
}


int Map::strzal(int x, int y, Map *mapa_xOP)
{
	switch (mapa[x][y])
	{
	case '.':
		mapa_xOP->mapa[x][y] = 'o';
		cout << "\nPudlo!\n";

		return 1;
		break;
	case '2':
		mapa_xOP->mapa[x][y] = 'X';
		cout << "\nTrafiles!\n";
		system("PAUSE");
		return 2;
		break;
	case '3':
		mapa_xOP->mapa[x][y] = 'X';
		cout << "\nTrafiles!\n";
		system("PAUSE");
		return 2;
		break;
	case '4':
		mapa_xOP->mapa[x][y] = 'X';
		cout << "\nTrafiles!\n";
		system("PAUSE");
		return 2;
		break;
	case '5':
		mapa_xOP->mapa[x][y] = 'X';
		cout << "\nTrafiles!\n";
		system("PAUSE");
		return 2;
		break;
	default:
		return 3;
		break;
	}
}

void Map::wyswietl()
{
	string out = "  @";
	cout << "    ";
	for (int i = 0; i < this->n; i++)
		cout << "_" << i + 1;
	cout << "_" << endl;

	for (int i = 0; i < this->m; i++) {
		out[2] += 1;
		if (out[2] > 'Z') {
			if (out[0] == ' ') {
				if (out[1] == ' ')out[1] = '@';
				out[1] = out[1] + 1;
				out[2] = 'A';
			}
			else {
				out[1] = char(out[1] + 1);
				out[2] = 'A';
			}
		}
		if (out[1] > 'Z') {
			out[0] = '@' + char(i / 625);
			out[1] = 'A';
			out[2] = 'A';
		}
		cout << out << "| ";
		for (int j = 0; j < this->n; j++) {
			cout << mapa[i][j] << " ";
		}
		cout << "|" << endl;
	}
}
