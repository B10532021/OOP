#include <iostream>
#include <iomanip>
using namespace std;

long double Absolute(long double d)
{
	if (d < 0)
		return -d;
	return d;
}
int main()
{
	long double n, guess, r, previous_guess;
	const long double Rate = 0.01;//決定停止的值
	//while (cin >> n)
	//{
	cin >> n;
		guess = n / 2;
		do
		{
			previous_guess = guess;
			r = n / guess;
			guess = (guess + r) / 2;
		} while (Absolute(guess - previous_guess) > Rate);//看前一個guess和現在的guess的差值是否小於1%

		cout << fixed << setprecision(2) << guess << endl;//印出小數後2位的結果
	//}
		system("pause");
	return 0;
}

