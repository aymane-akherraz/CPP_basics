#include <iostream>

using namespace std;

int main(void) {
	int   sys;
	float m, ft, in;
	const float M_PER_INCH = 0.0254;
	const char* err = "Invalid distance: distance should be greater than 0\n";

	cout << "Which system would you like to use to input data:\n0- metric\n\n1- imperial\n";
	cin >> sys;
	if (sys == 0)
	{
		m = -1;
		while (m < 0)
		{
			cout << "Enter distance in meter:";
			cin >> m;
			if (m < 0)
				cout << err;
		}
		in = m / M_PER_INCH;
		ft = in / 12;
		in -= (int)ft * 12;
		cout << (int)ft << '\'' << in << "\"\n";
	}
	else if (sys == 1)
	{
		ft = -1;
		while (ft < 0)
                {
			cout << "Enter distance in feet:";
        	        cin >> ft;
			if (ft < 0)
                                cout << err;
		}
		in = -1;
		while (in < 0)
                {
			cout << "Enter distance in inches:";
        	        cin >> in;
			 if (in < 0)
                                cout << err;
		}
		m = (ft * 12 + in) * M_PER_INCH;
		cout << m << "m\n";
	}
	else
		cout << "option not available, please select 0 or 1\n";
	return 0;
}
