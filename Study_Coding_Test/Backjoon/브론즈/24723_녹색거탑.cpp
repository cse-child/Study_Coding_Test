#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	// 1: 2
	// 2: 4
	// 3: 8
	cout << pow(2, N);

	return 0;
}