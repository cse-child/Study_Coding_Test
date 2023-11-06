#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;

	if (a > b)
		swap(a, b);

	while(true)
	{
		if (abs(a - b) == 1 && a % 2 != 0 && b % 2 == 0)
			break;

		if (a % 2 != 0)
			a += 1;
		if (b % 2 != 0)
			b += 1;

		a /= 2;
		b /= 2;
		answer++;
	}
	return answer;
}

int main()
{
	cout << solution(8, 4, 7) << endl; // 3
	cout << solution(8, 1, 2) << endl; 
	cout << solution(4, 1, 4) << endl; 
	cout << solution(8, 1, 7) << endl; 
}