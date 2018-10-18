#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class student
{
private:
	float score;
	string name;
	int number;
	float total;
	float percentage;
public:
	void setDetails();
	void getDetails();
};


void student::setDetails()
{
	cin >> name >> number >> total;
	percentage = total / 300 * 100;
}

void student::getDetails()
{
	cout << "Student details:" << endl;
	cout << "Name:" << name << endl;
	cout << "Student Number:" << number << endl;
	cout << "Total:" << total << endl;
	if (total > 300)
	{
		cout << "Total scores should be under 300!" << endl;
	}
	cout << "Percentage:" << percentage << endl;
	/*Name:ming
	Student Number : 44
	Total : 36
	Percentage : 12*/
}

/*
Please implement your class "student" and functions here.
*/
int main()
{
	student std[MAX];       //array of objects creation
	int numberOfStudents;

	cout << "Enter total number of students: ";
	cin >> numberOfStudents;

	for (int i = 0; i< numberOfStudents; i++) {
		cout << "Enter details of student " << i + 1 << ":\n";
		std[i].setDetails();
	}

	cout << endl;

	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Details of student " << (i + 1) << ":\n";
		std[i].getDetails();
		cout << endl;
	}

	system("pause");
	return 0;
}