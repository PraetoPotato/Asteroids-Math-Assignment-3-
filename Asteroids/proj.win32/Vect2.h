#pragma once
class Vect3
{
public:
	Vect3();//constructor
	Vect3(float X, float Y, float Z) :x(X), y(Y), z(Z) {} //constructor that initializes x and y
	~Vect3();//deconstructor

	//operator overloading
private:
	float x, y,z;
};