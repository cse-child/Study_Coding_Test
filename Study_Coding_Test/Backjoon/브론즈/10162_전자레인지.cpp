#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// A: 5��(300��), B: 1��(60��), C: 10��
	int A = 0, B = 0, C = 0;
	int T;
	cin >> T;

	A += (T / 300);
	T %= 300;
	B += (T / 60);
	T %= 60;
	C += (T / 10);
	T %= 10;

	if (T != 0)
		cout << "-1";
	else
		cout << A << ' ' << B << ' ' << C;
	return 0;
}