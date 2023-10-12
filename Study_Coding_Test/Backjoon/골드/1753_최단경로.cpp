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
		graph[u].emplace_back(v, w); // �������, ���
	}
	fill(dist.begin(), dist.end(), INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // ���, �������			
	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;				// ���� �������� ���
		int cur = pq.top().second;				// ���� ���
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;		// ���� ���
			int nCost = graph[cur][i].second;	// ���� �������� ���

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