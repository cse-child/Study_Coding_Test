#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[9];
bool visit[9];

void DFS(int depth)
{
	if(depth == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for(int i = 1; i <= N; i++)
	{
		if(depth == 0 || arr[depth-1] <= i)
		{
			arr[depth] = i;
			DFS(depth + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	DFS(0);

	return 0;
}