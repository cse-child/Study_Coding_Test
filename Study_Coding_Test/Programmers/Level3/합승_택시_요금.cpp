#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[201];
vector<int> Dist;
vector<int> sDist;

void Dijkstra(const vector<vector<int>>& fares, vector<int>& dist, int start)
{
	fill(dist.begin(), dist.end(), INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
	que.push({ 0, start });
	dist[start] = 0;

	while (!que.empty())
	{
		int cost = que.top().first;
		int node = que.top().second;
		que.pop();

		for (int i = 0; i < graph[node].size(); i++)
		{
			int nNode = graph[node][i].first;
			int nCost = graph[node][i].second;
			if (dist[nNode] > nCost + cost)
			{
				dist[nNode] = nCost + cost;
				que.push({ dist[nNode], nNode });
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	sDist.resize(n + 1);
	Dist.resize(n + 1);

	for (int i = 0; i < fares.size(); i++)
	{
		graph[fares[i][0]].emplace_back(fares[i][1], fares[i][2]);
		graph[fares[i][1]].emplace_back(fares[i][0], fares[i][2]);
	}

	int result = INF;
	int s_i, i_a, i_b;

	Dijkstra(fares, sDist, s);
	for (int i = 1; i <= n; i++)
	{
		s_i = sDist[i];
		if (s_i == INF) continue;

		Dijkstra(fares, Dist, i);
		i_a = Dist[a];
		i_b = Dist[b];

		result = min(result, s_i + i_a + i_b);
	}
	return result;
}

int main()
{
	//vector<vector<int>> fares = { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25 } };
	//cout << solution(6, 4, 6, 2, fares);

	vector<vector<int>> fares = { {5, 7, 9},{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6} };
	cout << solution(7,3,4,1, fares);
}
