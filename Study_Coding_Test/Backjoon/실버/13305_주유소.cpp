#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> bridge(N - 1);
	for (int& b : bridge)
		cin >> b;

	vector<int> oilPrice(N);
	for (int& o : oilPrice)
		cin >> o;

	long long result = 0;
	long long minPrice = 1000000000;
	for(int i = 0; i < N-1; i++)
	{
		if (oilPrice[i] < minPrice)
			minPrice = oilPrice[i];
		result += minPrice * bridge[i];
	}
	cout << result;
	return 0;
}