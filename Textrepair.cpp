#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
using std::ofstream;
using std::ifstream;

int main()
{
	ifstream file;
	ofstream out;
	file.open("Error.txt", ios::in);
	out.open("Correct.txt");
	char alpha;
	file.get(alpha);
	alpha = toupper(alpha);
	//cout << alpha << endl;
	out << alpha;
	while(file.get(alpha))
	{
		if (alpha == '.')
		{
			out << alpha;
			file.get(alpha);
			out << alpha;
			file.get(alpha);
			if (alpha == '\n')
			{
				out << alpha;
				file.get(alpha);
			}
			alpha = toupper(alpha);
			out << alpha;
		}
		else
		{
			alpha = tolower(alpha);
			out << alpha;
		}
	}
	//cout << "end";
	out.close();

}