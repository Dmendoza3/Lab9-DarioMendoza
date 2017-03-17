#include "Bender.h"

#ifndef WATER_H
#define WATER_H

class WaterBender : Bender
{
	WaterBender(string, double, double, double, double, int);

    virtual double ataqueEspecial(Bender*);
	virtual void recover(Bender*);
    virtual void spy(Bender*);
	virtual double ataque(Bender*);
    virtual double roll();
};

#endif
