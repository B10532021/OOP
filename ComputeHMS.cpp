#include<iostream>
using namespace std;

int main()
{
	unsigned long long int time[3];//��usigned long long int�H�T�O�Ʀr���j���|�W�L�W��
	while (cin >> time[0])
	{
		//time[0]��ܬ�Btime[1]��ܤ��Btime[2]��ܤp��
		time[1] = time[0] / 60;//�ݦ��X����
		time[0] = time[0] % 60;//���`��ư��H60���l�ơA�Y����
		time[2] = time[1] / 60;//�ݦ��X�p��
		time[1] = time[1] % 60;//���`�����ư��H60���l�ơA�Y������

		cout << time[2] << " hours " << time[1] << " minutes and " << time[0] << " seconds" << endl;
	}
	
	return 0;
}