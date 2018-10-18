#include <iostream>
#include <string>
using namespace std;

int main()
{

		int a, b, N;
		while (cin >> a)
		{
			cin >> b >> N;
			cout << a / b << ".";
			a %= b;
			while (N--)
			{
				a *= 10;
				cout << a / b;
				a %= b;
			}
			cout << endl;
		}
		return 0;
}