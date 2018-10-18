// Name: ���q
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
	while (coefficients[flag] == 0)//��L����̰����誺�Ƥ��e��0�ư���
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
	for (int j = 0; j < n; j++)//��}�C��index������ơA�C�g�L�@���j��N�⦸���Ӽƽc���M����w���p�@���a���趵�t��
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