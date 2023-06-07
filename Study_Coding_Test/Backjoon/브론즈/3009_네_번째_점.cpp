#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	map<int, int> X;
	map<int, int> Y;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		X[x]++;
		Y[y]++;
	}
	
	for (pair<int, int> xCnt : X)
	{
		if (xCnt.second % 2 == 1)
			cout << xCnt.first << " ";
	}

	for (pair<int, int> yCnt : Y)
	{
		if (yCnt.second % 2 == 1)
			cout << yCnt.first << endl;
	}
	
	return 0;
}


/* 간단버전 */
/*

int main()
{
	int x[3];
	int y[3];
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	if(x[0] == x[1])
		cout << x[2] << " ";
	else if(x[0] == x[2])
		cout << x[1] << " ";
	else
		cout << x[0] << " ";

	if(y[0] == y[1])
		cout << y[2];
	else if(y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];
}

*/