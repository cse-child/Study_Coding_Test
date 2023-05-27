#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int hap = 1;
	int i = 1;
	int N;
	cin >> N;

	while (hap < N)
	{
		hap += (6 * i);
		i++;
	}
	
	cout << i << endl;

	return 0;
}