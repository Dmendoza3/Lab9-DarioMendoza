#include <stdlib.h>
#include <string>
#include <typeinfo>

using namespace std;

#ifndef BENDER_H
#define BENDER_H

class Bender
{
	public:
		string nombre;
		double hp;	
		double defensa;
		double ofensa;
		double fuerza;
		int suerte;

		//Constructor
		Bender(string, double, double, double, double, int);

		//Metodos
		double ataque(Bender*);
		virtual double ataqueEspecial(Bender*) = 0;
		virtual void recover(Bender*) = 0;
		virtual void spy(Bender*) = 0;
		double roll();

		//Destructor
		virtual ~Bender();
};

#endif
