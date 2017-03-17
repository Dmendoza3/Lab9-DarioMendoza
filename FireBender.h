#include "Bender.h"

#ifndef FIRE_H
#define FIRE_H

class FireBender : public Bender
{
	public:
	FireBender(string, double, double, double, double, int);

    virtual double ataqueEspecial(Bender*);
	virtual void recover();
    virtual void spy(Bender*);
	virtual double ataque(Bender*);
    virtual double roll();
};

#endif
