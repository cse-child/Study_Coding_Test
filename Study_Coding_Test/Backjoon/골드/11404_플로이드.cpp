#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int Max_Cost = 10000000; // Max 설정값 주의하기

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1, vector<int>(n+1));
	fill(graph.begin(), graph.end(), vector<int>(n+1, Max_Cost)); // 1. 무한대 초기화

	for (int i = 1; i <= n; i++)
		graph[i][i] = 0; // 자기자신 경로 초기화

	for(int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if(graph[start][end] > cost)
			graph[start][end] = cost;
	}

	for(int bridge = 1; bridge <= n; bridge++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n ;j++)
			{
				if (i == j) continue;
				if (bridge == i || bridge == j) continue;

				graph[i][j] = min(graph[i][j], graph[i][bridge] + graph[bridge][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if (graph[i][j] >= Max_Cost) // 문제 조건에 무한대인 경우 0으로 출력
				graph[i][j] = 0;

			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}