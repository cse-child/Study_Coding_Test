#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int sum = 0;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		sum += i;

	cout << sum << endl;
	return 0;
}