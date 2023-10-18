#include <vector>

using namespace std;

/* 기둥 설치 규칙 */
bool InstallPillar(const vector<vector<bool>>& pillar, const vector<vector<bool>>& floor, int x, int y)
{
	if (y == 1 || pillar[x][y - 1] || floor[x - 1][y] || floor[x][y])
		return true;
	return false;
}

/* 보 설치 규칙 */
bool InstallFloor(const vector<vector<bool>>& pillar, const vector<vector<bool>>& floor, int x, int y)
{
	if (pillar[x][y - 1] || pillar[x + 1][y - 1] || (floor[x - 1][y] && floor[x + 1][y]))
		return true;
	return false;
}

/* 구조물 규칙 검사 함수 */
bool CheckRules(vector<vector<bool>>& pillar, vector<vector<bool>>& floor, int n)
{
	for (int x = 0; x <= n + 1; x++)
	{
		for (int y = 0; y <= n + 1; y++)
		{
			if (pillar[x][y]) // 기둥 검사
			{
				pillar[x][y] = false; // 현재 기둥이 없다는 가정하에, 추가할 수 있는 조건인지 검사
				if (!InstallPillar(pillar, floor, x, y))
				{
					pillar[x][y] = true;
					return false;
				}
				pillar[x][y] = true;
			}
			if (floor[x][y]) // 보 검사
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

// x,y : 설치 지점
// a : 0 기둥, 1 보
// b : 0 삭제, 1 설치
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<bool>> pillar(n + 2, vector<bool>(n + 2));	// 기존 크기에 한 칸 더 크게 생성
	vector<vector<bool>> floor(n + 2, vector<bool>(n + 2));		// 기존 크기에 한 칸 더 크게 생성

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0] + 1;		// 한 칸 더 크게 잡고, x < 0 경우 예외처리 안함
		int y = build_frame[i][1] + 1;		// 한 칸 더 크게 잡고, y < 0 경우 예외처리 안함
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		if (a == 0) // 기둥
		{
			if (b == 1) // 설치
			{
				if (InstallPillar(pillar, floor, x, y))
					pillar[x][y] = true;
			}
			else if (b == 0) // 삭제
			{
				pillar[x][y] = false; // 삭제됐다는 가정하에 구조물 검사
				if (!CheckRules(pillar, floor, n))
					pillar[x][y] = true; // 구조물 규칙에 어긋나면 원상복구
			}
		}
		else if (a == 1) // 보 설치
		{
			if (b == 1) // 설치
			{
				if (InstallFloor(pillar, floor, x, y))
					floor[x][y] = true;
			}
			else if (b == 0) // 삭제
			{
				floor[x][y] = false; // 삭제됐다는 가정하에 구조물 검사
				if (!CheckRules(pillar, floor, n))
					floor[x][y] = true; // 구조물 규칙에 어긋나면 원상복구
			}
		}
	}

	vector<vector<int>> result;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			if (pillar[i][j])
				result.push_back({ i - 1,j - 1,0 });	// 한 칸 크게 잡은거 돌려놓으며 추가
			if (floor[i][j])
				result.push_back({ i - 1,j - 1,1 });	// 한 칸 크게 잡은거 돌려놓으며 추가
		}
	}
	return result;
}