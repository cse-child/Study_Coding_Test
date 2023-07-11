#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int A, B;
		cin >> A >> B;
		if(A > B)
		{
			int temp = A;
			A = B;
			B = temp;
		}

		cout << (A * B) / GCD(A, B) << '\n';
		
		//int min = A > B ? B : A;
		//int gcd = 0;
		//for(int i = 1; i <= min; i++)
		//{
		//	if (A%i == 0 && B%i == 0)
		//		gcd = i;
		//}
		//cout << (A*B) / gcd << '\n';
	}

	return 0;
}