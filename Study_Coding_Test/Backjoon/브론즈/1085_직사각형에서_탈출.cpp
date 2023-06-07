#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> distance = { abs(x - w), abs(y - h), x, y };

	cout << *min_element(distance.begin(), distance.end()) << endl;

	return 0;
}