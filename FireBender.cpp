#include "FireBender.h"
#include "WaterBender.h"


double FireBender::ataqueEspecial(Bender* enemy)
{
	double  mod = 1;
	if(typeid(*enemy) == typeid(WaterBender))
		mod += 0.25;
	mod += roll();
	
	double nhp = enemy->hp;
    nhp = (ofensa * mod) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	return nhp;
}

void FireBender::recover(Bender* enemy)
{
    cout << endl << "Solo el waterbender puede recuperar vida.\n";
}

void FireBender::spy(Bender* enemy)
{
    cout << endl << "Solo el earthbender puede espiar al enemigo.\n";
}

