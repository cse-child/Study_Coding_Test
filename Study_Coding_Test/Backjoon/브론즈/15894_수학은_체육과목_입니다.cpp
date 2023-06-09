#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	// 1 : 4 ( 1*1)+1+(1*2) = 4
	// 2 : 8  (1 * 2)+2+(2*2) = 8 
	// 3 : 12 (1*3)+3+(3*2) = 12
	// 4 : 16
	// n : (1 * n) + n + (n * 2)

	cout << n * 4 << endl;
	return 0;
}