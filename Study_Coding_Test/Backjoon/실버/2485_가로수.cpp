#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> diff(N - 1);
	int temp1, temp2;
	cin >> temp1 >> temp2;
	diff[0] = temp2 - temp1;
	int gcd = diff[0];
	for(int i = 2; i < N; i++)
	{
		temp1 = temp2;
		cin >> temp2;
		diff[i - 1] = temp2 - temp1;
		gcd = GCD(gcd, diff[i - 1]);
	}

	int result = 0;
	for(int i = 0; i < diff.size(); i++)
		result += diff[i] / gcd-1;
	
	cout << result;

	return 0;
}