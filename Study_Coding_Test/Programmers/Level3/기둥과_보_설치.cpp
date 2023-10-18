#include <vector>

using namespace std;

/* ��� ��ġ ��Ģ */
bool InstallPillar(const vector<vector<bool>>& pillar, const vector<vector<bool>>& floor, int x, int y)
{
	if (y == 1 || pillar[x][y - 1] || floor[x - 1][y] || floor[x][y])
		return true;
	return false;
}

/* �� ��ġ ��Ģ */
bool InstallFloor(const vector<vector<bool>>& pillar, const vector<vector<bool>>& floor, int x, int y)
{
	if (pillar[x][y - 1] || pillar[x + 1][y - 1] || (floor[x - 1][y] && floor[x + 1][y]))
		return true;
	return false;
}

/* ������ ��Ģ �˻� �Լ� */
bool CheckRules(vector<vector<bool>>& pillar, vector<vector<bool>>& floor, int n)
{
	for (int x = 0; x <= n + 1; x++)
	{
		for (int y = 0; y <= n + 1; y++)
		{
			if (pillar[x][y]) // ��� �˻�
			{
				pillar[x][y] = false; // ���� ����� ���ٴ� �����Ͽ�, �߰��� �� �ִ� �������� �˻�
				if (!InstallPillar(pillar, floor, x, y))
				{
					pillar[x][y] = true;
					return false;
				}
				pillar[x][y] = true;
			}
			if (floor[x][y]) // �� �˻�
			{
				floor[x][y] = false;
				if (!InstallFloor(pillar, floor, x, y))
				{
					floor[x][y] = true;
					return false;
				}
				floor[x][y] = true;
			}
		}
	}
	return true;
}

// x,y : ��ġ ����
// a : 0 ���, 1 ��
// b : 0 ����, 1 ��ġ
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<bool>> pillar(n + 2, vector<bool>(n + 2));	// ���� ũ�⿡ �� ĭ �� ũ�� ����
	vector<vector<bool>> floor(n + 2, vector<bool>(n + 2));		// ���� ũ�⿡ �� ĭ �� ũ�� ����

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0] + 1;		// �� ĭ �� ũ�� ���, x < 0 ��� ����ó�� ����
		int y = build_frame[i][1] + 1;		// �� ĭ �� ũ�� ���, y < 0 ��� ����ó�� ����
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		if (a == 0) // ���
		{
			if (b == 1) // ��ġ
			{
				if (InstallPillar(pillar, floor, x, y))
					pillar[x][y] = true;
			}
			else if (b == 0) // ����
			{
				pillar[x][y] = false; // �����ƴٴ� �����Ͽ� ������ �˻�
				if (!CheckRules(pillar, floor, n))
					pillar[x][y] = true; // ������ ��Ģ�� ��߳��� ���󺹱�
			}
		}
		else if (a == 1) // �� ��ġ
		{
			if (b == 1) // ��ġ
			{
				if (InstallFloor(pillar, floor, x, y))
					floor[x][y] = true;
			}
			else if (b == 0) // ����
			{
				floor[x][y] = false; // �����ƴٴ� �����Ͽ� ������ �˻�
				if (!CheckRules(pillar, floor, n))
					floor[x][y] = true; // ������ ��Ģ�� ��߳��� ���󺹱�
			}
		}
	}

	vector<vector<int>> result;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			if (pillar[i][j])
				result.push_back({ i - 1,j - 1,0 });	// �� ĭ ũ�� ������ ���������� �߰�
			if (floor[i][j])
				result.push_back({ i - 1,j - 1,1 });	// �� ĭ ũ�� ������ ���������� �߰�
		}
	}
	return result;
}