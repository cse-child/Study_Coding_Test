#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> finalGrade;

    for (int grade : grades)
    {
        int remain = 5 - (grade % 5);
        if (remain < 3 && grade + remain >= 40)
            grade += remain;

        finalGrade.push_back(grade);
    }
    return finalGrade;
}