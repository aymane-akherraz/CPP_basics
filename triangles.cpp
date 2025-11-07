#include <iostream>
using namespace std;

int main(void) {
	int h, s, w, N;

	cout << "Pyramid height = ";
	cin >> h;
	cout << "Number of Pyramids (Depends on your screen width) = ";
	cin >> N;
	if (h < 2 || N < 1)
	{
		cout << "Pyramid height must be greater than 1 and Number of Pyramids must be greater than zero\n";
		return 1;
	}
	w = 1;
	s = h - 1;
	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < s; j++)
			cout << ' ';
		for (int x = 0; x < w; x++)
		{
			if (x == 0 || x == w - 1)
				cout << '*';
			else
				cout << ' ';
		}
		for (int y = 0; y < N - 1; y++)
		{
			for (int j = 0; j < (s * 2) + 1; j++)
				cout << ' ';
			for (int x = 0; x < w; x++)
			{
				if (x == 0 || x == w - 1)
					cout << '*';
				else
					cout << ' ';
			}
		}
			cout << endl;
		w += 2;
		s--;
	}
	for (int i = 0; i < w; i++)
		cout << '*';
	for (int y = 0; y < N - 1; y++)
        {
		cout << ' ';
		for (int i = 0; i < w; i++)
                	cout << '*';
	}
	cout << endl;
	return 0;
}
