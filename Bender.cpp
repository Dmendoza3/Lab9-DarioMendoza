#include "Bender.h"

Bender::Bender(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte)
{
	nombre = nnombre;
	hp = nhp;
	defensa = ndefensa;
	ofensa = nofensa;
	fuerza = nfuerza;
	suerte = nsuerte;
}

double roll()
{
	if(suerte <= 5)
	{
		if(rand() % 1000 == 50)
			return 0.50;
	}
	else if(suerte <= 9)
	{	
		if((rand() % 100) % 5 == 0)
			return 0.50;
	}
	else
	{
		if((rand() % 100) % 3 == 0)
			return 0.50;
	}
	return 0;
}

double Bender::ataque(Bender* enemy)
{
    double nhp = enemy->hp;
    nhp = (ofensa * (1 + roll())) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	return nhp;
}

~Bender(){}
