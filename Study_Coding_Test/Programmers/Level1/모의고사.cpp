#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> maxAnswer;
    map<int, vector<int>> answer;
    map<int, int> peopleAnswer;
    answer[1] = { 1,2,3,4,5 };
    answer[2] = { 2,1,2,3,2,4,2,5 };
    answer[3] = { 3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < answers.size(); i++)
    {
        for (int j = 1; j <= answer.size(); j++)
        {
            if (answers[i] == answer[j][i % answer[j].size()]) 
                peopleAnswer[j]++;
        }
    }

    int max = 0;
    for (pair<int, int> people : peopleAnswer)
    {
        if (people.second > max)
        {
            max = people.second;
        }
    }

    for (pair<int, int> people : peopleAnswer)
    {
        if (people.second == max)
            maxAnswer.push_back(people.first);
    }

    return maxAnswer;
}