#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[801];
vector<int> dist(801);

void Dijkstra(int start)
{
	fill(dist.begin(), dist.end(), INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, E;
	cin >> N >> E;
	for(int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	int v1, v2;
	cin >> v1 >> v2;

	// 꼭 방문해야 하는 노드 v1과 v2의 경우를 나눠서 다익스트라 알고리즘 수행
	// 1. Start 부터 v1까지의 거리 & Start 부터 v2까지의 거리
	// 2. v1부터 v2까지의 거리 == v2부터 v1까지의 거리 (무방향 그래프)
	// 3. v2부터 End 까지의 거리 (v1부터 End까지의 거리는 2번에서 한번에 구할 수 있다)

	int s_v1, s_v2, v1_v2, v1_e, v2_e;

	// 1번째 case : Start -> v1, Start -> v2
	Dijkstra(1);
	s_v1 = dist[v1];
	s_v2 = dist[v2];

	//2번째 case : v1 -> v2 (= v2 -> v1)
	Dijkstra(v1);
	v1_v2 = dist[v2];
	v1_e = dist[N];

	// 3번째 case : v2 -> End
	Dijkstra(v2);
	v2_e = dist[N];

	// 최종 연산
	int result = INF;
	result = min(result, s_v1 + v1_v2 + v2_e);
	result = min(result, s_v2 + v1_v2 + v1_e);

	if (result == INF || v1_v2 == INF)
		result = -1;

	cout << result;

	return 0;
}