#include<vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 100000000
using namespace std;

vector<vector<int>> Maps;
bool visit[101][101];

int result = MAX;

struct Node
{
	int x;
	int y;
	int cnt;
};

void BFS(Node node)
{
	queue<Node> que;
	que.push(node);

	int moveX[4] = { -1, 1, 0, 0 };
	int moveY[4] = { 0, 0, -1, 1 };
	while (!que.empty())
	{
		Node pos = que.front();
		que.pop();

		if (pos.x == Maps[0].size() - 1 && pos.y == Maps.size() - 1)
		{
			result = min(result, pos.cnt+1);
		}

		for (int i = 0; i < 4; i++)
		{
			int x = pos.x + moveX[i];
			int y = pos.y + moveY[i];

			if (x < 0 || y < 0 || x >= Maps[0].size() || y >= Maps.size()) continue;
			if (Maps[x][y] == 0) continue;
			if (visit[x][y]) continue;

			visit[x][y] = true;
			que.push({ x, y, pos.cnt + 1 });
		}
	}

}

int solution(vector<vector<int> > maps)
{
	Maps = maps;

	BFS({ 0,0,0 });

	return result == MAX ? -1 : result;
}

int main()
{
	vector<vector<int> > maps = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
	cout << solution(maps);
}