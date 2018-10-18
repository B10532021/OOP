#include <iostream>
#include <string>
#include <algorithm>
#include "Rect.h" 
using namespace std;
Rect::Rect()
{
}

Rect::Rect(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}

Rect operator + (const Rect& r1, const Rect& r2)
{
	int x, y, h, w;
	if (r1.x >= r2.x)
	{
		x = r2.x;
	}
	else
	{
		x = r1.x;
	}

	if (r1.y >= r2.y)
	{
		y = r1.y;
	}
	else
	{
		y = r2.y;
	}

	if (r1.x + r1.width >= r2.x + r2.width && r1.x >= r2.x)
	{
		w = r1.x + r1.width - r2.x;
	}
	else if (r1.x + r1.width >= r2.x + r2.width && r1.x <= r2.x)
	{
		w = r1.width;
	}
	else if (r2.x + r2.width >= r1.x + r1.width && r2.x >= r1.x)
	{
		w = r2.x + r2.width - r1.x;
	}
	else if (r2.x + r2.width >= r1.x + r1.width && r2.x <= r1.x)
	{
		w = r2.width;
	}

	if (r1.y - r1.height <= r2.y - r2.height && r1.y >= r2.y)
	{
		h = r1.height;
	}
	else if (r1.y - r1.height <= r2.y - r2.height && r1.y <= r2.y)
	{
		h = r1.height + r2.y - r1.y;
	}
	else if (r2.y - r2.height <= r1.y - r1.height && r2.y >= r1.y)
	{
		h = r2.height;
	}
	else if (r2.y - r2.height <= r1.y - r1.height && r2.y <= r1.y)
	{
		h = r2.height + r1.y - r2.y;
	}
	return Rect(x, y, w, h);
}
Rect operator * (const Rect& r1, const Rect& r2)
{
	int x, y, w, h;
	if (r1.x <= r2.x && r1.x + r1.width >= r2.x)
	{
		x = r2.x;
	}
	else if (r2.x <= r1.x && r2.x + r2.width >= r1.x)
	{
		x = r1.x;
	}
	else
	{
		x = -1;
	}
	if (r1.y >= r2.y && r1.y - r1.height <= r2.y)
	{
		y = r2.y;
	}
	else if (r2.y >= r1.y && r2.y - r2.width <= r1.y)
	{
		y = r1.y;
	}
	else
	{
		y = -1;
	}
	if (r1.x == r2.x && r1.width == r2.width)
	{
		w = r1.width;
	}
	else if (r1.x <= r2.x && r1.x + r1.width >= r2.x && r1.x + r1.width < r2.x + r2.width)
	{
		w = r1.x + r1.width - r2.x;
	}
	else if (r1.x <= r2.x && r1.x + r1.width >= r2.x && r1.x + r1.width > r2.x + r2.width)
	{
		w = r2.width;
	}
	else if (r2.x <= r1.x && r2.x + r2.width >= r1.x && r2.x + r2.width < r1.x + r1.width)
	{
		w = r2.x + r2.width - r1.x;
	}
	else if (r2.x <= r1.x && r2.x + r2.width >= r1.x && r2.x + r2.width > r1.x + r1.width)
	{
		w = r1.width;
	}
	else
	{
		w = -1;
	}

	if (r1.y == r2.y && r1.height == r2.height)
	{
		h = r1.height;
	}
	else if (r1.y >= r2.y && r1.y - r1.height <= r2.y && r1.y - r1.height > r2.y - r2.height)
	{
		h = -(r1.y - r1.height + r2.y);
	}
	else if (r1.y >= r2.y && r1.y - r1.height <= r2.y && r1.y - r1.height < r2.x - r2.height)
	{
		h = r2.height;
	}
	else if (r2.y >= r1.y && r2.y - r2.height <= r1.y && r2.y - r2.height >r1.y + r1.height)
	{
		h = -(r2.y - r2.height + r1.y);
	}
	else if (r2.y >= r1.y && r2.y - r2.height <= r1.y && r2.y - r2.height < r1.y - r1.height)
	{
		h = r1.height;
	}
	else
	{
		h = -1;
	}
	return Rect(x, y, w, h);
}
string Rect::toString()
{
	string a;
	a.clear();
	if (width < 0 && height < 0)
	{
		a = "(0, 0, 0, 0)";
		cout << "Not overlapping" << endl;
	}
	else
	{
		a = "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(width) + ", " + to_string(height) + ")";
	}
	//cout << a << endl;
	/*char* str = new char[a.length()];
	for (int i = 0; i < a.length(); i++)
	{
		str[i] = a[i];
	}*/
	return a;
}

Rect::~Rect()
{
}


int main()
{
	int x1, y1, width1, height1;	//for rect1
	int x2, y2, width2, height2;	//for rect2

	while (cin >> x1 >> y1 >> width1 >> height1
		>> x2 >> y2 >> width2 >> height2) {

		Rect rect1 = Rect(x1, y1, width1, height1);		//construct rect1
		Rect rect2 = Rect(x2, y2, width2, height2);		//construct rect2
		Rect unionRect = rect1 + rect2;

		cout << "union : " << unionRect.toString() << endl;

		Rect interRect = rect1 * rect2;
		cout << "intersection : " << interRect.toString() << endl;
	}
	system("pause");
	return 0;
}


