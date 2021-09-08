#include <bits/stdc++.h>
using namespace std;
 
// Map to store the numeric value of each month depending on
// its occurrence i.e. Jan = 1, Feb = 2 and so on.
unordered_map<string, int> monthsMap;
 
// Function which initializes the monthsMap
void sort_months()
{
    monthsMap["Jan"] = 1;
    monthsMap["Feb"] = 2;
    monthsMap["Mar"] = 3;
    monthsMap["Apr"] = 4;
    monthsMap["May"] = 5;
    monthsMap["Jun"] = 6;
    monthsMap["Jul"] = 7;
    monthsMap["Aug"] = 8;
    monthsMap["Sep"] = 9;
    monthsMap["Oct"] = 10;
    monthsMap["Nov"] = 11;
    monthsMap["Dec"] = 12;
}

bool comp(string a, string b)
{

    string str1 = a.substr(7, 4);
    string str2 = b.substr(7, 4);
    if (str1.compare(str2) != 0) {
        if (str1.compare(str2) < 0)
            return true;
        return false;
    }

    string month_sub_a = a.substr(3, 3);
    string month_sub_b = b.substr(3, 3);

    int month_a = monthsMap[month_sub_a];
    int month_b = monthsMap[month_sub_b];
    if (month_a != month_b) {
        return month_a < month_b;
    }
 
    string day_a = a.substr(0, 2);
    string day_b = b.substr(0, 2);
    if (day_a.compare(day_b) < 0)
        return true;
    return false;
}

void printDates(string dates[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << dates[i] << endl;
    }
}
 
int main()
{
    string dates[] = { "24 Jul 2017", "25 Jul 2017", "11 Jun 1996",
                       "01 Jan 2019", "12 Aug 2005", "01 Jan 1997" };
    int n = sizeof(dates) / sizeof(dates[0]);
    sort_months();
    sort(dates, dates + n, comp);
    printDates(dates, n);
}