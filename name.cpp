#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
using namespace std;

/*template<class T>
class set_
{
private:
	vector<T> name_set;
public:
	set_();
	~set_();
	void add(T name);
	template<class T1>
	friend ostream& operator<<(ostream& output,  set_<T1>& Set_);
};
template<class T>
set_<T>::set_()
{
}

template<class T>
set_<T>::~set_()
{
}

template<class T>
void set_<T>::add(T name)
{
	for (int i = 0; i < name_set.size(); i++)
	{
		if (name == name_set[i])
		{
			return;
		}
	}
	name_set.push_back(name);
}


template<class T1>
ostream& operator<<(ostream& output, set_<T1>& Set_)
{
	for (int i = 0; i < Set_.name_set.size(); i++)
	{
		output << Set_.name_set[i] << endl;
	}
	return output;
}*/

int main()
{
	set<string> Set_;
	fstream fp("name.txt", ios::in);
	string first_name, last_name;
	while (fp >> first_name >> last_name)
	{
		string tempt = "";
		tempt = first_name + " " + last_name;
		Set_.insert(tempt);
	}
	for (auto i : Set_)
	{
		cout << i << endl;
	}
	system("pause");
}