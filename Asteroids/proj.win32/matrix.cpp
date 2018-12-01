#include "matrix.h"

mat3::mat3()
{
	col[0][0] = 1.0f;
	col[0][1] = 0.0;
	col[0][2] = 0.0;


	col[1][0] = 0.0;
	col[1][1] = 1.0f;
	col[1][2] = 0.0;


	col[2][0] = 0.0;
	col[2][1] = 0.0;
	col[2][2] = 1.0f;
	
}

mat3::mat3(const Vect3 right, const Vect3 up, const Vect3 dir)
{
	col[0] = right;
	col[1] = up;
	col[2] = dir;
	
}

mat3::mat3(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9)
{
	col[0][0] = f1;
	col[0][1] = f2;
	col[0][2] = f3;

	col[1][3] = f4;
	col[1][4] = f5;
	col[1][5] = f6;

	col[2][6] = f7;
	col[2][7] = f8;
	col[2][8] = f9;

}

const Vect3 & mat3::operator[](const int index) const
{
	return col[index];
}

Vect3 & mat3::operator[](const int index)
{
	return col[index];
}

mat3 mat3::operator+(const mat3 & m) const
{
	return mat3(
		col[0] + m[0],
		col[1] + m[1],
		col[2] + m[2])
		;
		
}

mat3 mat3::operator*(const mat3 & m) const
{
	return mat3(
		col[0][0] * m[0][0] + col[1][0] * m[0][1] + col[2][0] * m[0][2] + col[3][0] * m[0][3],
		col[0][0] * m[1][0] + col[1][0] * m[1][1] + col[2][0] * m[1][2] + col[3][0] * m[1][3],
		col[0][0] * m[2][0] + col[1][0] * m[2][1] + col[2][0] * m[2][2] + col[3][0] * m[2][3],

		col[0][1] * m[0][0] + col[1][1] * m[0][1] + col[2][1] * m[0][2] + col[3][1] * m[0][3],
		col[0][1] * m[1][0] + col[1][1] * m[1][1] + col[2][1] * m[1][2] + col[3][1] * m[1][3],
		col[0][1] * m[2][0] + col[1][1] * m[2][1] + col[2][1] * m[2][2] + col[3][1] * m[2][3],

		col[0][2] * m[0][0] + col[1][2] * m[0][1] + col[2][2] * m[0][2] + col[3][2] * m[0][3],
		col[0][2] * m[1][0] + col[1][2] * m[1][1] + col[2][2] * m[1][2] + col[3][2] * m[1][3],
		col[0][2] * m[2][0] + col[1][2] * m[2][1] + col[2][2] * m[2][2] + col[3][2] * m[2][3]
		);
}

mat3 mat3::getTranspose() const
{
	mat3 temp;
	temp[0][0] = col[0][0];
	temp[1][0] = col[0][1];
	temp[2][0] = col[0][2];
	temp[0][1] = col[1][0];
	temp[1][1] = col[1][1];
	temp[2][1] = col[1][2];
	temp[0][2] = col[2][0];
	temp[1][2] = col[2][1];
	temp[2][2] = col[2][2];
	return mat3();
}
