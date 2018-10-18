#pragma once
#include <iostream>
#include <vector>
class Vector
{
public:
	float x, y;
	friend Vector operator + (const Vector& v1, const Vector& v2);
	friend Vector operator - (const Vector& v1, const Vector& v2);
	friend float operator * (const Vector& v1, const Vector& v2);
	friend Vector operator * (const Vector& v1, float k);
	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	Vector(){}
	~Vector(){}
};
Vector operator + (const Vector& v1, const Vector& v2);
Vector operator - (const Vector& v1, const Vector& v2);
float operator * (const Vector& v1, const Vector& v2);
Vector operator * (const Vector& v1, float k);

