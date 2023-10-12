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

	// �� �湮�ؾ� �ϴ� ��� v1�� v2�� ��츦 ������ ���ͽ�Ʈ�� �˰��� ����
	// 1. Start ���� v1������ �Ÿ� & Start ���� v2������ �Ÿ�
	// 2. v1���� v2������ �Ÿ� == v2���� v1������ �Ÿ� (������ �׷���)
	// 3. v2���� End ������ �Ÿ� (v1���� End������ �Ÿ��� 2������ �ѹ��� ���� �� �ִ�)

	int s_v1, s_v2, v1_v2, v1_e, v2_e;

	// 1��° case : Start -> v1, Start -> v2
	Dijkstra(1);
	s_v1 = dist[v1];
	s_v2 = dist[v2];

	//2��° case : v1 -> v2 (= v2 -> v1)
	Dijkstra(v1);
	v1_v2 = dist[v2];
	v1_e = dist[N];

	// 3��° case : v2 -> End
	Dijkstra(v2);
	v2_e = dist[N];

	// ���� ����
	int result = INF;
	result = min(result, s_v1 + v1_v2 + v2_e);
	result = min(result, s_v2 + v1_v2 + v1_e);

	if (result == INF || v1_v2 == INF)
		result = -1;

	cout << result;

	return 0;
}