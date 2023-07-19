#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, queue<pair<int, int>>> vPos;

void SpreadVirus(vector<vector<int>>& arr, int& vNum)
{
	int moveX[4] = { -1,1,0,0 };
	int moveY[4] = { 0,0,-1,1 };

	int size = vPos[vNum].size();
	for (int i = 0; i < size; i++)
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
			vPos[vNum].push({ x, y });
		}
	}
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

	for (int s = 0; s < S; s++)
	{
		for (int k = 1; k <= K; k++)
			SpreadVirus(arr, k);
	}

	cout << arr[X - 1][Y - 1];

	return 0;
}

////////////////////////////////////////////////////////////////


/*

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<tuple<int, int, int>> virus;

void SpreadVirus(vector<vector<int>>& arr, tuple<int, int, int> n)
{
	int moveX[4] = { -1,1,0,0 };
	int moveY[4] = { 0,0,-1,1 };

	for (int m = 0; m < 4; m++)
	{
		int x = get<0>(n) + moveX[m];
		int y = get<1>(n) + moveY[m];

		if (x < 0 || x >= arr.size() || y < 0 || y >= arr.size()) continue;
		if (arr[x][y] != 0) continue;

		arr[x][y] = get<2>(n);
		virus.emplace_back(x, y, get<2>(n));
	}
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
				virus.emplace_back(i, j, arr[i][j]);
		}
	}

	// 바이러스 번호 순으로 오름차순 정렬
	sort(virus.begin(), virus.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
	{
		return get<2>(a) < get<2>(b);
	});

	int S, X, Y;
	cin >> S >> X >> Y;

	for (int s = 0; s < S; s++)
	{
		// 새로운 바이러스 감염 전 존재하는 바이러스 먼저 한 턴 퍼뜨리기
		int size = virus.size();
		for (int i = 0; i < size; i++)
		{
			SpreadVirus(arr, virus.front());
			virus.pop_front();
		}
	}

	cout << arr[X - 1][Y - 1];

	return 0;
}

 */