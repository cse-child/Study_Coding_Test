#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int answer = 0;

void DFS(int curNum, int totalNum, int goalNum)
{
	if (totalNum > goalNum) return;
	if (totalNum == goalNum)
	{
		answer++;
		return;
	}
	totalNum += (++curNum);
	DFS(curNum, totalNum, goalNum);
}

int solution(int n)
{
	for (int i = 1; i <= n; i++)
		DFS(i, i, n);

	return answer;
}

int main()
{
	int num = bitset<20>(15).count();
	cout << num << endl;

	cout << bitset<20>(15).to_string() << endl;
}


