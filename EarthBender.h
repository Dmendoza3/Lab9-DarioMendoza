#include "Bender.h"

#ifndef EARTH_H
#define EARTH_H

class EarthBender : Bender
{
	EarthBender(string, double, double, double, double, int);

    virtual double ataqueEspecial(Bender*);
	virtual void recover(Bender*);
   	virtual void spy(Bender*);
	virtual double ataque(Bender*);
    virtual double roll();
};

#endif
