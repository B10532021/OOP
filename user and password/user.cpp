#include "user.h"

namespace
{
	string username;
	bool isValid()
	{
		if (username.length() != 8)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < username.length(); i++)
			{
				if (username[i] < 'A' || (username[i] > 'Z' &&  username[i] < 'a') || username[i] > 'z')
				{
					return 0;
				}
			}
			return 1;
		}
	}
}
namespace Authenticate
{
	
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}
	string getUserName()
	{
		return username;
	}

}
