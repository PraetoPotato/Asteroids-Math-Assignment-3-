#pragma once
class Vect3
{
public:
	Vect3();//constructor
	Vect3(float X, float Y, float Z) :x(X), y(Y), z(Z) {} //constructor that initializes x and y
	~Vect3();//deconstructor

	//operator overloading
	const float & operator[](const int index) const;

	Vect3 operator+(const Vect3 &vec) const;
	Vect3 operator-(const Vect3 &vec) const;
	
	Vect3 operator*(const Vect3 &vec) const;
	Vect3 operator/(const Vect3 &vec) const;
	Vect3 operator*(float scalar) const;
	Vect3 operator/(float scalar) const;

private:
	float x, y,z;
	
};