// Name: ���q
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
		if (a.length() == 1)//�p�G�u���@�ӼƦr�N�����L�X��
		{
			cout << a << endl;
		}
		else
		{

			for (int i = 0; i < a.length(); i++)//�p�G���ܦh�Ʀr�N�ݲĤ@�ӬO�h�֡A�ĤG�ӬO�h��...�᭱�@��
			{
				switch (a[i])
				{
				case '1':
					n = 1;
					number.push_back(n);//�M���ivector
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

			while (number[flag] == 0)//��b�Ĥ@�Ӥ��O�s���Ƥ�e���Ʀr���ư���
			{
				flag++;
			}

			vector < vector<int>> arr(number.size());
			for (int i = flag; i < number.size(); i++)
			{
				arr[0].push_back(number[i]);
			}


			for (int i = 0; i < number.size() - 1; i++)//��Ĥ@�C���Ʀr���ۥ[pushback��U�@�C���}�C�A���гo�˰�
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