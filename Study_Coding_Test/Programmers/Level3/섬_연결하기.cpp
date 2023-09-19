#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> parent(101);

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

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;

	return true;
}

// [0]-[1]: 연결된 노드, [2]:비용
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	sort(costs.begin(), costs.end(), [](const vector<int>& cost1, const vector<int>& cost2){
		return cost1[2] < cost2[2];
	});

	for(int i = 0; i < costs.size(); i++)
	{
		if (Union(costs[i][0], costs[i][1]))
			answer += costs[i][2];
;	}

	return answer;
}

int main()
{
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
	solution(4, costs);
}