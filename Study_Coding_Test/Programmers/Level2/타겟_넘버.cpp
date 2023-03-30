#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int>numbers, int target, int index, int sum, bool plus)
{
	if (plus)
		sum += numbers[index++];
	else
		sum -= numbers[index++];

	if (numbers.size() == index)
	{
		if (sum == target)
			answer++;
	}
	else
	{
		DFS(numbers, target, index, sum, plus);
		DFS(numbers, target, index, sum, !plus);
	}
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, target, 0, 0, true);
	DFS(numbers, target, 0, 0, false);

	return answer;
}


/* Best Ç®ÀÌ

int total;

void DFS(vector<int> &numbers, int &target,int sum,int n) {
	if(n >= numbers.size()){
		if(sum == target) total++;
		return;
	}

	DFS(numbers, target, sum + numbers[n], n+1);
	DFS(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	DFS(numbers, target, numbers[0] , 1);
	DFS(numbers, target, -numbers[0], 1);

	answer = total;

	return answer;
}

 */