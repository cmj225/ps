// https://www.acmicpc.net/problem/2210

#include <iostream>
#include <set>

int board[5][5] = { 0 };
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> memoization;
std::set<int> answer;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int toPick, int cur) {
	if (toPick == 0) {
		if (memoization.find(std::make_pair(std::make_pair(y, x), std::make_pair(toPick, cur))) == memoization.end()) {
			memoization.insert(std::make_pair(std::make_pair(y, x), std::make_pair(toPick, cur)));
			answer.insert(cur);
		}
		return;
	}

	if (memoization.find(std::make_pair(std::make_pair(y, x), std::make_pair(toPick, cur))) == memoization.end()) {
		memoization.insert(std::make_pair(std::make_pair(y, x), std::make_pair(toPick, cur)));
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			continue;

		if (memoization.find(std::make_pair(std::make_pair(ny, nx), std::make_pair(toPick -1, cur*10 + board[ny][nx]))) == memoization.end())
			dfs(ny, nx, toPick - 1, cur * 10 + board[ny][nx]);
	}
};

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			std::cin >> board[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			dfs(i, j, 5, board[i][j]);
	}

	std::cout << answer.size() << std::endl;
}
