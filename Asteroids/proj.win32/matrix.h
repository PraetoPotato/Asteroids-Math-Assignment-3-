#pragma once
#include "proj.win32/Vect4.h"
#include <ostream>
class mat4 {
public:
	vec4 col[4];

	mat4();
	void Identity();
	mat4(const vec4 right, const vec4 up, const vec4 dir, const vec4 pos);
	mat4(float f1, float f2,
		float f3, float f4,
		float f5, float f6,
		float f7, float f8,
		float f9, float f10,
		float f11, float f12,
		float f13, float f14,
		float f15, float f16);

	const vec4& operator[](const int index)const;
	vec4& operator[](const int index);

	mat4 operator+(const mat4&m) const;
	mat4 operator*(const mat4&m) const;

	mat4 getTranspose() const;
	mat4 Rotate(float theta);
	mat4 RotateX(float theta);
	mat4 RotateY(float theta);
	mat4 RotateZ(float theta);

	mat4 *identity;
};
 //extern declares the existence of global variables in a header, so that each source file that includes the header knows about it


inline std::ostream& operator<<(std::ostream& os, const mat4& m) {

	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			os << "\t" << m[column][row] << "\t";
		}
		os << "\n";
	}
	return os;
}