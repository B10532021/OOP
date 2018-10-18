#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, M, Q;
	while (cin >> N >> M >> Q)
	{
		int **relation = new int*[N + 1];
		for (int i = 0; i < N + 1; i++)
		{
			relation[i] = new int[N + 1];
		}
		for(int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
			{
				relation[i][j] = 0;
			}

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			relation[a][b] = 1;
			relation[b][a] = 1;
			
		}
		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (relation[i][j] == 1)
				{
					for (int k = 1; k <= N; k++)
					{
						if (relation[j][k] == 1)
						{
							relation[i][k] = 1;
						}
					}
				}
			}
		for (int i = 0; i < Q; i++)
		{
			int a, b;
			cin >> a >> b;
			if (relation[a][b] == 1)
			{
				cout << ":)" << endl;
			}
			else
			{
				cout << ":(" << endl;
			}
		}
	}
	system("pause");
}