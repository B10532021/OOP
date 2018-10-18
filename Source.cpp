#include <iostream>
using namespace std;
#define ARRAY_SIZE 10
template <class T>
void ItrSearch(T a[], T firstIndex, T finalIndex, T key, bool &found, T &location)
{
	found = 0;
	int pos;
	while(finalIndex >= firstIndex)
	{
		pos = (finalIndex + firstIndex) / 2;
		if (key == a[pos])
		{
			found = 1;
			location = pos;
			return;
		}
		else if (key < a[pos])
		{
			finalIndex = pos - 1;
		}
		else
		{
			firstIndex = pos + 1;
		}
	}
	return;
}
template <class T>
void recBinSrch(T a[], T firstIndex, T finalIndex, T key, bool &found, T &location)
{
	found = 0;
	if (firstIndex > finalIndex)
	{
		return;
	}
	int pos = (finalIndex + firstIndex) / 2;
	if (key == a[pos])
	{
		found = 1;
		location = pos;
		return;
	}
	else if (key < a[pos])
	{
		recBinSrch(a, firstIndex, pos - 1, key, found, location);
	}
	else
	{
		recBinSrch(a, pos + 1, finalIndex, key, found, location);
	}
	return;
}
int main()
{
	int a[10];
	const int finalIndex = ARRAY_SIZE - 1;
	int i;
	for (i = 0; i < ARRAY_SIZE; i++)
		a[i] = 3 * i;
	cout << "Array contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
	int key, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> key;
	cout << "\nTesting Template Iterative Binary Search\n";
	ItrSearch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	cout << "\nTesting Template Recursive Binary Search\n";
	recBinSrch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	system("pause");
	return 0;
}