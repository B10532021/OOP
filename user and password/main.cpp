#include "user.h"
#include "password.h"

using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "
		<< getPassword() << endl;
	system("pause");
	return 0;
}