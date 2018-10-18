#include <iostream>
#include <vector>
#define ELEMENTS_FOR_COMBINATION 5 //i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
using namespace std;

void print(int arrayPtr[], vector<int>& flag, int m, int n)
{
	bool check = 0;
	for (int i = 0; i < m - n; i++)
	{
		if (flag[i] == 1)
		{
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		return;
	}
	check = 0;
	for (int i = 0; i < m; i++)
	{
		if (check == 1 && flag[i] == 0)
		{
			//cout << i << endl;
			flag[i] = 1;
			flag[i - 1] = 0;
			int  count = 0;
			for (int j = 0; j < i - 1; j++)
			{
				if (flag[j] == 0)
				{
					count++;
					flag[j] = 1;
				}
			}
			for (int j = i - 2; count > 0; count--, j--)
			{
				flag[j] = 0;
			}
			break;
		}
		if (flag[i] == 1)
		{
			check = 1;
		}
		
	}
	for (int i = 0; i < m; i++)
	{
		if (flag[i] == 1)
		{
			cout << arrayPtr[i] << " ";
		}
	}
	cout << endl;
	print(arrayPtr, flag, m, n);
	return;
}
void PrintCombination(int arrayPtr[], int m, int n)
{
	vector<int> flag;
	int num = 1;
	for (int i = 0; i < m; i++)
	{
		if (i > n - 1)
		{
			flag.push_back(0);
		}
		else
		{
			flag.push_back(1);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (flag[i] == 1)
		{
			cout << arrayPtr[i] << " ";
		}
	}
	cout << endl;
	print(arrayPtr, flag, m, n);

	return;
}

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];
	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;
	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);
	if (arrayPtr != NULL)
		delete[] arrayPtr;
	return 0;
}