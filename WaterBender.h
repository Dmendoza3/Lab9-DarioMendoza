#include "Bender.h"

#ifndef WATER_H
#define WATER_H

class WaterBender : Bender
{
    virtual double ataqueEspecial(Bender*);
	virtual void recover(Bender*);
    virtual void spy(Bender*);
};

#endif
