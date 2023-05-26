#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int total, N;
	int sum = 0;
	cin >> total >> N;

	for(int i = 0; i < N; i++)
	{
		int price, cnt;
		cin >> price >> cnt;
		sum += (price * cnt);
	}	
	if (total == sum)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}