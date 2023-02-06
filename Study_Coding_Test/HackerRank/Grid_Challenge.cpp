#include "Framework.h"

string gridChallenge(vector<string> grid) {
    // 비교해야 하는 것
    // 1. grid[0][0]이랑 grid[1][0]의 순서, [1][0] [2][0], [0][1] [1][1]
    // 2. grid[0][0]이랑 grid[0][1]의 순서, [1][0] [1][1]

    // 문제 이해가 좀 어려웠는데 대충 행만 오름차순 정렬할 수 있는데
    // 행 정렬하고나서 행과 열이 모두 오름차순 정렬이면 YES 반환
    for (int i = 0; i < grid.size(); i++)
        sort(grid[i].begin(), grid[i].end(), less<char>());

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 1; j < grid[i].size(); j++)
        {
            if (grid[i][j - 1] > grid[i][j])
                return "NO";

            if (grid[j - 1][i] > grid[j][i])
                return "NO";
        }
    }
    return "YES";
}