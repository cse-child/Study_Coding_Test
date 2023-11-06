#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long S;
	cin >> S;

	long long sum = 0;
	for(int i = 1;;i++)
	{
		sum += i;

		if (sum > S)
		{
			cout << i - 1;
			break;
		}
	}
	return 0;
}