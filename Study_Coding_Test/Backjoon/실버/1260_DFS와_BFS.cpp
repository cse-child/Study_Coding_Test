#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<int> graph[1001];
vector<bool> visit(1001);

int N, M, V;

void DFS(int start)
{
	cout << start << ' ';
	visit[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (!visit[next])
		{
			visit[next] = true;
			DFS(next);
		}
	}
}

void BFS(int start)
{
	fill(visit.begin(), visit.end(), false);

	queue<int> que;
	que.push(start);
	visit[start] = true;

	while(!que.empty())
	{
		int node = que.front();
		que.pop();
		cout << node << ' ';

		for(int i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i];
			if(!visit[next])
			{
				visit[next] = true;
				que.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;

	for(int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(V);
	cout << '\n';
	BFS(V);

	return 0;
}