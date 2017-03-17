#include "Bender.h"

#ifndef AIR_H
#define AIR_H

class AirBender : public Bender
{
	public:
	AirBender(string, double, double, double, double, int);

    virtual double ataqueEspecial(Bender*);
	virtual void recover();
    virtual void spy(Bender*);
	virtual double ataque(Bender*);
	virtual double roll();
};

#endif
