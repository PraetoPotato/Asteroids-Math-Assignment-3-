#include "proj.win32/Vect4.h"


vec4::vec4(float X, float Y, float Z, float W) {
	x = X;
	y = Y;
	z = Z;
	w = W;

}
const float & vec4::operator[](const int index) const
{
	return (&x)[index];
}

float & vec4::operator[](const int index)
{
	return (&x)[index];
}

vec4 vec4::operator+(const vec4 & vec) const
{
	return vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

vec4 vec4::operator-(const vec4 & vec) const
{
	return vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

vec4 vec4::operator=(const vec4 & vec) 
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
	this->w = vec.w;
	return *this;
}
vec4 vec4::operator+=(const vec4 & vec)
{
	this->x= x+ vec.x;
	this->y = y + vec.y;
	this->z = z + vec.z;
	this->w = w + vec.w;

	//*this = *this + vec;
	return *this;
}
