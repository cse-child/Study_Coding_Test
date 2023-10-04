#include <iostream>

using namespace std;

/* �����佺�׳׽��� ü - �Ҽ�ã�� �˰��� */
/* ������ ������ 1 ~ 1000 �̶�� ���� */

int main()
{
	int n = 5;
	bool check[6];

	memset(check, true, sizeof(check)); // �迭 true�� ���� ä���

	check[0] = check[1] = false; // 0�� 1�� �Ҽ��� �ƴϹǷ� false

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