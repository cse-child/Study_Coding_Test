#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

// ¾à 45ºÐ..?

using namespace std;

map<int, queue<pair<int, int>>> vPos;

void SpreadVirus(vector<vector<int>>& arr, int& vNum)
{
	int moveX[4] = { -1,1,0,0 };
	int moveY[4] = { 0,0,-1,1 };

	vector<pair<int, int>> savePos;
	while(!vPos[vNum].empty())
	{
		int vX = vPos[vNum].front().first;
		int vY = vPos[vNum].front().second;
		vPos[vNum].pop();

		for (int m = 0; m < 4; m++)
		{
			int x = vX + moveX[m];
			int y = vY + moveY[m];

			if (x < 0 || x >= arr.size() || y < 0 || y >= arr.size()) continue;
			if (arr[x][y] != 0) continue;

			arr[x][y] = vNum;
			savePos.emplace_back(x, y);
		}
	}

	for(int i = 0; i < savePos.size(); i++)
		vPos[vNum].push(savePos[i]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				vPos[arr[i][j]].push({ i, j });
		}
	}

	int S, X, Y;
	cin >> S >> X >> Y;

	for(int s = 0; s < S; s++)
	{
		for (int k = 1; k <= K; k++)
			SpreadVirus(arr, k);
	}
	
	cout << arr[X-1][Y-1];

	return 0;
}