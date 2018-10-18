#pragma once
#include <string>
#include <iostream>
using namespace std;
class Rect
{
private:
	int x, y, height, width;
public:
	Rect();
	Rect(int x, int y, int width, int height);
	friend Rect operator + (const Rect& r1, const Rect& r2);
	friend Rect operator * (const Rect& r1, const Rect& r2);
	string toString();
	~Rect();

	
};

Rect operator + (const Rect& r1, const Rect& r2);
Rect operator * (const Rect& r1, const Rect& r2);

