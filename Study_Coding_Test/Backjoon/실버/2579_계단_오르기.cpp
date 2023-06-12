#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// [n][m] : n ���° ���, m ��� ���� (3�� ������ �ȵǹǷ� 2���� ����)
	// m = 0 : 1�� ����, m = 1 : 2�� ����
	int dp[301][2];
	int stair[301];

	int stairCnt;
	cin >> stairCnt;

	for (int i = 1; i <= stairCnt; i++)
		cin >> stair[i];

	dp[1][0] = stair[1]; // ù��° ��� �ʱ�ȭ

	for(int i = 2; i <= stairCnt; i++)
	{
		dp[i][1] = dp[i - 1][0] + stair[i];
		dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + stair[i];
	}

	cout << max(dp[stairCnt][0], dp[stairCnt][1]);

	return 0;
}