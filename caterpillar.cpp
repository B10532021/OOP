#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string caterpillar;
	string s;
	while (cin >> s)
	{
		
		if (s == "EAT")
		{
			string s2;
			cin >> s2;
			for (int i = 0; i < s2.length(); i++)
			{
				caterpillar.insert(caterpillar.begin(), s2[i]);
			}
			cout << "@-";
			for (int i = 0; i < caterpillar.length(); i++)
			{
				cout << caterpillar[i] << '-';
			}
				cout << "*" << endl;
		}
		else if (s == "PULL")
		{
			int num;
			cin >> num;
			if (num >= caterpillar.size())
			{
				caterpillar.clear();
			}
			else
			{
				for (int i = 0; i < num; i++)
				{
					caterpillar.pop_back();
				}
			}
			cout << "@-";
			for (int i = 0; i < caterpillar.length(); i++)
			{
				cout << caterpillar[i] << '-';
			}
			cout << "*" << endl;
		}
		else if (s == "THROW")
		{
			int num;
			cin >> num;
			caterpillar.assign(caterpillar.begin() + num, caterpillar.end());
			cout << "@-";
			for (int i = 0; i < caterpillar.length(); i++)
			{
				cout << caterpillar[i] << '-';
			}
			cout << "*" << endl;
		}
		else if (s == "CONSUME")
		{
			char a;
			cin >> a;
			int n;
			int i = 0;
			n = caterpillar.find(a, 0);
			while (n != caterpillar.npos) 
			{
				caterpillar.erase(n, 1);
				n = caterpillar.find('a', n);
			}
			
			cout << "@-";
			for (int i = 0; i < caterpillar.length(); i++)
			{
				cout << caterpillar[i] << '-';
			}
			cout << "*" << endl;
		}
		else if (s == "SORT")
		{
			sort(caterpillar.begin(), caterpillar.end());
			reverse(caterpillar.begin(), caterpillar.end());
			cout << "@-";
			for (int i = 0; i < caterpillar.length(); i++)
			{
				cout << caterpillar[i] << '-';
			}
			cout << "*" << endl;;
		}
		
	}
	system("pause");
}