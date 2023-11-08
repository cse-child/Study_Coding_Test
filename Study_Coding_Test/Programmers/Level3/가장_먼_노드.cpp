#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<int> graph[20001];
vector<int> dist(20001);
int MaxDist;

void BFS(int start)
{
	fill(dist.begin(), dist.end(), INF);

	queue<int> que;
	que.emplace(start);
	dist[start] = 0;

	while(!que.empty())
	{
		int node = que.front();
		que.pop();

		for(int i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i];
			if(dist[next] == INF)
			{
				dist[next] = dist[node] + 1;
				MaxDist = max(MaxDist, dist[next]);
				que.emplace(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {

	// 가장 멀리 떨어진 노드 : 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드
	for(int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0]].emplace_back(edge[i][1]);
		graph[edge[i][1]].emplace_back(edge[i][0]);
	}

	BFS(1);

	return count(dist.begin(), dist.end(), MaxDist);
}

int main()
{
	vector<vector<int>> edge = { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
	cout << solution(6, edge);
}