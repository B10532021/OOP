#include <iostream>
#include "Vector.h" 
using namespace std;
Vector operator + (const Vector& v1, const Vector& v2)
{
	float x, y;
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	return Vector(x, y);
}
Vector operator - (const Vector& v1, const Vector& v2)
{
	float x, y;
	x = v1.x - v2.x;
	y = v1.y - v2.y;
	return Vector(x, y);
}
float operator * (const Vector& v1, const Vector& v2)
{
	float x, y;
	x = v1.x * v2.x;
	y = v1.y * v2.y;
	return x + y;
}
Vector operator * (const Vector& v1, float k)
{
	float x, y;
	x = v1.x * k;
	y = v1.y * k;
	return Vector(x, y);
}

int main()
{
	float x, y, k;
	while (cin >> x >> y) {
		Vector mainVector = Vector(x, y);

		cin >> x >> y;
		Vector addVector = Vector(x, y);
		Vector addResult = mainVector + addVector;

		cin >> x >> y;
		Vector subVector = Vector(x, y);
		Vector subResult = mainVector - subVector;

		cin >> x >> y;
		Vector dotVector = Vector(x, y);
		float dotResult = mainVector * dotVector;

		cin >> k;
		Vector scaleVector = mainVector * k;

		cout << "Add Result = ( " << addResult.x << " , " << addResult.y << " )" << endl;
		cout << "Subtract Result = ( " << subResult.x << " , " << subResult.y << " )" << endl;
		cout << "Dot Result = " << dotResult << endl;
		cout << "Scale Result = ( " << scaleVector.x << " , " << scaleVector.y << " )" << endl;
	}

	system("pause");
	return 0;
}