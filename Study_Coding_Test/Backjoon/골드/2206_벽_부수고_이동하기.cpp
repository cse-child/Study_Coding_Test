#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001][2];
int cnt;

int BFS()
{
	queue<tuple<int, int, int>> que;
	que.push({ 1,1,1 });
	dist[1][1][1] = 1;

	while (!que.empty())
	{
		int x = get<0>(que.front());
		int y = get<1>(que.front());
		int crash = get<2>(que.front());
		que.pop();

		if (x == N && y == M)
			return dist[x][y][crash];

		int moveX[4] = { 0, 0, -1, 1 };
		int moveY[4] = { -1, 1, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			int mx = x + moveX[i];
			int my = y + moveY[i];

			if (mx < 1 || my < 1 || mx > N || my > M) continue;

			// ���� ���� �μ��� ���
			if (map[mx][my] == 1 && crash == 1)
			{
				dist[mx][my][crash - 1] = dist[x][y][crash] + 1;
				que.push({ mx, my, crash - 1 });
			}
			// �ո����� �μ��� �ʰ� ���� ���
			else if (map[mx][my] == 0 && dist[mx][my][crash] == 0)
			{
				dist[mx][my][crash] = dist[x][y][crash] + 1;
				que.push({ mx,my,crash });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char input;
			cin >> input;
			map[i][j] = input - '0';
		}
	}

	cout << BFS();

	return 0;
}