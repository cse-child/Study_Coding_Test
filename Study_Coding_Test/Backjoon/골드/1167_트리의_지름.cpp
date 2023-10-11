#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[100001];
bool visit[100001];
int maxDist = 0;
int maxNode = 0;

void DFS(int node, int dist)
{
	visit[node] = true;

	if(maxDist < dist)
	{
		maxNode = node;
		maxDist = dist;
	}

	for(int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i].first;
		int nextDist = graph[node][i].second;
		if(!visit[nextNode])
			DFS(nextNode, dist + nextDist);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V;
	cin >> V;
	for(int i = 0; i < V; i++)
	{
		int num, node, value;
		cin >> num;
		while(true)
		{
			cin >> node;
			if (node == -1) break;
			cin >> value;
			graph[num].emplace_back(node, value);
		}
	}

	DFS(1, 0);

	fill(begin(visit), end(visit), false);
	maxDist = 0;
	DFS(maxNode, 0);

	cout << maxDist;

	return 0;
}