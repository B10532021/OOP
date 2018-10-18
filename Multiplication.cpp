#include <iostream>
#include <vector>
using namespace std;

typedef struct polynomial
{
	int a, b, c, d;

}Poly;

int main()
{
	Poly poly;
	while (cin >> poly.a)
	{
		cin >> poly.b >> poly.c >> poly.d;

		vector<int> array;
		vector<int> array2;
		array.push_back(poly.c);
		array.push_back(poly.b);
		array.push_back(poly.a);
		array2.push_back(poly.c);
		array2.push_back(poly.b);
		array2.push_back(poly.a);

		for (int i = 1; i < poly.d; i++)
		{
			vector<int> temp;
			for (int k = 0; k < array2.size(); k++)
			{
				temp.push_back(array[0] * array2[k]);
			}


			int count = array.size();
			for (int j = 1; j < count; j++)
			{

				for (int k = 0; k < array2.size(); k++)
				{
					if (k == array2.size() - 1)
					{
						temp.push_back(array[j] * array2[k]);
						break;
					}
					temp[k + j] += array[j] * array2[k];
				}
			}

			array2.clear();
			array2.assign(temp.begin(), temp.end());

		}

		cout << array2[array2.size() - 1];
		for (int i = array2.size() - 2; i >= 0; i--)
		{
			cout << " " << array2[i];
		}
		cout << endl;
	}
	
	system("pause");
}