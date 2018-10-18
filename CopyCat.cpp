#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	string input, output;
	ifstream filein;
	ofstream fileout;
	filein.open(argv[1], ios::in | ios::binary);
	fileout.open(argv[2], ios::out | ios::binary);

	if (filein.is_open() && fileout.is_open())
	{
		while (!filein.eof())
		{
			fileout.put(filein.get());
		}
	}
	filein.close();
	fileout.close();
	return 0;
}