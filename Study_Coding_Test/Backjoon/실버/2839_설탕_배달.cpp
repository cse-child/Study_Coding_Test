#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int cnt = 0;
	while(N > 0)
	{
		if(N % 5 == 0)
		{
			cnt += (N / 5);
			cout << cnt;
			return 0;
		}
		N -= 3;
		cnt++;
	}
	if (N == 0)
		cout << cnt;
	else
		cout << "-1";
	return 0;
}