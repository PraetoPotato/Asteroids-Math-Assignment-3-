#include "proj.win32/Vect3.h"

const float & Vect3::operator[](const int index) const
{
	return (&x)[index];
}

