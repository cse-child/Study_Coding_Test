#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string N;
	cin >> N;

	sort(N.begin(), N.end(), greater<char>());

	cout << N;

	return 0;
}