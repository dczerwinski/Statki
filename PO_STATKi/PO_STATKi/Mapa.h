#ifndef Mapa_h
#define Mapa_h
#include <iostream>
#include <vector>

using namespace std;

class Map {
public:
	Map(int m, int n);
	Map();
	~Map();
	void wyswietl();
	void wypelnij_mape();
	void zeruj_mape();
	int strzal(int x, int y, Map *mapa_xOP);
	int win_lose;
	int m, n;
	vector < vector <char>> mapa;
private:

	void stworz_mape();
	bool auto_rozstawienie(int *statki);
	bool auto_rozstawieniev2(int * statki);

	bool manual_rozstawienie(int *statki);
	void manual_rozstawienie(int *statki, int jaki_statek, int jak);
	bool rozstaw(int a, int b, int jaki_statek, int jak);


};

#endif // !Mapa_h

