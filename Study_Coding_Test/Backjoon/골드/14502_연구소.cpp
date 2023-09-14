#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> Map;
vector<pair<int, int>> Zero;
vector<bool> ZeroCheck;
int Result = 0;

int CheckSafeZone(const vector<vector<int>>& map)
{
	int result = 0;
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 0)
				result++;
		}
	}
	return result;
}

int SpreadVirus()
{
	vector<vector<int>> CopyMap = Map;
	queue<pair<int, int>> virus;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (CopyMap[i][j] == 2)
				virus.push({ i, j });
		}
	}

	int moveX[4] = { -1, 1, 0, 0 };
	int moveY[4] = { 0, 0, -1, 1 };
	while(!virus.empty())
	{
		pair<int, int> pos = virus.front();
		virus.pop();

		for(int i = 0; i < 4; i++)
		{
			int mx = pos.first + moveX[i];
			int my = pos.second + moveY[i];
			if (mx < 0 || my < 0 || mx >= N || my >= M) continue;

			if(CopyMap[mx][my] == 0)
			{
				CopyMap[mx][my] = 2;
				virus.push({ mx, my });
			}
		}
	}
	return CheckSafeZone(CopyMap);
}

void DFS(int wall)
{
	if(wall == 3)
	{
		Result = max(Result, SpreadVirus());
		return;
	}

	for(int i = 0; i < Zero.size(); i++)
	{
		if(!ZeroCheck[i])
		{
			ZeroCheck[i] = true;
			Map[Zero[i].first][Zero[i].second] = 1;
			DFS(wall + 1);
			ZeroCheck[i] = false;
			Map[Zero[i].first][Zero[i].second] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Map.resize(N);
	for (vector<int>& map : Map)
		map.resize(M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 0)
				Zero.push_back({ i, j });
		}
	}

	ZeroCheck.resize(Zero.size());

	DFS(0);

	cout << Result;
	return 0;
}