#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    // vector<string> reported;
    map<string, int> result;
    //map<string, int> reported;
    map<string, map<string, int>> reported; // [신고자][신고당한사람]

    for (string str : report)
    {
        string temp = str.substr(0, str.find_first_of(" "));
        str = str.substr(str.find_first_of(" ") + 1);

        //reported[temp][str] += 1;
        reported[str][temp] = 1;
    }

    for (auto r : reported)
    {
        if (r.second.size() >= k)
        {
            for (auto s : r.second)
            {
                result[s.first]++;
            }
        }
    }

    for (auto r : result)
    {
        for (int i = 0; i < id_list.size(); i++)
        {
            if (id_list[i] == r.first)
            {
                answer[i] = r.second;
            }
        }
    }

    return answer;
}