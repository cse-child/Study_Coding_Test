#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int GCD(long long int A, long long int B)
{
	if (A % B == 0)
		return B;
	return GCD(B, A%B);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	/* 유클리드 호제법 */
	//long long int A, B;
	//cin >> A >> B;
	//
	//if(A > B)
	//{
	//	long long int temp = A;
	//	A = B;
	//	B = temp;
	//}
	//
	//cout << (A * B) / (GCD(A, B));

	/* for문을 이용한 최대공약수, 최소공배수 구하기 */
	long long int A, B;
	cin >> A >> B;
	if(A > B) // Min 값을 A로 조정
	{
		long long int temp = A;
		A = B;
		B = temp;
	}

	long long int gcd; // 최대공약수
	for(int i = 1; i <= A; i++)
	{
		if (A % i == 0 && B % i == 0)
			gcd = i;
	}
	cout << (A * B) / gcd; // 최소공배수

	return 0;
}