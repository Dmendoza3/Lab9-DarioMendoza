#include "FireBender.h"
#include "WaterBender.h"

FireBender::FireBender(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte) : Bender(nnombre, nhp, ndefensa, nofensa, nfuerza, nsuerte){}

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

void FireBender::recover()
{
    cout << endl << "Solo el waterbender puede recuperar vida.\n";
}

void FireBender::spy(Bender* enemy)
{
    cout << endl << "Solo el earthbender puede espiar al enemigo.\n";
}

double FireBender::roll()
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

double FireBender::ataque(Bender* enemy)
{   
    double nhp = enemy->hp;
    nhp = (ofensa * (1 + roll())) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	cout << endl << nombre << " causa " << nhp << " de daño a " << enemy->nombre << endl;
    return nhp;
}
