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
	const long double Rate = 0.01;//�M�w�����
	//while (cin >> n)
	//{
	cin >> n;
		guess = n / 2;
		do
		{
			previous_guess = guess;
			r = n / guess;
			guess = (guess + r) / 2;
		} while (Absolute(guess - previous_guess) > Rate);//�ݫe�@��guess�M�{�b��guess���t�ȬO�_�p��1%

		cout << fixed << setprecision(2) << guess << endl;//�L�X�p�ƫ�2�쪺���G
	//}
		system("pause");
	return 0;
}

