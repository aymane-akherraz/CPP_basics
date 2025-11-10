#include <iostream>
using namespace std;

struct TIME{
  int hour;
  int min;
};

int main()
{
	TIME time;
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
	while (event_duration >= 60)
	{
		if (time.hour == 23)
			time.hour = 0;
		else
			time.hour++;
		event_duration -= 60;
	}
	while (event_duration)
	{
		if (time.min == 59)
		{
			time.min = 0;
			time.hour++;
		}
		else
			time.min++;
		event_duration--;
	}
	if (time.hour < 10)
		cout << 0;
	cout << time.hour << ':';
	if (time.min < 10)
		cout << 0;
        cout << time.min << endl;
	return 0;
}
