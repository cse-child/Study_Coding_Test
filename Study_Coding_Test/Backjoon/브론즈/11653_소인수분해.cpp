#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	while(N > 1)
	{
		for(int i = 2; i <= N; i++)
		{
			if(N % i == 0)
			{
				cout << i << endl;
				N /= i;
				if (N == i)
				{
					cout << i << endl;
					return 0;
				}
				i--;
				continue;
			}
		}
	}

	return 0;
}