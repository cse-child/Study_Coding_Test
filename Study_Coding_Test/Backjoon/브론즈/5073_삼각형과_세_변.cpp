#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> results;

	while(true)
	{
		int x, y, z;
		cin >> x >> y >> z;

		int max = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);

		if (x == y && y == z)
		{
			if (x == 0) break;
			results.push_back("Equilateral");
		}

		else if (max >= x + y + z - max)
			results.push_back("Invalid");

		else if (x != y && y != z && x != z)
			results.push_back("Scalene");

		else
			results.push_back("Isosceles");
	}

	for (string r : results)
		cout << r << "\n";

	return 0;
}