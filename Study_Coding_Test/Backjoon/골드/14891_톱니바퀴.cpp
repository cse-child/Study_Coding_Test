#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

vector<deque<int>> tire(4);
vector<bool> check(4);

bool CheckRight(int num)
{
	if (num >= 3) return false;
	if (check[num + 1]) return false;

	if (tire[num][2] + tire[num + 1][6] == 1)
		return true;
	return false;
}

bool CheckLeft(int num)
{
	if (num <= 0) return false;
	if (check[num - 1]) return false;

	if (tire[num][6] + tire[num - 1][2] == 1)
		return true;
	return false;
}

void RotateTire(int num, int rotate)
{
	if (num < 0 || num > 3) return;

	if (rotate == 1)
	{
		tire[num].push_front(tire[num].back());
		tire[num].pop_back();
	}
	else if (rotate == -1)
	{
		tire[num].push_back(tire[num].front());
		tire[num].pop_front();
	}
}

// 2, 6
// 1:시계방향, -1:반시계방향
void CheckTire(int num, int rotate)
{
	check[num] = true;

	if (CheckRight(num))
		CheckTire(num + 1, rotate*-1);
	
	if (CheckLeft(num))
		CheckTire(num - 1, rotate*-1);
	
	RotateTire(num, rotate);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char c;
			cin >> c;
			tire[i].push_back(c - '0');
		}
	}
	int K;
	cin >> K;
	while (K--)
	{
		int num, dir;
		cin >> num >> dir;

		fill(check.begin(), check.end(), false);

		CheckTire(num - 1, dir);
	}

	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += (tire[i][0] * (pow(2,i)));
	cout << sum;
	return 0;
}