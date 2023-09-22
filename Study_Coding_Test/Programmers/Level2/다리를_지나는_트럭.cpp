#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	int curWeight = 0;
	int passTruck = 0;

	vector<int> trucks(truck_weights.rbegin(), truck_weights.rend()); // 대기 트럭
	queue<int> bridgeTrucks; // 다리를 건너는 트럭

	while(true)
	{
		// 다리위에 트럭 큐가 다 찬 경우
		if(bridgeTrucks.size() == bridge_length)
		{
			curWeight -= bridgeTrucks.front();
			if (bridgeTrucks.front() != 0)
				passTruck++;
			bridgeTrucks.pop();
		}

		if (passTruck == truck_weights.size()) break;

		// 다리위에 트럭이 더 올라갈 수 있는 경우
		if(bridgeTrucks.size() < bridge_length)
		{
			if(!trucks.empty())
			{
				// 다리의 최대 무게에 도달하지 않는 경우
				if (trucks.back() + curWeight <= weight)
				{
					bridgeTrucks.push(trucks.back());
					curWeight += trucks.back();
					trucks.pop_back();
				}
				else // 다리에 최대 무게가 올라가있어서 못건너는 경우
					bridgeTrucks.push(0);
			}
			else
				bridgeTrucks.push(0);
		}
		time++;
	}
	return time;
}

int main()
{
	//cout << solution(2, 10, { 7,4,5,6 });
	//cout << solution(100, 100, { 10 });
	//cout << solution(100, 100, { 10 });
	cout << solution(5, 5, { 2,2,2,2,1,1,1,1,1 });
}