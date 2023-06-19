#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		int sum = i;
		int temp = i;
		while(temp > 0)
		{
			sum += (temp % 10);
			temp /= 10;
		}

		if(sum == N)
		{
			cout << i;
			return 0;
		}
	}

	cout << "0";
	return 0;
}