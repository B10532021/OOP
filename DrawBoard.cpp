#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main()
{
	int rx, ry;
	cin >> rx >> ry;
	char** matrix = new char*[ry];
	for (int i = 0; i < ry; i++)
	{
		matrix[i] = new char[rx];
	}
	for (int i = 0; i < ry; i++)
	{
		for (int j = 0; j < rx; j++)
		{
			 matrix[i][j] = '0';
		}
	}

	string s;
	while (cin >> s)
	{
		if (s == "RECT")
		{
			int a, b, c, d;
			char graph;
			cin >> a >> b >> c >> d >> graph;
			if (d <= 0)
			{
				for (int i = 0; i < ry && i <= b; i++)
				{
					if (c <= 0)
					{
						for (int j = 0; j < rx && j <= a; j++)
						{
							matrix[i][j] = graph;
						}
					}
					else
					{
						for (int j = c; j < rx && j <= a; j++)
						{
							matrix[i][j] = graph;
						}
					}
				}
			}
			else
			{
				for (int i = d; i < ry && i <= b; i++)
				{
					if (c <= 0)
					{
						for (int j = 0; j < rx && j <= a; j++)
						{
							matrix[i][j] = graph;
						}
					}
					else
					{
						for (int j = c; j < rx && j <= a; j++)
						{
							matrix[i][j] = graph;
						}
					}
				}
			}
			
			
		}
		else if (s == "CIRCLE")
		{
			int x, y, radious;
			char graph;
			cin >> x >> y >> radious >> graph;
			for (int i = 0; i < ry; i++)
				for (int j = 0; j < rx; j++)
				{
					int r = pow(j - (x), 2) + pow(i - (y), 2);
					if (r <= pow(radious, 2))
					{
						if (x + 1 < rx && y + 1 < ry)
						{
							matrix[i][j] = graph; 
						}
						
					}
				}

		}
		else if (s == "DRAW")
		{
			for (int i = 0; i < ry; i++)
			{
				for (int j = 0; j < rx; j++)
				{
					cout << matrix[i][j];
				}
				cout << endl;
			}
				
		}
	}
}