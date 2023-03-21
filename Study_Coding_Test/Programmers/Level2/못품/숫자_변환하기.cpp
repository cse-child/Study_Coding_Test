#include <string>
#include <vector>

using namespace std;
int solution(int x, int y, int n) {
	int answer = 0;

	while (x != y)
	{
		if (y % (x * 2) == 0)
			x *= 2;
		else if (y % (x * 3) == 0)
			x *= 3;
		else if ((x + n) <= y)
			x += n;
		else
			return -1;
		answer++;
	}

	return answer;
}

//int main()
//{
//	solution(10, 40, 5);
//}