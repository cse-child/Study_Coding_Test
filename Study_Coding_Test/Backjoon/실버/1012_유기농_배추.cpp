#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 51;
int T;
int M, N, K;
int farm[MAX][MAX];
bool visit[MAX][MAX];

void BFS(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	visit[x][y] = true;

	int moveX[4] = { -1,1,0,0 };
	int moveY[4] = { 0,0,-1,1 };
	while (!que.empty())
	{
		pair<int, int> front = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> pos = { front.first + moveX[i], front.second + moveY[i] };

			if (pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M) continue;
			if (visit[pos.first][pos.second]) continue;
			if (farm[pos.first][pos.second] == 0) continue;

			visit[pos.first][pos.second] = true;
			que.push(pos);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		//for (int j = 0; j < N; j++)
		//	fill(farm[j], farm[j] + M, 0);
		memset(farm, 0, sizeof(farm));
		memset(visit, false, sizeof(visit));

		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> y >> x;
			farm[x][y] = 1;
		}

		int cnt = 0;
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				if (farm[x][y] == 0) continue;
				if (visit[x][y]) continue;
				BFS(x, y);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}