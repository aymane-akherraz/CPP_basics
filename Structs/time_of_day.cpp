#include <iostream>
using namespace std;

struct {
  int hour;
  int min;
}
time;
int main()
{
	int event_duration;

	cout << "Enter hour: ";
	cin >> time.hour;
	cout << "Enter minutes: ";
	cin >> time.min;
	cout << "Enter event duration in minutes: ";
	cin >> event_duration;
	if (time.hour < 0 || time.hour > 23 || time.min < 0 || time.min > 59 || event_duration < 0)
	{
		cout << "Invalid input\n";
		return 1;
	}
	
}
