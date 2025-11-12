#include <iostream>
#include <ctime>

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
                return -1;
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
	if (days < 0)
		return -1;
	while (--d2.year > d1.year)
	{
		if (isLeap(d2.year))
			days += 366;
		else
			days += 365;
	}
	int start_date = dayOfYear(d1);
	if (start_date < 0)
		return -1;
	days += dayOfYear({d1.year, 12, 31}) - start_date;
	return (days);
}

Date today(void) {
        time_t t = time(NULL);
        tm tl = *localtime(&t);
        return { tl.tm_year+1900, tl.tm_mon+1, tl.tm_mday };
}

int daysLived(Date d) {
	return daysBetween(d, today());
}

int main(void) {
	Date birthDate;
	cout << "Enter your birthday date (Y M D): ";
	cin >> birthDate.year >> birthDate.month >> birthDate.day;
	int daysSinceBirth = daysLived(birthDate);
	if (daysSinceBirth >= 0)
		cout << "You lived " << daysSinceBirth << " days." << endl;
	else
		cout << "Invalid input" << endl;
	return 0;
}
