#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	float x1, x2, x3, y1, y2, y3;
	while(cin >> x1)
	{		
		cin >> y1 >> x2 >> y2 >> x3 >> y3;
		float line1, line2, line3;
		line1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		line2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
		line3 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	
		float s, area;
		s = (line1 + line2 + line3) / 2;
		area = sqrt(s * (s - line1) * (s - line2) * (s - line3));
	
		cout << fixed << setprecision(2) << area;
	}
	return 0;
	
} 
