#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool visit[201];

void BFS(int findNum, int n, vector<vector<int>>& computers)
{
	queue<int> que;
	que.push(findNum);
	visit[findNum] = true;

	while (!que.empty())
	{
		int num = que.front();
		que.pop();

		for (int i = 0; i < n; i++)
		{
			if (num == i) continue;
			if (computers[num][i] == 0) continue;
			if (visit[i]) continue;

			visit[i] = true;
			que.push(i);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int cnt = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(!visit[i])
		{
			BFS(i, n, computers);
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	//vector<vector<int>> arr = { {1,1,0},{1,1,0},{0,0,1} }; // 2
	vector<vector<int>> arr = { {1,1,0},{1,1,1},{0,1,1} }; // 1
	cout << solution(3, arr);
}



//for(int i = 0; i < n; i++)
	//{
	//	for(int j = 0; j < n; j++)
	//	{
	//		if (i == j) continue;
	//		if (check[i][j]) continue;
	//		if (computers[i][j] == 0) continue;
	//
	//		check[i][j] = check[j][i] = true;
	//		cnt++;
	//	}
	//}