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
                return (0);
        int year_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeap(year) && month == 2)
                return (year_month[month - 1] + 1);
        return (year_month[month - 1]);
}

int dayOfYear(Date date) {
	int days = 0;
	if (date.year <= 0 || date.month <= 0 || date.month > 12 || date.day <= 0 || date.day > 31)
		return (0);
	while (--date.month)
		days += monthLength(date.year, date.month);
	days += date.day;
	return (days);
}

int main(void) {

	Date d;
	cout << "Enter year, month, day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}
