#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string S;
	cin >> S;

	int result = 0;
	for(int i = 0; i < S.size(); i++)
	{
		if (S[i] != S[i + 1])
			result++;
	}
	if (result != 0)
		result /= 2;
	cout << result;

	return 0;
}