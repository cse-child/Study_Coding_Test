#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ChangeTimeToMinutes(string time)
{
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));

	return (h * 60) + m;
}

int solution(vector<vector<string>> book_time) {
	vector<pair<int, int>> room;
	for(int i = 0; i < book_time.size(); i++)
		room.emplace_back(ChangeTimeToMinutes(book_time[i][0]), ChangeTimeToMinutes(book_time[i][1]) + 10);

	sort(room.begin(), room.end());

	int roomCnt = 0;
	vector<pair<int, int>> useRooms;
	for (int i = 0; i < room.size(); i++)
	{
		vector<pair<int, int>> temp;
		for(int j = 0; j < useRooms.size(); j++) // 방 시작 시간마다 사용중인 방들과 겹치는지 검사
		{
			// 대실 시간이 겹쳐진다면, 방 개수 배열에 추가
			if (room[i].first < useRooms[j].second)
				temp.push_back(useRooms[j]);
		}

		useRooms = temp;
		useRooms.push_back(room[i]); // 현재 방은 대실 룸에 추가
		roomCnt = max(roomCnt, (int)useRooms.size());
	}

	return roomCnt;
}

int main()
{
	vector<vector<string>> book_time = { {"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20" } };

	cout << solution(book_time);
}