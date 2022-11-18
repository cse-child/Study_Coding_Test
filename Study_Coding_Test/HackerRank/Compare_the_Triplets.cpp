vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> score;
    score.resize(2);

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            score[0]++;
        else if (a[i] < b[i])
            score[1]++;
    }

    return score;
}