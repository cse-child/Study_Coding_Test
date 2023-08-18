#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
char map[1001][1001];
bool visit[1001][1001];

int cnt = 1;
int minCnt = 1001;

void DFS(int x, int y, bool crash)
{
	if(x == N && y == M)
	{
		if (minCnt > cnt)
			minCnt = cnt;
		return;
	}

	int moveX[4] = { 0, 0, -1, 1 };
	int moveY[4] = { -1, 1, 0, 0 };
	for(int i = 0; i < 4; i++)
	{
		int mx = x + moveX[i];
		int my = y + moveY[i];

		if (mx < 1 || my < 1 || mx > N || my > M) continue;
		if (visit[mx][my]) continue;
		if (crash && map[mx][my] == '1') continue;

		if (!crash && map[mx][my] == '1') // 벽을 부수고 감
		{
			crash = true;
			visit[mx][my] = true;
			cnt++;
			DFS(mx, my, crash);
			crash = false;
			visit[mx][my] = false;
			cnt--;
		}
		else
		{
			visit[mx][my] = true;
			cnt++;
			DFS(mx, my, crash);
			visit[mx][my] = false;
			cnt--;
		}
	}
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

	visit[1][1] = true;
	DFS(1, 1, false);

	if (minCnt == 1)
		cout << "-1";
	else
		cout << minCnt + 1;

	return 0;
}