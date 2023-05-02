#include <iostream>

using namespace std;

/* 에라토스테네스의 체 - 소수찾기 알고리즘 */
/* 숫자의 범위가 1 ~ 1000 이라고 가정 */

int main()
{
	int n = 5;
	bool check[6];

	memset(check, true, sizeof(check)); // 배열 true로 전부 채우기

	check[0] = check[1] = false; // 0과 1은 소수가 아니므로 false

	for(int i = 2; i < sqrt(n); i++)
	{
		if(check[i])
		{
			for (int j = i + i; j <= n; j += i)
				check[j] = false;
		}
	}

	for(int i = 0; i <= n; i++)
	{
		if (check[i])
			cout << i << endl;
	}
}