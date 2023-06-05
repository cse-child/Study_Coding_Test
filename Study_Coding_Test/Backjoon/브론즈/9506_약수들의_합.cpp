#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	vector<int> n;
	int input = 0;

	while(input != -1)
	{
		cin >> input;
		n.push_back(input);
	}
	n.pop_back();

	for(int i = 0; i < n.size(); i++)
	{
		int sum = 0;
		vector<int> divisor;
		for(int j = 1; j <= sqrt(n[i]); j++)
		{
			if(n[i] % j == 0)
			{
				sum += j;
				divisor.push_back(j);
				if (n[i] / j != j)
				{
					if (n[i] == (n[i] / j)) continue;
					sum += (n[i] / j);
					divisor.push_back(n[i] / j);
				}
			}
		}

		sort(divisor.begin(), divisor.end());

		if (sum == n[i])
		{
			cout << n[i] << " = ";
			for (int j = 0; j < divisor.size(); j++)
			{
				if (j == divisor.size() - 1)
					cout << divisor[j] << endl;
				else
					cout << divisor[j] << " + ";
			}
		}
		else
			cout << n[i] << " is NOT perfect." << endl;
	}

	return 0;
}