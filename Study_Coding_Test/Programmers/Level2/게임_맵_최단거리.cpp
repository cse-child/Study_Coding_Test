#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int cnt;
};

int solution(vector<vector<int>> maps)
{
	bool visit[100][100] = { false };
	queue<Node> que;

	visit[0][0] = true;
	que.push({ 0,0,1 });

	// ╩С : {0, -1}
	// го : {0, 1}
	// аб : {-1, 0}
	// ©Л : {1, 0}
	vector<int> visitX = { 0,0,-1,1 };
	vector<int> visitY = { -1,1,0,0 };
	while (!que.empty())
	{
		for (int i = 0; i < visitX.size(); i++)
		{
			Node dest = { que.front().x + visitX[i], que.front().y + visitY[i], que.front().cnt + 1 };

			if (dest.x < 0 || dest.y < 0 || dest.x >= maps[0].size() || dest.y >= maps.size()) continue;
			if (visit[dest.x][dest.y]) continue;
			if (maps[dest.y][dest.x] == 0) continue;


			if (dest.x == maps[0].size() - 1 && dest.y == maps.size() - 1)
				return dest.cnt;

			que.push(dest);
			visit[dest.x][dest.y] = true;
		}
		que.pop();
	}
	return -1;
}

//int main()
//{
//	vector<vector<int>> maps = { {1, 0, 1, 1, 1}, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 }};
//
//	solution(maps);
//}