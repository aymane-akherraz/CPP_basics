#include <iostream>

using namespace std;

bool is_leap(int year) { 
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int month_length(int year, int month) {

	if (year <= 0 || month <= 0 || month > 12)
		return 0;
	int year_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (is_leap(year) && month == 2)
		return (year_month[month - 1] + 1);
	return (year_month[month - 1]);
}

int main(void) {
	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << month_length(yr,mo) << " ";
		cout << endl;
	}
	return 0;
}
