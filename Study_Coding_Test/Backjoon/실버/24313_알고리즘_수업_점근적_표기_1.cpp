#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a1, a0, c, n;
	cin >> a1 >> a0 >> c >> n;

	// f(n) <= c * g(n)
	// f(n) = a1 * n + a0
	// g(n) = n0 ->> a1 * n + a0 <= c * n0

	// O(g(n)) ={ f(n) <= c * g(n) }
	// O(n) = f(n) <= c * n
	// O(n) = (a1*n) + a0 <= c * n;

	// fn = a1n + a0
	// fn <= c * n;

	// c - a1 >= 0 : 모든 n>=n0 에 대해
	if (((a1 * n + a0) <= c * n) && (c - a1 >= 0))
		cout << "1";
	else
		cout << "0";
	return 0;
}