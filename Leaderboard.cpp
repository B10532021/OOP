#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
using namespace std;

void getHighScores(vector <string> &name, vector <int> &rank)
{
	for (int i = 0; i < rank.size() - 1; i++)
		for (int j = i + 1; j < rank.size(); j++)
		{
			int score_temp;
			string name_temp;
			if (rank[i] < rank[j])
			{
				score_temp = rank[i];
				rank[i] = rank[j];
				rank[j] = score_temp;

				name_temp = name[i];
				name[i] = name[j];
				name[j] = name_temp;
			}
		}
}

int main()
{
	fstream fs;
	string people;
	int point;
	vector <int> rank;
	vector <string> name;
	fs.open("scores.txt", ios::in);

	while (fs >> people)
	{
		fs >> point;
		name.push_back(people);
		rank.push_back(point);
	}
	getHighScores(name, rank);
	for (int i = 0; i < 3; i++)
	{
		cout << name[i] << endl;
		cout << rank[i] << endl;
	}

	system("pause");
	return 0;

}