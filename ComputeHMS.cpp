#include<iostream>
using namespace std;

int main()
{
	unsigned long long int time[3];//用usigned long long int以確保數字夠大不會超過上限
	while (cin >> time[0])
	{
		//time[0]表示秒、time[1]表示分、time[2]表示小時
		time[1] = time[0] / 60;//看有幾分鐘
		time[0] = time[0] % 60;//看總秒數除以60的餘數，即為秒
		time[2] = time[1] / 60;//看有幾小時
		time[1] = time[1] % 60;//看總分鐘數除以60的餘數，即為分鐘

		cout << time[2] << " hours " << time[1] << " minutes and " << time[0] << " seconds" << endl;
	}
	
	return 0;
}