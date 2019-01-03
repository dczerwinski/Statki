#ifndef Gra_h
#define Gra_h
#include <iostream>
#include "Mapa.h"

using namespace std;

class Go_Gra : public Map
{
public:
	Go_Gra();
	~Go_Gra();
	int PVP();
	int PVE();
	int EVE();

private:
	void Stworz_mape();
	void CheatModeOn();
	void CheatModeOff();
	Map* mapa_1;
	Map* mapa_2;
	Map* mapa_1OP;
	Map* mapa_2OP;
	bool check_win(Map *mapa);
	bool shoot(Map *mapa_a, Map *mapa_xOP, int a = -1, int b = -1);

	void zatopiony();


};


#endif // Gra_h

