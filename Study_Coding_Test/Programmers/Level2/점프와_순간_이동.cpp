#include <iostream>
using namespace std;

int solution(int n)
{
	int pos = n;
	int energy = 0;
	
	while(pos > 0)
	{
		if (pos % 2 == 0)
			pos /= 2;
		else
		{
			pos--;
			energy++;
		}
	}

	return energy;
}

int main()
{
	cout << solution(5000);

	return 0;
}


// 독특한 풀이

/*
 public int solution(int n) {
	return Integer.bitCount(n);
}

결국, 문제 해결을 위해선 2로 얼마나 나누어지는지를 세야 하기 때문에
n을 2진수로 변환한 뒤 발생하는 1의 개수를 카운팅하면 된다.

2진수가 1,2,4,8,16,... 으로 2의 제곱수만큼 늘어나기 때문에
2로 나누어지지 않는 경우는 1이 발생하게 된다.
이러한 특성을 활용해 1의 개수만 카운팅하면 되는것이다.

*/



