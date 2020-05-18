// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int N, K; // [0, 100,000]

std::queue<int> q;
std::vector<bool> discovered(100000 + 1, false);
int depth = 0;

int bfs(int start) {
	discovered[start] = true;
	q.push(start);

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int here = q.front();
			q.pop();
			if (here == K)
				return depth;

			if (here - 1 >= 0 && !discovered[here - 1]) {
				q.push(here - 1);
				discovered[here - 1] = true;
			}
			if (here + 1 <= 100000 && !discovered[here + 1]) {
				q.push(here + 1);
				discovered[here + 1] = true;
			}
			if (here * 2 <= 100000 && !discovered[here * 2]) {
				q.push(here * 2);
				discovered[here * 2] = true;
			}
		}

		// goto next depth
		depth++;
	}

	return std::numeric_limits<int>::min(); // can't catch ...
}

int main() {
	std::cin >> N >> K;
	
	std::cout << bfs(N) << std::endl;

	return 0;
}
