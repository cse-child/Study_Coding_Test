#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tiii;

int parent[1001];

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) 
		return false;

	parent[a] = b;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int result = 0;
	int N, M;
	cin >> N >> M;

	vector<tiii> network;
	for(int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		network.emplace_back(a, b, c);
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	sort(network.begin(), network.end(), [](const tiii& a, const tiii& b)
	{
		return get<2>(a) < get<2>(b);
	});

	for(int i = 0; i < M; i++)
	{
		if (Union(get<0>(network[i]), get<1>(network[i])))
			result += get<2>(network[i]);
	}

	cout << result;

	return 0;
}