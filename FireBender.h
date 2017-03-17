#include "Bender.h"

#ifndef FIRE_H
#define FIRE_H

class FireBender : Bender
{
    virtual double ataqueEspecial(Bender*);
	virtual void recover(Bender*);
    virtual void spy(Bender*);
};

#endif
