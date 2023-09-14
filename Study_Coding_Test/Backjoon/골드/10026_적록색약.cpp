// 20ºÐ ÄÆ ¤¾¤¾
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
char color[101][101];
bool visit_RGB[101][101];
bool visit_RG[101][101];

void BFS(int x, int y, bool rg)
{
	char baseColor = color[x][y];
	queue<pair<int, int>> que;
	que.push({ x, y });

	int moveX[4] = { -1, 1, 0, 0 };
	int moveY[4] = { 0, 0, -1, 1 };
	while(!que.empty())
	{
		pair<int, int> pos = que.front();
		que.pop();

		for(int i = 0; i < 4; i++)
		{
			int mx = pos.first + moveX[i];
			int my = pos.second + moveY[i];

			if (mx < 0 || my < 0 || mx >= N || my >= N) continue;

			if(!rg)
			{
				if (visit_RGB[mx][my]) continue;
				if (color[mx][my] != baseColor) continue;

				visit_RGB[mx][my] = true;
			}
			else
			{
				if (visit_RG[mx][my]) continue;
				if (baseColor == 'B' && color[mx][my] != baseColor) continue;
				if ((baseColor == 'R' || baseColor == 'G')
					&& (color[mx][my] != 'R' && color[mx][my] != 'G')) continue;

				visit_RG[mx][my] = true;
			}
			que.push({ mx, my });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> color[i][j];

	int rgbCnt = 0;
	int rgCnt = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(!visit_RGB[i][j])
			{
				BFS(i, j, false);
				rgbCnt++;
			}
			if(!visit_RG[i][j])
			{
				BFS(i, j, true);
				rgCnt++;
			}
		}
	}

	cout << rgbCnt << ' ' << rgCnt;

	return 0;
}