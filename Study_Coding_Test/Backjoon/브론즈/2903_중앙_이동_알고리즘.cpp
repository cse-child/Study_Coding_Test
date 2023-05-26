#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int lineDot = 2;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		lineDot = lineDot + (lineDot - 1);

	cout << lineDot * lineDot << endl;

	return 0;
}