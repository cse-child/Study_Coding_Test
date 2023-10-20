#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> map(26, vector<int>(26));
vector<vector<bool>> visit(26, vector<bool>(26));

int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };

int BFS(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	visit[x][y] = true;
	int cnt = 1;

	while(!que.empty())
	{
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		for(int i = 0; i < 4; i++)
		{
			int mx = cx + moveX[i];
			int my = cy + moveY[i];

			if (mx < 0 || my < 0 || mx >= N || my >= N) continue;
			if (map[mx][my] == 0) continue;
			if (visit[mx][my]) continue;

			visit[mx][my] = true;
			que.push({ mx, my });
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			char input;
			cin >> input;
			map[i][j] = input-'0';
		}
	}

	vector<int> result;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] != 0 && !visit[i][j])
			{
				int temp = BFS(i, j);
				result.push_back(temp);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}