// Name: 朱皓
// Date: March 15, 2018
// Last Update: March 15, 3018
// Problem statement: This C++ program computes the differentiating_polynomial. 
#include <iostream>
#include <vector>
using namespace std;

int n;

void Print(int* coefficients)
{
	int flag = n - 1;
	while (coefficients[flag] == 0)//把微分後最高次方的數之前的0排除掉
	{
		flag = flag - 1;
	}
	for (int i = flag; i >= 0; i--)
	{
		cout << coefficients[i] << " ";
	}
	cout << endl;
}

void Differential(int* coefficients)
{
	for (int j = 0; j < n; j++)//把陣列的index當為次方數，每經過一次迴圈就把次方跟細數箱成然後指定給小一次地次方項系數
	{
		coefficients[j - 1] = j * coefficients[j];
		coefficients[j] = 0;
	}
}
void Differential(int* coefficients, int times)
{
	for (int i = 0; i < times; i++)
	{
		for (int j = 0; j < n; j++)
		{
			coefficients[j - 1] = j * coefficients[j];
			coefficients[j] = 0;
		}
	}
	Print(coefficients);
		
}


int main()
{
	int time;
	
	while (cin >> n >> time)
	{
		int *coef = new int[n];
		int *coef2 = new int[n];

		for (int i = n - 1; i >= 0; i--)
		{
			cin >> coef[i];
			coef2[i] = coef[i];
		}


		Differential(&coef[0], time);


		for (int i = 0; i < time; i++)
		{
			Differential(&coef2[0]);
			Print(coef2);
		}
	}

	system("pause");
	return 0;

}