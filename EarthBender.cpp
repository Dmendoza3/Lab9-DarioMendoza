#include "EarthBender.h"
#include "AirBender.h"


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
	string nombre;
        double hp;  
        double defensa;
        double ofensa;
        double fuerza;
        int suerte;


    cout << endl << "Estado del enemigo:"
	<< "\nNombre: " << enemy->nombre <<
	<< "\nDefensa: " << enemy->defensa <<
	<< "\nOfensa: " << enemy->ofensa <<
	<< "\nFuerza: " << enemy->fuerza <<
	<< "\nSuerte: " << enemy->suerte << endl;
}
