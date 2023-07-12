#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int cA, pA, cB, pB;
	cin >> cA >> pA >> cB >> pB;

	int P = pA * pB;
	int C = (cA * pB) + (cB * pA);

	cout << C/ GCD(C, P) << ' ' << P/ GCD(C, P);

	return 0;
}