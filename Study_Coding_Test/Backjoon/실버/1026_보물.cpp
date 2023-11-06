// 4Ка

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int& a : A)
		cin >> a;
	for (int& b : B)
		cin >> b;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < N; i++)
		result += (A[i] * B[i]);

	cout << result;
	return 0;
}