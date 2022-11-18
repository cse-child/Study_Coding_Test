string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    string minSec = s.substr(2, 6);
    string time = s.substr(s.size() - 2);

    if (time == "PM" && hour < 12)
        hour += 12;
    else if (time == "AM" && hour >= 12)
        hour -= 12;

    cout << hour << " " << minSec << "  " << time;
    if (hour < 10)
        return "0" + to_string(hour) + minSec;
    else
        return to_string(hour) + minSec;
}