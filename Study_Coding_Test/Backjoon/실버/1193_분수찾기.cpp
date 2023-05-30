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

	// 1. 찾고자 하는 숫자가 몇번째 대각선에 위치하는지 찾기
	int i = 0;
	while(x > 0)
	{
		i++;
		x -= i;
	}

	// 2. 대각선이 홀수번째인지 짝수번째인지 구별한 뒤,
	// 각각의 경우에 따라 x값을 반전하여 출력
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