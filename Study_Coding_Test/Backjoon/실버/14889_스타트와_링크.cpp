#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
int S[30][30];	// 21로 설정하면 Invalid Pointer 에러
bool check[30];

int diff = 100000;

void DFS(int size, int pos)
{
	if (size == N / 2)
	{
		int team1 = 0, team2 = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i] && check[j])
					team1 += S[i][j];
				else if (!check[i] && !check[j])
					team2 += S[i][j];
			}
		}
		int temp = abs(team1 - team2);
		if (diff > temp)
			diff = temp;

		return;
	}

	for (int i = pos; i < N; i++)
	{
		check[i] = true;
		DFS(size + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	DFS(0, 0);

	cout << diff;
	return 0;
}