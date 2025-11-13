#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	int err = 0;
	int grade;
	int **grades = NULL;
	int num_of_grades;
	float *course_final_grades = NULL;
	float final_grade;
	cout << "Enter number of courses taken: ";
	cin >> n;
	if (cin.good() && n > 0)
	{
		grades = new int * [n];
		for (int i = 0; i < n; i++)
			grades[i] = NULL;
		course_final_grades = new float[n];
		for (int i = 0; i < n; i++)
		{
			course_final_grades[i] = 0.0;
			cout << "Enter number of grades for course number " << i + 1 << ": ";
			cin >> num_of_grades;
			if (cin.good() && num_of_grades > 0)
			{
				grades[i] = new int[num_of_grades + 1];
				for (int j = 1; j <= num_of_grades; j++)
				{
					cout << "Enter grade " << j << ": ";
					cin >> grade;
					if (cin.good() && grade >= 0)
					{
						grades[i][j] = grade;
						course_final_grades[i] += grade;
					}
					else
					{
						err = 1;
						break;
					}
				}
				course_final_grades[i] /= num_of_grades;
				grades[i][0] = num_of_grades;
			}
			else
			{
				err = 1;
				break;
			}
		}
	}
	else
		err = 1;
	if (!err)
	{
		final_grade = 0.0;
		for (int i = 0; i < n; i++)
		{
			cout << fixed << setprecision(2) << "Course " << i + 1 << ": final " << course_final_grades[i] << ", grades: ";
			for (int j = 1; j <= grades[i][0]; j++)
				cout << grades[i][j] << " ";
			cout << endl;
			final_grade += course_final_grades[i];
		}
		cout << "Overall final " << final_grade / n << endl;
	}
	else
		cout << "Invalid input" << endl;
	delete[] course_final_grades;
	for (int i = 0; i < n; i++)
		delete[] grades[i];
	delete[] grades;
}
