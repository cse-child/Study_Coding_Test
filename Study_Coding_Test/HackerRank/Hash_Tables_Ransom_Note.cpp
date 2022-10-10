#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 해커랭크 - Hash Tables: Ransom Note
void checkMagazine(vector<string> magazine, vector<string> note) {

    // 단어, 개수
    map<string, int> magazines;
    for (string mWord : magazine)
        ++magazines[mWord];

    for (string nWord : note)
    {
        magazines[nWord]--;

        if (magazines[nWord] < 0)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    vector<string> magazine;
    vector<string> note;

    //magazine.push_back("give");
    //magazine.push_back("me");
    //magazine.push_back("one");
    //magazine.push_back("grand");
    //magazine.push_back("today");
    //magazine.push_back("night");
    //
    //note.push_back("give");
    //note.push_back("one");
    //note.push_back("grand");
    //note.push_back("today");

    magazine.push_back("two");
    magazine.push_back("times");
    magazine.push_back("three");
    magazine.push_back("is");
    magazine.push_back("not");
    magazine.push_back("four");

    note.push_back("two");
    note.push_back("times");
    note.push_back("two");
    note.push_back("is");
    note.push_back("four");

    checkMagazine(magazine, note);
}