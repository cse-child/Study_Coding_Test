#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E, K;
	cin >> V >> E >> K;

	vector<pair<int, int>> graph[20001];
	vector<int> dist(20001);

	for(int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w); // 도착노드, 비용
	}
	fill(dist.begin(), dist.end(), INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 비용, 도착노드			
	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;				// 현재 노드까지의 비용
		int cur = pq.top().second;				// 현재 노드
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;		// 다음 노드
			int nCost = graph[cur][i].second;	// 다음 노드까지의 비용

			if(dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				pq.push({ dist[next], next });
			}
		}
	}

	for(int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}