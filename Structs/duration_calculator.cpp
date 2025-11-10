#include <iostream>
using namespace std;
struct TIME {
	int h;
	int m;
};
int main(void) {
	TIME start;
	TIME end;
	TIME time = {0};
	cout << "Enter start h m: ";
	cin >> start.h >> start.m;
	cout << "Enter end h m: ";
	cin >> end.h >> end.m;

	int dur = ((end.h * 60) + end.m) - ((start.h * 60) + start.m);
	int hh = dur / 60;		// hours within duration
	int mm = dur % 60;		// remaining minutes
	time.m += mm;			// increment minutes
	time.h += hh;			// increment hours
	time.h += time.m / 60;		// update hours to reflect minutes above 59
	time.m %= 60;			// correct minutes
	time.h %= 24;
	if(time.h < 10)
                cout << 0;
        cout << time.h << ":";
        if(time.m < 10)
                cout << 0;
        cout << time.m << endl;
	return 0;
}
