#include "AirBender.h"
#include "FireBender.h"


double AirBender::ataqueEspecial(Bender* enemy)
{
	double  mod = 1;
	if(typeid(*enemy) == typeid(FireBender))
		mod += 0.15;
	mod += roll();
	
	double nhp = enemy->hp;
    nhp = (ofensa * mod) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	return nhp;
}

void AirBender::recover(Bender* enemy)
{
	cout << endl << "Solo el waterbender puede recuperar vida.\n";
}

void AirBender::spy(Bender* enemy)
{
	cout << endl << "Solo el earthbender puede espiar al enemigo.\n";
}
