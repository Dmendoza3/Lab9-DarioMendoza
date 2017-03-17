#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <iostream>

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
		virtual double ataque(Bender*) = 0;
		virtual double ataqueEspecial(Bender*) = 0;
		virtual void recover(Bender*) = 0;
		virtual void spy(Bender*) = 0;
		virtual double roll() = 0;

		//Destructor
		virtual ~Bender();
};

#endif
