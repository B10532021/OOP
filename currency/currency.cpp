#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string country[3] = {"Japan", "Korean", "America"};
	string crty;
	int money;
	float J_currency = 3.5778, K_currency = 34.1180, A_currency = 0.0339, get;
	while(cin >> crty)
	{
		if (crty == country[0])
		{
			cin >> money;
			get = money * J_currency;
			cout << setw(6) << "TWD" << setw(12) << "JYP" << endl;
			cout << setw(6) << money << setw(12) << get << endl; 
		}
		else if (crty == country[1])
		{
			cin >> money;
			get = money * K_currency;
			cout << setw(6) << "TWD" << setw(12) << "KRW" << endl;
			cout << setw(6) << money << setw(12) << get << endl; 
		}
		else if(crty == country[2])
		{
			cin >> money;
			get = money * A_currency;
			cout << setw(6) << "TWD" << setw(12) << "USD" << endl;
			cout << setw(6) << money << setw(12) << get << endl; 
		}
		else
		{
			cin >> money;
			cout << "We don't provide the exchange of this country." << endl;
		}
	}

	
}
