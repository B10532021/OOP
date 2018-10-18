#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	double avg, CSD, sum = 0, num;
	vector <double> number;

	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			number.push_back(num);
			sum += num;
		}

		avg = (double)sum / n;

		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += pow(((double)number[i] - avg), 2);
		}

		CSD = sqrt(sum / n);
		cout << "Average:" << avg << "	" << "Standard deviation:" << setprecision(6) << CSD << endl;

		number.clear();
		sum = 0;
		avg = 0;
	}
	
	system("pause");
	return 0;

}