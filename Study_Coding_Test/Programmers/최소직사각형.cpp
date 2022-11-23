#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        max_width = max(max_width, max(sizes[i][0], sizes[i][1]));
        max_height = max(max_height, min(sizes[i][0], sizes[i][1]));
    }

    return max_width * max_height;
}