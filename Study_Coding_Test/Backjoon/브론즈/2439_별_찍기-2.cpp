#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
			cout << ' ';
		for (int j = 0; j < i + 1; j++)
			cout << '*';
		cout << '\n';
	}

	return 0;
}