#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int length[3];
	cin >> length[0] >> length[1] >> length[2];

	sort(begin(length), end(length));

	if (length[0] + length[1] > length[2])
		cout << length[0] + length[1] + length[2];
	else
		cout << (length[0] + length[1]) * 2 - 1;

	return 0;
}