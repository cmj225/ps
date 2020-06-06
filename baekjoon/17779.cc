// https://www.acmicpc.net/problem/17779

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int N; // [5, 20]
int map[20][20] = { -1 };
int map2[20][20] = { 0 };
int ans = std::numeric_limits<int>::max();

// x = col, y = 
void calDiff(int x, int y, int d1, int d2) {
	std::vector<int> vec(5, 0);

	// mark distrction 5

	// cal diff
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int row = r + 1;
			int col = c + 1;
			// distriction 1
			if (row >= 1 && row < y && col >= 1 && col <= x + d1
				&& !(col >= x && row >= y - (col - x)))
				vec[0] += map[r][c];
			// distriction 2
			else if (row >= 1 && row <= y - d1 + d2 && col > x + d1 && col <= N
				&& !(row >= y - d1 + (col - (x + d1))))
				vec[1] += map[r][c];
			// distriction 3
			else if (row >= y && row <= N && col >= 1 && col < x + d2
				&& !(col >= x && row <= y + (col - x)))
				vec[2] += map[r][c];
			// distriction 4
			else if (row > y + d2 - d1 && row <= N && col >= x + d2 && col <= N
				&& !(row <= y + d2 - (col - (x + d2))))
				vec[3] += map[r][c];
			// distriction 5
			else
				vec[4] += map[r][c];
		}
	}
	
	std::sort(vec.begin(), vec.end());

	ans = ans < (vec[4] - vec[0]) ? ans : (vec[4] - vec[0]);
};

void select(int x, int y) {
	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {
			if (x + d1 + d2 > N || y - d1 < 1 || y + d2 > N)
				continue;

			calDiff(x, y, d1, d2);
		}
	}
}

int main() {
	std::cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
			std::cin >> map[r][c];
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++)
			select(c + 1, r + 1);
	}

	std::cout << ans << std::endl;
}

