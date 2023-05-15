#include <iostream>
#define INF 1000000000
#define N 5

using namespace std;

int weight[N][N] =
{
	{0,	7,	4,	6,	1},
	{INF,0,	INF,INF,INF},
	{INF,2,	0,	5,	INF},
	{INF,3,	INF,0,	INF},
	{INF,INF,INF,1,	0}
};

bool visit[N];
int dist[N];
int minNode;

int GetMinimumNode()
{
	int min = INF;
	int minpos = 0;
	for (int i = 0; i < N; i++)
	{
		// 방문하지 않았고, 비용이 가장 작은 노드 탐색
		if (dist[i] < min && !visit[i])
		{
			min = dist[i];
			minpos = i;
		}
	}
	return minpos;
}

void dijkstra(int start)
{
	for (int i = 0; i < N; i++)
		dist[i] = weight[start][i];

	visit[start] = true;
	for (int i = 0; i < N - 1; i++)
	{
		minNode = GetMinimumNode();
		visit[minNode] = true;

		for (int j = 0; j < N; j++)
		{
			// 방문하지 않은 노드 중에, 경유하는 노드 경로가 기존 경로보다 더 가까워지면 갱신
			if (!visit[j] && (dist[minNode] + weight[minNode][j] < dist[j]))
				dist[j] = dist[minNode] + weight[minNode][j];
		}
	}
}

int main()
{
	dijkstra(0);

	for (int i = 0; i < N; i++)
		cout << dist[i] << " ";
	cout << endl;

	return 0;
}