#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> tree;
int parent[100001];

void DFS(int node)
{
	for(int i = 0; i < tree[node].size(); i++)
	{
		int next = tree[node][i];
		if(parent[next] == 0)
		{
			parent[next] = node;
			DFS(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	tree.resize(N+1);
	for (int i = 0; i < N-1; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		tree[temp1].emplace_back(temp2);
		tree[temp2].emplace_back(temp1);
	}

	DFS(1);	

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}