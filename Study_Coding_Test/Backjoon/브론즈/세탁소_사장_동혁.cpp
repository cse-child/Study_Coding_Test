#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	vector<int> money(testCase);
	for (int& m : money)
		cin >> m;

	// 1�޷� = 100��Ʈ
	// 124��Ʈ = 1.24�޷�
	int change[4] = { 25, 10, 5, 1 };
	
	for(int m : money)
	{
		for(int i = 0; i < 4; i++)
		{
			int divisor = m / change[i];
			if(divisor > 0)
			{
				m -= (divisor * change[i]);
				cout << divisor << " ";
			}
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return 0;
}