// Name: 朱皓
// Date: March 15, 2018
// Last Update: March 15, 3018
// Problem statement: This C++ program computes the sort and factorial. 
#include <iostream>
using namespace std;

int Factorial(int num)
{
	int sum = 1;
	for (int i = 1; i <= num; i++)//算階層的迴圈
	{
		sum *= i;
	}
	return sum;
}

void Sort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)//排大小的迴圈
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp;
			if (array[j] < array[i])//當下一項的數字比現在的小，則做交換
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		int *array = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> array[i];
		}

		Sort(&array[0], n);
		
		cout << Factorial(array[0]);
		for (int i = 1; i < n; i++)
		{
			cout << " <" << Factorial(array[i]);
		}

		system("pause");
	}
}