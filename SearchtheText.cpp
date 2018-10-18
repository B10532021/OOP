#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string word;
	string file = "Data.txt";
	while (cin >> word)
	{
		fstream fp;
		fp.open(file, ios::in);
		char a;
		int position, l = 1;
		string line;
		bool check = false;
		bool appear = false;
		while (getline(fp, line))
		{
			int j = 0, i = 0;
			vector<int> pos;
			while (j < line.length())
			{
				
				if (line[j] == word[i] && line.length() - j >= word.length())
				{
					position = j;
					//cout << position << endl;
					for (i = 0; i < word.length(); i++)
					{
						if (line[j] == word[i])
						{
							check = true;
							j++;
						}
						else
						{
							check = false;
							j++;
							break;
						}
					}
					if (check == true)
					{
						pos.push_back(position + 1);
						appear = true;
						check = false;
						
					}
					i = 0;
					
				}
				else
				{
					j++;
				}
				
				
			}
			if (pos.size() >= 1)
			{
				cout << "The word " << word << " find at line " << l << ", position:";
				cout << pos[0];
				for (int k = 1; k < pos.size(); k++)
					cout << ", " << pos[k];
				cout << endl;
			}
			l++;
		}
		
		if (appear == false)
		{
			cout << "The word " << word << " not exist in this file." << endl;
		}
	}

	system("pause");
}