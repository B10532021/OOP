#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream fp;
	fp.open("words.txt", ios::in);
	string a;
	vector<string> words;

	while (fp >> a)
	{
		words.push_back(a);
	}
	string max = "";
	for (int i = 0; i < words.size() - 1; i++)
	{
		for (int j = i + 1; j < words.size(); j++)
		{
			bool same = 0;
			if (words[i].length() == words[j].length() && (words[i][0] == words[j][words[j].length() - 1] || words[i][0] - 32 == words[j][words[j].length() - 1] || words[i][0] + 32 == words[j][words[j].length() - 1]))
			{
				int len = words[i].length();
				for (int k = 0; k < len; k++)
				{
					if (words[i][k] == words[j][len - 1 - k])
					{
						same = 1;
					}
					else 
					{
						same = 0;
						break;
					}
				}
			}
			if (same && words[i].length() > max.length())
			{
				max = words[i];
				break;
			}
		}
	}

	cout << max << endl;
	fp.close();
	system("pause");
}