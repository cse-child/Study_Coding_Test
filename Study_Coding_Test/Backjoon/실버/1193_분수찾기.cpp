#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int x;
	cin >> x;

	// 1. ã���� �ϴ� ���ڰ� ���° �밢���� ��ġ�ϴ��� ã��
	int i = 0;
	while(x > 0)
	{
		i++;
		x -= i;
	}

	// 2. �밢���� Ȧ����°���� ¦����°���� ������ ��,
	// ������ ��쿡 ���� x���� �����Ͽ� ���
	if (i % 2 == 1)
		cout << 1 - x << "/" << i + x;
	else
		cout << i + x << "/" << 1 - x;

	return 0;
}

/*

	int cnt = 1;
	int x = 0, y = 0;
	int X;
	bool down = true;

	cin >> X;

	while (cnt < X)
	{
		if (y == 0)
		{
			x++;
			cnt++;
			if (cnt == X) break;

			y++;
			x--;
			down = true;
		}
		else if (x == 0)
		{
			y++;
			cnt++;
			if (cnt == X) break;

			x++;
			y--;
			down = false;
		}
		else
		{
			if (down)
			{
				y++;
				x--;
			}
			else
			{
				y--;
				x++;
			}
		}
		cnt++;
	}

	cout << (y + 1) << "/" << (x + 1) << endl;


 */