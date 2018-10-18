#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string alpha;

	while (cin >> alpha)
	{
		int count = 0, length;
		length = alpha.size();
		for (int i = 0; i <= length; i++)
		{
			if (i == sqrt(length))
			{
				count = i;
				break;
			}
			else if (i < sqrt(length) && sqrt(length) < (i + 1))
			{
				count = i + 1;
				break;
			}
		}

		char **code;
		code = new char*[count];
		for (int i = 0; i < count; i++)
		{
			code[i] = new char[count];
		}
		
		int num = 0;
		for(int i = 0; i < count; i++)
			for(int j = 0; j < count; j ++)
			{
				code[i][j] = 0;
			}

		for (int i = 0; i < count; i++)
			for (int j = 0; j < count; j++)
			{
				if (num < length)
				{
					code[j][i] = alpha[num];
					num++;
				}
			}
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (code[i][j] != 0)
				{
					cout << code[i][j];
				}
			}
			cout << endl;
		}
			
	}
	system("pause");
	return 0;
}