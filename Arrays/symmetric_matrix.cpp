#include <iostream>

using namespace std;

int main(void) {

	double matrix[][4] = { 	{ 1, 2, 3, 4 },
			    	{ 2, 2, 3, 1 },
			    	{ 3, 3, 3, 2 },
			    	{ 4, 1, 2, 4 }   };

	int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int rows = sizeof(matrix) / sizeof(matrix[0]);
	bool is_symmetric = true;
	if (cols == rows)
	{
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				if (i != j && matrix[i][j] != matrix[j][i])
					is_symmetric = false;
	}
	else
		is_symmetric = false;
	if(is_symmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;
	return 0;
}
