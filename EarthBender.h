#include "Bender.h"

#ifndef EARTH_H
#define EARTH_H

class EarthBender : Bender
{
    virtual double ataqueEspecial(Bender*);
	virtual void recover(Bender*);
   	virtual void spy(Bender*);
};

#endif
