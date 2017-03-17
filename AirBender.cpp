#include "AirBender.h"
#include "FireBender.h"

AirBender::AirBender(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte) : Bender(nnombre, nhp, ndefensa, nofensa, nfuerza, nsuerte){}


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

double AirBender::roll()
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

double AirBender::ataque(Bender* enemy)
{   
    double nhp = enemy->hp;
    nhp = (ofensa * (1 + roll())) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

    return nhp;
}
