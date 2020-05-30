// https://www.acmicpc.net/problem/16197

#include <iostream>
#include <vector>
#include <queue>

int N, M; // [1,20]
char board[20][20] = { NULL };
std::vector<std::pair<int, int>> coin;

// left, right, up, down
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool memoization[20][20][20][20] = { false };
std::queue<std::pair<std::pair<int,int>, std::pair<int,int>>> q;

bool outRange(std::pair<int, int> pos) {
	if (pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M)
		return true;
	return false;
};

bool move(std::pair<std::pair<int, int>, std::pair<int, int>> status) {
	for (int i = 0; i < 4; i++) {
		int ny1 = status.first.first + dy[i];
		int nx1 = status.first.second + dx[i];
		int ny2 = status.second.first + dy[i];
		int nx2 = status.second.second + dx[i];
	
		if (outRange(std::make_pair(ny1, nx1)) != outRange(std::make_pair(ny2, nx2)))
			return true;
		else if (outRange(std::make_pair(ny1, nx1)) == true && outRange(std::make_pair(ny2, nx2)) == true)
			continue;

		if (0 <= nx1 && nx1 < M && 0 <= ny1 && ny1 < N && board[ny1][nx1] == '#') {
			ny1 = status.first.first;
			nx1 = status.first.second;
		}
		if (0 <= nx2 && nx2 < M && 0 <= ny2 && ny2 < N && board[ny2][nx2] == '#') {
			ny2 = status.second.first;
			nx2 = status.second.second;
		}
		if (!memoization[ny1][nx1][ny2][nx2]) {
			memoization[ny1][nx1][ny2][nx2] = true;
			q.push(std::make_pair(std::make_pair(ny1, nx1), std::make_pair(ny2, nx2)));
		}
	}
	return false;
};

// bfs
int bfs() {
	int trial = 0;
	memoization[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = true;
	q.push(std::make_pair(coin[0], coin[1]));

	while (!q.empty()) {
		if(++trial > 10)
			return -1;

		int size = q.size();
		for (int i = 0; i < size; i++) {
			std::pair<std::pair<int, int>, std::pair<int, int>> status = q.front(); q.pop();
			if(move(status))
				return trial;
		}
	}
	return -1;
};

int main() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin.push_back(std::make_pair(i, j));
				board[i][j] = '.';
			}
		}
	}

	std::cout << bfs() << std::endl;
}
