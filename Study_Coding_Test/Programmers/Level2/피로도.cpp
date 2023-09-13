// 10ºÐÄÆ ¤¾¤¾
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> visit;
int result = 0;

void DFS(int k, vector<vector<int>> dungeons, int cnt)
{
	result = max(result, cnt);

	for (int i = 0; i < dungeons.size(); i++)
	{
		if (k >= dungeons[i][0] && !visit[i])
		{
			visit[i] = true;
			DFS(k - dungeons[i][1], dungeons, cnt + 1);
			visit[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	visit.resize(dungeons.size());

	DFS(k, dungeons, 0);

	return result;
}