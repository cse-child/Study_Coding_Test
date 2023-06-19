#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int cnt;
};

bool check[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> maze(N, vector<char>(M));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> maze[i][j];

	queue<Node> queue;
	queue.push({0,0,1});
	check[0][0] = true;

	int moveX[4] = {0,0,-1,1};
	int moveY[4] = {-1,1,0,0};
	while(!queue.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			Node node = { queue.front().x + moveX[i], queue.front().y + moveY[i], queue.front().cnt + 1 };
		
			if (node.x < 0 || node.x >= N || node.y < 0 || node.y >= M) continue;
			if (maze[node.x][node.y] == '0') continue;
			if (check[node.x][node.y]) continue;

			if (node.x == N - 1 && node.y == M - 1)
			{
				cout << node.cnt;
				return 0;
			}

			queue.push(node);
			check[node.x][node.y] = true;
		}
		queue.pop();
	}

	return 0;
}