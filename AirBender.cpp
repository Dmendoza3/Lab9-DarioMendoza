#include "AirBender.h"
#include "FireBender.h"

AirBender::AirBender(string nnombre, double nhp, double ndefensa, double nofensa, double nfuerza, int nsuerte) : Bender(nnombre, nhp, ndefensa, nofensa, nfuerza, nsuerte){}


double AirBender::ataqueEspecial(Bender* enemy)
{
	double  mod = 1;
	if(typeid(*enemy) == typeid(FireBender) || nombre == "Aang")
		mod += 0.15;
	mod += roll();
	
	double nhp = enemy->hp;
    nhp = (ofensa * mod) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);
	
	cout << endl << nombre << " causa " << nhp << " de daño a " << enemy->nombre << endl;

	return nhp;
}

void AirBender::recover()
{
	if(nombre == "Aang")
		if(fuerza >= 110)
		{
	        hp += 75;
			cout << "\nAang recupero 75 puntos de vida";
		}
	else
		cout << endl << "Solo el waterbender puede recuperar vida.\n";
}

void AirBender::spy(Bender* enemy)
{
	if(nombre == "Aang")
	{
		cout << endl << "Estado del enemigo:";
		cout << "\nNombre: " << enemy->nombre;
		cout << "\nHP: " << enemy->hp;
		cout << "\nDefensa: " << enemy->defensa;
		cout << "\nOfensa: " << enemy->ofensa;
		cout << "\nFuerza: " << enemy->fuerza;
		cout << "\nSuerte: " << enemy->suerte << endl;
	}
	else
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
        if((rand() % 10) % 3 == 0)
            return 0.50;
    }
    return 0;
}

double AirBender::ataque(Bender* enemy)
{   
    double nhp = enemy->hp;
    nhp = (ofensa * (1 + roll())) - enemy->defensa;
    enemy->hp -= ((nhp < 0)?0:nhp);

	cout << endl << nombre << " causa " << nhp << " de daño a " << enemy->nombre << endl;
    return nhp;
}
