#pragma once
class Vect2
{
public:
	Vect2();//constructor
	Vect2(float X, float Y) :x(X), y(Y) {} //constructor that initializes x and y
	~Vect2();//deconstructor

	//operator overloading
private:
	float x, y;
};