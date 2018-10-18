#include <iostream>
using namespace std;

int main()
{
	int left, height, right, x, y[2004] = { 0 };
	while (cin >> left)
	{
		cin >> height >> right;
		for (x = 2 * left; x <= 2 * right; x++)
		{
			if (y[x] < height)
			{
				y[x] = height;
			}
				
		}
			
	}
	for (x = 0; x <= 2 * 1000; x++) 
	{
		if (y[x] != y[x + 1])
			break;
	}
		
	cout << x / 2 + 1 << " " << y[x] << " " << x / 2 + 1 << " " << y[x + 1];

	for (x++; x <= 2 * 1000; x++)
	{
		if (y[x] < y[x + 1])
		{
			cout << " " << x / 2 + 1 << " " << y[x] << " " << x / 2 + 1 << " " << y[x + 1];
		}	
		else if (y[x] > y[x + 1])
		{
			cout << " " << x / 2 << " " << y[x] << " " << x / 2 << " " << y[x + 1];
		}	
	}
	system("pause");
	return 0;
}