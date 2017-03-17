#include "Bender.h"

#ifndef WATER_H
#define WATER_H

class WaterBender : public Bender
{
	public:
	WaterBender(string, double, double, double, double, int);

    virtual double ataqueEspecial(Bender*);
	virtual void recover();
    virtual void spy(Bender*);
	virtual double ataque(Bender*);
    virtual double roll();
};

#endif
