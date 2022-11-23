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

    // 한줄로 대체 가능..!
    answer.erase(min_element(answer.begin(), answer.end()));

    return answer.empty() ? vector<int>(1, -1) : answer;
}

// 아니 문제를 저따구로 써놨네 배열 순서 바뀌면 안된다고 말을 해야지~~~~~~~