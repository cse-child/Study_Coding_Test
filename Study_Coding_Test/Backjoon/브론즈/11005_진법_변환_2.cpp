#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string conversion = "";
	int N, B;
	cin >> N >> B;
	//N = 60466175;
	//B = 36;

	while(N > 0)
	{
		if (N % B >= 10)
			conversion += (char)(N % B + 55);
		else
			conversion += to_string(N % B);

		N /= B;
	}
	reverse(conversion.begin(), conversion.end());
	cout << conversion << endl;
	return 0;
}