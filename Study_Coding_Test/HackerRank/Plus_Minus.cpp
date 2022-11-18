void plusMinus(vector<int> arr) {
    float positive = 0;
    float negative = 0;
    float zero = 0;

    for (int num : arr)
    {
        if (num > 0)
            positive++;
        else if (num < 0)
            negative++;
        else
            zero++;
    }
    cout << (positive / arr.size()) << endl;
    cout << (negative / arr.size()) << endl;
    cout << (zero / arr.size()) << endl;
}