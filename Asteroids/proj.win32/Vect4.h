#pragma once
class vec4 {
public:
	float x, y, z, w;

	vec4() = default;
	vec4(float X, float Y, float Z, float W);

	const float& operator[](const int index)const;

	float& operator[](const int index);

	vec4 operator+(const vec4 &vec) const;
	vec4 operator-(const vec4 &vec) const;

};
