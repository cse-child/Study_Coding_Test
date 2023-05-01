#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2명씩밖에 못탄다는 인원제한을 못읽었다..!!
int solution(vector<int> people, int limit) {
	int boatCount = 0;
	int front = 0, end = people.size()-1;

	sort(people.begin(), people.end());

	while(front < end)
	{
		if(people[front]+people[end] > limit)
		{
			end--;
		}
		else
		{
			front++;
			end--;
		}
		boatCount++;
	}
	if (front == end) boatCount++;
	return boatCount;
}