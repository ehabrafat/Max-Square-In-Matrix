#include <iostream>
#include <vector>
using namespace std;

int maxSquare(vector<vector<int>>& mat) {
	size_t n{ mat.size() };
	size_t m{ mat[0].size() };
	int max{};
	int sum{ 0 };
	int sq_i{}, sq_j{};
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			sum = mat[i][j] + mat[i + 1][j] + mat[i][j + 1] + mat[i + 1][j + 1];
			if (sum > max) {
				sq_i = i;
				sq_j = j;
				max = sum;
			}
		}
	}
	// Print the selected squares
	vector<vector<int>> neighbour{
		{0,0},
		{0,1},
		{1,0},
		{1,1}
	};
	for (int i = 0; i < neighbour.size(); i++) {
		cout << "(" << sq_i + neighbour[i][0] << "," << sq_j + neighbour[i][1] << ")";
		if (i % 2 == 1) cout << '\n';
		else cout << " ";
	}
	return max;
}

int main() {
	vector<vector<int>> mat{
		{0,0,1,2},
		{1,2,1,2},
		{0,3,0,3}
	};
	maxSquare(mat);
}
