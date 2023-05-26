#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string N;
	int B;
	int binary = 0;
	
	cin >> N >> B;

	for(int i = N.size()-1, j = 0; i >= 0; i--, j++)
	{
		if ((int)N[i] >= 65)
			binary += (((int)N[i] - 55) * pow(B,j));
		else
			binary += (((int)(N[i]) - 48) * pow(B, j));
	}
	cout << binary << endl;
	return 0;
}