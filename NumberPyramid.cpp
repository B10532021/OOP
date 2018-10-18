// Name: 朱皓
// Date: March 15, 2018
// Last Update: March 15, 3018
// Problem statement: This C++ program computes the number pyramid. 
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	vector <int> number;
	string a;
	int count = 0, n = 0, flag = 0;
	while (cin >> a)
	{
		if (a.length() == 1)//如果只有一個數字就直接印出來
		{
			cout << a << endl;
		}
		else
		{

			for (int i = 0; i < a.length(); i++)//如果有很多數字就看第一個是多少，第二個是多少...後面一樣
			{
				switch (a[i])
				{
				case '1':
					n = 1;
					number.push_back(n);//然後放進vector
					break;
				case '2':
					n = 2;
					number.push_back(n);
					break;
				case '3':
					n = 3;
					number.push_back(n);
					break;
				case '4':
					n = 4;
					number.push_back(n);
					break;
				case '5':
					n = 5;
					number.push_back(n);
					break;
				case '6':
					n = 6;
					number.push_back(n);
					break;
				case '7':
					n = 7;
					number.push_back(n);
					break;
				case '8':
					n = 8;
					number.push_back(n);
					break;
				case '9':
					n = 9;
					number.push_back(n);
					break;
				default:
					break;
				}
			}

			while (number[flag] == 0)//把在第一個不是零的數支前的數字都排除掉
			{
				flag++;
			}

			vector < vector<int>> arr(number.size());
			for (int i = flag; i < number.size(); i++)
			{
				arr[0].push_back(number[i]);
			}


			for (int i = 0; i < number.size() - 1; i++)//把第一列的數字兩兩相加pushback到下一列的陣列，反覆這樣做
			{
				for (int j = 0; j < arr[i].size() - 1; j++)
				{
					arr[i + 1].push_back(arr[i][j] + arr[i][j + 1]);
				}
			}


			cout << arr[number.size() - 1][0] << endl;
			number.clear();
			arr.clear();

		}
		
	}
	
	
	system("pause");

	return 0;

}