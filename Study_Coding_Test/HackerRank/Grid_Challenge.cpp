#include "Framework.h"

string gridChallenge(vector<string> grid) {
    // ���ؾ� �ϴ� ��
    // 1. grid[0][0]�̶� grid[1][0]�� ����, [1][0] [2][0], [0][1] [1][1]
    // 2. grid[0][0]�̶� grid[0][1]�� ����, [1][0] [1][1]

    // ���� ���ذ� �� ������µ� ���� �ุ �������� ������ �� �ִµ�
    // �� �����ϰ��� ��� ���� ��� �������� �����̸� YES ��ȯ
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