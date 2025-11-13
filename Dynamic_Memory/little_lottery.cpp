#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int	get_random_val(int max, int *balls, int n)
{
	int rnd;
	bool exists = false;
	do {
		exists = false;
		rnd = rand() % max + 1;
		for (int i = 0; i < n; i++)
	                if (balls[i] == rnd)
				exists = true;
	} while(exists);
	return rnd;
}

int main(void) {
	int maxball;
	int n;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> n;
	srand(time(NULL));
	int *balls = new int[n];
	for (int j = 0; j < n; j++) {
		balls[j] = get_random_val(maxball, balls, j);
		cout << balls[j] << endl;
	}
	delete[] balls;
	return 0;
}
