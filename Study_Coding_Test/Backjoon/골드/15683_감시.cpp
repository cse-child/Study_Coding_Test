#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> office(9, vector<int>(9));
int cnt = 0;
vector<pair<int, int>> cameraPos;
int zeroCnt = 987654321;

void Monitor(int x, int y, int dir)
{
	dir %= 4;
	// 0: ©ч, 1: ╩С, 2: ©ю, 3: го
	int moveX[4] = { -1, 0, 1, 0 };
	int moveY[4] = { 0, -1, 0, 1 };

	while(true)
	{
		int mx = x + moveX[dir];
		int my = y + moveY[dir];
		x = mx; y = my;
		if (mx >= N || my >= M || mx < 0 || my < 0) break;
		if (office[mx][my] == 6) break;
		if (office[mx][my] != 0) continue;
		office[mx][my] = -1;
	}
}

void OnCCTV(int index)
{
	if(index == cameraPos.size())
	{
		int tempCnt = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if (office[i][j] == 0)
					tempCnt++;
			}
		}
		zeroCnt = min(zeroCnt, tempCnt);
		return;
	}

	int x = cameraPos[index].first;
	int y = cameraPos[index].second;
	vector<vector<int>> tempOffice = office;
	// 0: ©ч, 1: ╩С, 2: ©ю, 3: го
	for(int dir = 0; dir < 4; dir++)
	{
		switch (office[x][y])
		{
		case 1:
			Monitor(x, y, dir);
			break;
		case 2:
			Monitor(x, y, dir);
			Monitor(x, y, dir + 2);
			break;
		case 3:
			Monitor(x, y, dir);
			Monitor(x, y, dir + 1);
			break;
		case 4:
			Monitor(x, y, dir);
			Monitor(x, y, dir + 1);
			Monitor(x, y, dir + 2);
			break;
		case 5:
			Monitor(x, y, dir);
			Monitor(x, y, dir + 1);
			Monitor(x, y, dir + 2);
			Monitor(x, y, dir + 3);
			break;
		}

		OnCCTV(index + 1);

		office = tempOffice;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> office[i][j];
			if(office[i][j] != 0 && office[i][j] != 6)
				cameraPos.emplace_back(i, j);
		}
	}

	OnCCTV(0);

	cout << zeroCnt;
	return 0;
}