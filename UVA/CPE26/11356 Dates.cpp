#include <bits/stdc++.h>
using namespace std;

string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int month(string s) {
    for (int i = 0; i < 12; i++){
        if (months[i] == s) return i;
    }
    return -1;
}

int main() {
    int kases;
    cin >> kases;

    for (int kase = 1; kase <= kases; kase++) {
        string date;
        int add;

        cin >> date >> add;

        // YYYY-Month-DD
        int p1 = date.find('-');
        int p2 = date.find('-', p1 + 1);

        int year = stoi(date.substr(0, p1));
        int mon = month(date.substr(p1 + 1, p2 - p1 - 1));
        int day = stoi(date.substr(p2 + 1));

        day += add;

        while (true) {
            int days = daysOfMonth[mon];

            if (mon == 1 && leap(year))
                days = 29;

            if (day <= days)
                break;

            day -= days;
            mon++;

            if (mon == 12) {
                mon = 0;
                year++;
            }
        }

        printf("Case %d: %04d-", kase, year);
        cout << months[mon];
        printf("-%02d\n", day);
    }
}