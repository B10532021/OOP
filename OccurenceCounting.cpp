// Name: 朱皓
// Date: March 15, 2018
// Last Update: March 15, 3018
// Problem statement: This C++ program computes the occurence counting. 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct Record
{
	int num;
	int times = 1;
}record;

int main()
{
	record n;
	vector <record> number;
	fstream fs;
	fs.open("input.txt", ios::in);
	int count = 0;
	fs >> n.num;
	number.push_back(n);
	count++;

	while (fs >> n.num)//讀檔案到最尾端
	{

		for (int i = 0; i < count; i++)
		{
			if (n.num == number[i].num)//如果數字已經出現過 則出現次數+1
			{
				number[i].times++;
				break;
			}
			else if (i + 1 == count)//當沒有出現過數字 i的下一個也沒數字了 則pushback到vector裡面
			{
				number.push_back(n);
				count++;
				break;
			}
		}
		
		
	}
	fs.close();

	for (int i = 0; i < number.size() - 1; i++)
		for (int j = i + 1; j < number.size(); j++)//開始做大小的排列
		{
			record temp;
			if (number[i].num < number[j].num)
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}

	fstream fp;
	fp.open("output.txt", ios::out);

	fp << "N" << "\t" << "Count" << endl;	
	for (int i = 0; i < count; i++)
	{
		fp << number[i].num << "\t" << number[i].times << endl;
	}

	return 0;
}