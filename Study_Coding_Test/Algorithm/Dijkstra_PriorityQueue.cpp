#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define N 3

using namespace std;

vector<pair<int, int>> nodes[N];
int dist[N];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first; // 우선순위큐가 내림차순이므로 -처리
		int here = pq.top().second;
		pq.pop();

		// 이미 최단거리 정보라면 넘어가기
		if (dist[here] < cost) continue;

		for (int i = 0; i < nodes[here].size(); i++)
		{
			int via_cost = cost + nodes[here][i].first;

			// here을 경유하는 경로가 더 빠르다면 갱신
			if (via_cost < dist[nodes[here][i].second])
			{
				dist[nodes[here][i].second] = via_cost;
				pq.push({ -via_cost, nodes[here][i].second });
			}
		}
	}
}

int main()
{
	for (int i = 0; i < N; i++)
		dist[i] = INF;

	nodes[0].push_back({ 5,1 });
	nodes[0].push_back({ 1,2 });
	nodes[2].push_back({ 3,1 });

	dijkstra(0);

	for (int i = 0; i < N; i++)
		cout << dist[i] << endl;

	return 0;
}