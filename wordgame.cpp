#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool check;
void find(char square[][4], bool array[][4], string word, int a, int b, int pos)
{ 
	if (pos == word.length())
	{
		return;
	}
	int i, j, init, now_pos = pos;
	check = 0;
	if (a == 0)
	{
		i = 0;
	}
	else
	{
		i = a - 1;
	}
	if (b == 0)
	{
		j = 0;
		init = 0;
	}
	else
	{
		j = b - 1;
		init = b - 1;
	}

	for (; i <= a + 1 && i < 4; i++)
	{
		for (; j <= b + 1 && j < 4; j++)
		{
			if (i == a && j == b)
			{
				continue;
			}

			if (word[pos] == square[i][j] && array[i][j] == 0)
			{
				check = 1;
				pos++;
				array[i][j] = 1;
				find(square, array, word, i, j, pos);
				if (check)
				{
					break;
				}
				else
				{
					array[i][j] = 0;
					pos = now_pos;
				}
				
			}
		}
		if (check)
		{
			break;
		}
		j = init;
	}
	if (check == 1)
	{
		return;
	}
	
	return;
}
int main()
{
	fstream input;
	input.open("words.txt", ios::in);
	string word;
	char square[4][4];
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> square[i][j];
		}
	
	while (input >> word)
	{
		bool array[4][4] = { 0 };
		//cout << word << endl;
		check = 0;
		int pos = 0, now_pos = 0;
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (square[i][j] == word[0])
				{
					check = 1;
					pos++;
					array[i][j] = 1;
					find(square, array, word, i, j, pos);
					if (check)
					{
						break;
					}
					else
					{
						array[i][j] = 0;
						pos = now_pos;
					}
				}
			}
			if (check)
			{
				break;
			}
			j = 0;
		}
			
		if (check == 1)
		{
			cout << word << endl;
		}
	}
	
	system("pause");
}