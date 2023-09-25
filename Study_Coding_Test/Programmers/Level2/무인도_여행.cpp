// 17Ка?

#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[101][101];
int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };

int BFS(const vector<string>& maps, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	int result = maps[x][y];

	while (!que.empty())
	{
		pair<int, int> pos = que.front();
		que.pop();

		for(int i = 0; i < 4; i++)
		{
			int dx = pos.first + moveX[i];
			int dy = pos.second + moveY[i];

			if (dx < 0 || dy < 0 || dx >= maps.size() || dy >= maps[0].size()) continue;
			if (maps[dx][dy] == 'X') continue;
			if (visit[dx][dy]) continue;

			visit[dx][dy] = true;
			que.push({ dx, dy });
			result += maps[dx][dy];
		}
	}

	return result;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;

	for(int i = 0; i < maps.size(); i++)
	{
		for(int j = 0; j < maps[i].size(); j++)
		{
			if (maps[i][j] != 'X' && !visit[i][j])
			{
				int temp = BFS(maps, i, j);
				answer.push_back(temp);
			}
		}
	}

	if (answer.empty())
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	return 0;
}