#include "WaterBender.h"
#include "EarthBender.h"


double WaterBender::ataqueEspecial(Bender* enemy)
{
	double  mod = 1;
	if(typeid(*enemy) == typeid(EarthBender))
		mod += 0.25;
	mod += roll();	

	double nhp = enemy->hp;
    nhp = (ofensa * mod) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	return nhp;
}

void WaterBender::recover(Bender* enemy)
{
    if(fuerza >= 110)
		hp += 75;
}

void WaterBender::spy(Bender* enemy)
{
    cout << endl << "Solo el earthbender puede espiar al enemigo.\n";
}

