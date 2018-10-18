// Name: ���q
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

	while (fs >> n.num)//Ū�ɮר�̧���
	{

		for (int i = 0; i < count; i++)
		{
			if (n.num == number[i].num)//�p�G�Ʀr�w�g�X�{�L �h�X�{����+1
			{
				number[i].times++;
				break;
			}
			else if (i + 1 == count)//��S���X�{�L�Ʀr i���U�@�Ӥ]�S�Ʀr�F �hpushback��vector�̭�
			{
				number.push_back(n);
				count++;
				break;
			}
		}
		
		
	}
	fs.close();

	for (int i = 0; i < number.size() - 1; i++)
		for (int j = i + 1; j < number.size(); j++)//�}�l���j�p���ƦC
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