#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

#define INF 987654321

using namespace std;

vector<pair<int, int>> chicken;
vector<bool> bChicken;
vector<pair<int, int>> house;

int N, M;
int result = INF;

int GetChickenLength(const pair<int, int>& a, const pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void ChickenStreet(int count, int start)
{
	if(count >= M)
	{
		//TODO: 도시의 치킨 거리
		int totalLength = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int minLength = INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				if(bChicken[j])
					minLength = min(minLength, GetChickenLength(house[i], chicken[j]));
			}
			totalLength += minLength;
		}
		result = min(result, totalLength);
		return;
	}

	for (int i = start; i < chicken.size(); i++)
	{
		if (!bChicken[i])
		{
			bChicken[i] = true;
			ChickenStreet(count + 1, i);
			bChicken[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
				house.emplace_back(i, j);
			else if (input == 2)
			{
				chicken.emplace_back(i, j);
				bChicken.emplace_back(false);
			}
		}
	}

	ChickenStreet(0, 0);

	cout << result;
	return 0;
}