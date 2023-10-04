#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> num = { 1,2,3,4,5,6,7,8,9 };

	bool isFound = binary_search(num.begin(), num.end(), 3);
	cout << isFound << endl << endl;

	vector<int> times = { 1000000000, 10 };
	cout << times[0] << endl;
	cout << (long long)times[0] << endl;

	cout << times[0] * 3 << endl;
	cout << (long long)times[0] * 3 << endl;
}
