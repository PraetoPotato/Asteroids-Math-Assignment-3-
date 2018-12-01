#include "proj.win32/Vect3.h"



Vect3::Vect3(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;


}
const float & Vect3::operator[](const int index) const
{
	return (&x)[index];
}

Vect3 Vect3::operator+(const Vect3 & vec) const
{
	return Vect3(x + vec.x, y + vec.y, z + vec.z);
}

Vect3 Vect3::operator-(const Vect3  & vec) const
{
	return Vect3(x - vec.x, y - vec.y, z - vec.z);
}

Vect3 Vect3::operator*(const Vect3  & vec) const
{
	return Vect3(x *vec.x, y * vec.y, z * vec.z);
}

Vect3 Vect3::operator/(const Vect3  & vec) const
{
	return Vect3(x /vec.x, y / vec.y, z / vec.z);
}

