#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 최대공약수
int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a%b);
}

int solution(vector<int> arr) {
	for(int i = 1; i < arr.size(); i++)
		arr[i] = (arr[i - 1] * arr[i]) / GCD(arr[i - 1], arr[i]);

	return arr[arr.size()-1];
}

int main()
{
	cout << GCD(2, 3);
}