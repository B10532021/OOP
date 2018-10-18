// Name: 朱皓
// Date: March 16, 2018
// Last Update: March 16, 3018
// Problem statement: This C++ program computes the TextTextTextText-based histogrambased. 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
	fstream fs;
	fs.open("grade.txt", ios::in);

	int array[6] = { 0 };
	int a;

	while (fs >> a)//讀檔案到最尾端
	{

		for (int i = 0; i < 6; i++)
		{
			if (a == i)//分數每出現一次 則出現次數+1
			{
				array[i]++;
				break;
			}
		}


	}
	fs.close();



	fstream fp;
	fp.open("grade.Output", ios::out);

	for (int i = 0; i < 6; i++)
	{
		fp << array[i] << " grade(s) of " << i << endl;
	}

	return 0;
}