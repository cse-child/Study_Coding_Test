#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    /*int minNum = *min_element(arr.begin(), arr.end());
    for (int num : arr)
    {
        if (num != minNum)
            answer.push_back(num);
    }*/

    // ���ٷ� ��ü ����..!
    answer.erase(min_element(answer.begin(), answer.end()));

    return answer.empty() ? vector<int>(1, -1) : answer;
}

// �ƴ� ������ �������� ����� �迭 ���� �ٲ�� �ȵȴٰ� ���� �ؾ���~~~~~~~