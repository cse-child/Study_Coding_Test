#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// 2¿ø, 5¿ø
	int n;
	cin >> n;

	int cnt = 0;
	while(n > 0)
	{
		if(n%5 == 0)
		{
			cnt += (n / 5);
			n %= 5;
		}
		else
		{
			cnt += 1;
			n -= 2;
		}
	}

	if (n != 0)
		cnt = -1;

	cout << cnt;

	return 0;
}