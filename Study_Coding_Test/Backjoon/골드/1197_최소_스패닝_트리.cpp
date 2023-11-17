#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<tuple<int, int, int>> graph;
int parent[10001];

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int A, int B)
{
	int a = Find(A);
	int b = Find(B);

	if (a == b)
		return false;

	parent[a] = b;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E;
	cin >> V >> E;
	for(int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph.emplace_back(A, B, C);
	}

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	sort(graph.begin(), graph.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
	{
		return get<2>(a) < get<2>(b);
	});

	int result = 0;
	for(int i = 0; i < E; i++)
	{
		if (Union(get<0>(graph[i]), get<1>(graph[i])))
			result += get<2>(graph[i]);
	}

	cout << result;
	return 0;
}