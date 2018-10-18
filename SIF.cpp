#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
int main() {
	ifstream in("script.txt"); // data file
	istringstream str(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); // read file into string	
	//cout << str;
	map<string, string> plot;
	map<int, string> plot2;
	string s;
	getline(str, s);
	while (s[0] == '#')
	{
		string temp;
		//cout << s;
		if (s[0] == '#' || s[0] == '-')
		{
			string str2;
			while (getline(str, temp))
			{
				if (temp[0] != '#')
				{
					str2 += temp;
					str2 += "\n";
					//getline(str, temp);
				}
				else
					break;
				
			}
			string last;
			for (int i = 0; i < str2.length() - 1; i++)
			{
				last += str2[i];
			}
			plot[s] = last;

		}
		cout << plot[s];
		s = temp;
		//cout << endl;
	}
	/*string go = "#0";
	string::iterator word;
	int count = 1;
	for (word = plot[go].begin(); word != plot[go].end(); word++)
	{
		if (*word == '-')
		{
			cout << "(" << count << ") ";
		}
		else if (*word == '#')
		{
			string a;

			while (*word != '\n')
			{
				a += *word;
				word++;
			}
			plot2[count] = a;
			count++;
			cout << endl;
		}
		else
		{
			cout << *word;
		}
	}
	int i;
	count = 0;
	while (count != 1)
	{
		count = 1;
		cin >> i;
		go = plot2[i];
		for (word = plot[go].begin(); word != plot[go].end(); word++)
		{
			if (*word == '-')
			{
				cout << "(" << count << ") ";
			}
			else if (*word == '#')
			{
				string a;

				while (*word != '\n')
				{
					a += *word;
					word++;
				}
				plot2[count] = a;
				count++;
				cout << endl;
			}
			else
			{
				cout << *word;
			}
		}
	}
	
	*/
	
	system("pause");
}  