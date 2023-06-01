#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	for(int i = 1; i <= N; i++)
	{
		if(N % i == 0)
		{
			K--;
			if(K == 0)
			{
				cout << i << endl;
				return 0;
			}
		}
	}

	if (K > 0)
		cout << "0" << endl;
	return 0;
}