#include <iostream>
#include <string>
#include <queue>

#define MAX 101

using namespace std;

int N, CompN;
int graph[MAX][MAX];
bool visit[MAX];
int cnt = 0;

void DFS(int node)
{
	visit[node] = true;
	cnt++;

	for(int i = 1; i <= N; i++)
	{
		if (!visit[i] && graph[node][i])
			DFS(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> CompN;
	for (int i = 0; i < CompN; i++)
	{
		int pos, next;
		cin >> pos >> next;
		graph[pos][next] = graph[next][pos] = 1;
	}

	DFS(1);
	cout << cnt-1;
	return 0;
}


/******************** BFS Ç®ÀÌ *********************
int N, CompN;
int graph[MAX][MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> CompN;
	for(int i = 0; i < CompN; i++)
	{
		int pos, next;
		cin >> pos >> next;
		graph[pos][next] = graph[next][pos] = 1;
	}

	queue<int> que;
	que.push(1);
	visit[1] = true;
	int count = 0;
	while(!que.empty())
	{
		int pos = que.front();
		que.pop();

		for(int i = 1; i <= N; i++)
		{
			if(!visit[i] && graph[pos][i] == 1)
			{
				que.push(i);
				visit[i] = true;
				count++;
			}
		}
	}

	cout << count;
	return 0;
}
******************************************************/