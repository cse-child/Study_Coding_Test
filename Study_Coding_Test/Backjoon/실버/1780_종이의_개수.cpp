#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int minusN;
int zeroN;
int plusN;

bool CheckArea(int x, int y, int length)
{
	for(int i = x; i < x+length; i++)
	{
		for(int j = y; j < y+length; j++)
		{
			if (paper[x][y] != paper[i][j])
				return false;
		}
	}

	if (paper[x][y] == -1)
		minusN++;
	else if (paper[x][y] == 0)
		zeroN++;
	else if (paper[x][y] == 1)
		plusN++;
	return true;
}

void SlicePaper(int x, int y, int length)
{
	if (!CheckArea(x, y, length))
	{
		int size = length / 3;
		SlicePaper(x, y, size);
		SlicePaper(x + size, y, size);
		SlicePaper(x + size + size, y, size);
		SlicePaper(x, y + size, size);
		SlicePaper(x + size, y + size, size);
		SlicePaper(x + size + size, y + size, size);
		SlicePaper(x, y + size + size, size);
		SlicePaper(x + size, y + size + size, size);
		SlicePaper(x + size + size, y + size + size, size);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	paper.resize(N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			paper[i].push_back(temp);
		}
	}

	SlicePaper(0, 0, N);

	cout << minusN << '\n';
	cout << zeroN << '\n';
	cout << plusN << '\n';

	return 0;
}