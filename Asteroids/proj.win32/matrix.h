//#pragma once
//#include "proj.win32/Vect3.h"
//#include <ostream>
//class mat4 {
//public:
//	Vect3 col[4];
//
//	mat4();
//	mat4(const Vect3 right, const Vect3 up, const Vect3 dir, const Vect3 pos);
//	mat4(float f1, float f2,
//		float f3, float f4,
//		float f5, float f6,
//		float f7, float f8,
//		float f9, float f10,
//		float f11, float f12,
//		float f13, float f14,
//		float f15, float f16);
//
//	const Vect3& operator[](const int index)const;
//	Vect3& operator[](const int index);
//
//	mat4 operator+(const mat4&m) const;
//	mat4 operator*(const mat4&m) const;
//
//	mat4 getTranspose() const;
//};
//
//
//inline std::ostream& operator<<(std::ostream& os, const mat4& m) {
//
//	for (int row = 0; row < 4; row++) {
//		for (int column = 0; column < 4; column++) {
//			os << "\t" << m[column][row] << "\t";
//		}
//		os << "\n";
//	}
//	return os;
//}