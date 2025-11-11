#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) { 
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int monthLength(int year, int month) {
	if (year <= 0 || month <= 0 || month > 12)
                return 0;
        int year_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeap(year) && month == 2)
                return (year_month[month - 1] + 1);
        return (year_month[month - 1]);
}

int dayOfYear(Date date) {
	int days = 0;
        if (date.year <= 0 || date.month <= 0 || date.month > 12 || date.day <= 0 || date.day > 31)
                return 0;
        while (--date.month)
                days += monthLength(date.year, date.month);
        days += date.day;
        return (days);
}

int daysBetween(Date d1, Date d2) {
	if (d2.year < d1.year)
		return -1;
	if (d2.year == d1.year)
	{
		if (d2.month < d1.month)
			return -1;
		else if (d2.month == d1.month && d2.day < d1.day)
			return -1;
		return (dayOfYear(d2) - dayOfYear(d1));
	}
	int days = dayOfYear(d2);
	while (--d2.year > d1.year)
	{
		if (isLeap(d2.year))
			days += 366;
		else
			days += 365;
	}
	days += dayOfYear({d1.year, 12, 31}) - dayOfYear(d1);
	return (days);
}

int main(void) {

	Date since,to;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> to.year >> to.month >> to.day;
	cout << daysBetween(since,to) << endl;
	return 0;
}
