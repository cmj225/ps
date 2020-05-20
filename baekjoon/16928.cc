// https://www.acmicpc.net/problem/16928

#include <iostream>
#include <vector>
#include <queue>

int N, M; // [1, 15]

std::vector<std::pair<bool, int>> ladder(100, std::pair<bool, int>(false, -1));
std::vector<std::pair<bool, int>> snake(100, std::pair<bool, int>(false, -1));
std::vector<bool> board(100, false);
std::queue<int> q;

int bfs() {
	int cnt = 0;

	board[1] = true;
	q.push(1);

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int here = q.front(); q.pop();
			if (here >= 100 - 6) {
				return ++cnt;
			}
			
			for (int j = 0; j < 6; j++) {
				int to = here + (j + 1);
				if (to > 100)
					continue;

				int jump = to;
				if (ladder[to].first)
					jump = ladder[to].second;
				else if (snake[to].first)
					jump = snake[to].second;

				if (!board[to] && (to == jump)) {
					board[to] = true;
					q.push(to);
				}
				else if (!board[to] && to != jump) {
					board[to] = true;
					board[jump] = true;
					q.push(jump);
				}
			}
		}
		cnt++;
	}

	return -1;
}

int main() {

	std::cin >> N >> M;

	int from = -1;
	int to = -1;
	for (int i = 0; i < N; i++) {
		std::cin >> from >> to;
		ladder[from] = std::pair<bool, int>(true, to);
	}
	for (int i = 0; i < M; i++) {
		std::cin >> from >> to;
		snake[from] = std::pair<bool, int>(true, to);
	}

	std::cout << bfs() << std::endl;

	return 0;
}
