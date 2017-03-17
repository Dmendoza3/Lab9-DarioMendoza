#include "EarthBender.h"
#include "AirBender.h"

EarthBender::EarthBender(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte) : Bender(nnombre, nhp, ndefensa, nofensa, nfuerza, nsuerte){}

double EarthBender::ataqueEspecial(Bender* enemy)
{
	double  mod = 1;
	if(typeid(*enemy) == typeid(AirBender))
		mod += 0.25;
	mod += roll();	

	double nhp = enemy->hp;
    nhp = (ofensa * mod) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	return nhp;
}

void EarthBender::recover(Bender* enemy)
{
    cout << endl << "Solo el waterbender puede recuperar vida.\n";
}

void EarthBender::spy(Bender* enemy)
{
    cout << endl << "Estado del enemigo:";
	cout << "\nNombre: " << enemy->nombre;
	cout << "\nDefensa: " << enemy->defensa;
	cout << "\nOfensa: " << enemy->ofensa;
	cout << "\nFuerza: " << enemy->fuerza;
	cout << "\nSuerte: " << enemy->suerte << endl;
}

double EarthBender::roll()
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

double EarthBender::ataque(Bender* enemy)
{   
    double nhp = enemy->hp;
    nhp = (ofensa * (1 + roll())) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

    return nhp;
}
