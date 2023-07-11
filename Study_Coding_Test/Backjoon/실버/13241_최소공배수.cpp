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

	/* ��Ŭ���� ȣ���� */
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

	/* for���� �̿��� �ִ�����, �ּҰ���� ���ϱ� */
	long long int A, B;
	cin >> A >> B;
	if(A > B) // Min ���� A�� ����
	{
		long long int temp = A;
		A = B;
		B = temp;
	}

	long long int gcd; // �ִ�����
	for(int i = 1; i <= A; i++)
	{
		if (A % i == 0 && B % i == 0)
			gcd = i;
	}
	cout << (A * B) / gcd; // �ּҰ����

	return 0;
}