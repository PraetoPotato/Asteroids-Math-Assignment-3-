#pragma once
#include "proj.win32/Vect3.h"
#include <ostream>
class mat3 {
public:
	Vect3 col[3];

	mat3();
	mat3(const Vect3 right, const Vect3 up, const Vect3 dir);
	mat3(float f1, float f2,
		float f3, float f4,
		float f5, float f6,
		float f7, float f8,
		float f9);

	const Vect3& operator[](const int index)const;
	Vect3& operator[](const int index);

	mat3 operator+(const mat3&m) const;
	mat3 operator*(const mat3&m) const;

	mat3 getTranspose() const;
};


inline std::ostream& operator<<(std::ostream& os, const mat3& m) {

	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			os << "\t" << m[column][row] << "\t";
		}
		os << "\n";
	}
	return os;
}