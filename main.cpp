#include <time.h>
#include <vector>

#include "Bender.h"
#include "AirBender.h"
#include "WaterBender.h"
#include "EarthBender.h"
#include "FireBender.h"

void fight(Bender*, Bender*);

int main()
{
	srand(time(NULL));

	vector<Bender*> bender;
	//(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte)
	bender.push_back(new AirBender("Aang", 100, 20, 70, 200, 10));
	bender.push_back(new WaterBender("Karara", 90, 10, 50, 200, 5));
	bender.push_back(new EarthBender("Toph", 150, 50, 80, 200, 4));
	bender.push_back(new FireBender("Zuko", 170, 50, 90, 200, 3));

	while(true)
	{
		int b1, b2;
		do{
			cout << "\nSimulacion de combate:\n"
			<<		"Elija los combatientes:\n"
			<<		"1. Aang\n"
			<<		"2. Katara\n"
			<<		"3. Toph\n"
			<<		"4. Zuko\n"
			<<		"0. Salir\n"
			<<		"->";
			cin >> b1 >> b2;

			if(b1 == 0 || b2 == 0)
				goto exit;
		}while(b1 < 1 || b1 > 4 || b2 < 1 || b2 > 4 || b1 == b2);
		fight(bender[b1], bender[b2]);
	}

	exit:

	delete bender[0];
	delete bender[1];
	delete bender[2];
	delete bender[3];
	return 0;
}

void fight(Bender* bender1, Bender* bender2)
{
	bool battle = false;
	int turno = 0;
	while(bender1->hp > 0 || bender2->hp > 0)
	{
		battle = true;
		Bender  *benderAtacante, *benderDefensor;
		if(turno)
		{
			benderAtacante = bender1;
			benderDefensor = bender2;
		}else{
			benderAtacante = bender2;
			benderDefensor = bender1;
		}

		int op = 0;
		cout << "\nTurno: Jugador " << turno + 1 << endl
		<<		"1. Ataque\n"
		<<		"2. Ataque Especial\n"
		<<		"3. Recuperar\n"
		<<		"4. Escanear\n"
		<<		"5. Huir\n"
		<<		"->";
		do{
			cin >> op;
		}while(op < 0 || op > 5);
		
		
		switch(op)
		{
			case 1: benderAtacante->ataque(benderDefensor); break;
			case 2: benderAtacante->ataqueEspecial(benderDefensor); break;
			case 3: benderAtacante->recover(); break;
			case 4: benderAtacante->spy(benderDefensor); break;
			case 5: cout << "\nJugador " << turno + 1 << "Huye del combate.\n"; return;
		}
		
		//Cambio de turno
		turno = !turno;
	}
	
	if(bender1->hp <= 0)
	{
		cout << endl << bender1->nombre << " Esta fuera de combate\n";
		if(battle)
		{
			cout << endl << "Victoria para: " << bender2->nombre << endl;
		}else cout << "\nNo hay combate.\n";
	}
	
	if(bender2->hp <= 0)
	{
		cout << endl << bender2->nombre << " Esta fuera de combate\n";
		if(battle)
		{
			cout << endl << "Victoria para: " << bender1->nombre << endl;
		}else cout << "\nNo hay combate.\n";
	}
}
