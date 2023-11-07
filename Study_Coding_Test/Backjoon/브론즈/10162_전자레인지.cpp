#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// A: 5분(300초), B: 1분(60초), C: 10초
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