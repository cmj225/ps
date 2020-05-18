// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int N, K; // [0, 100,000]

std::queue<int> q;
std::vector<bool> discovered(100000 + 1, false);
std::vector<int> from(100000 + 1, std::numeric_limits<int>::min());
std::vector<int> path;
int depth = 0;

int bfs(int start) {
	discovered[start] = true;
	q.push(start);

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int here = q.front();
			q.pop();
			if (here == K) {
				while (here != N) {
					path.push_back(here);
					here = from[here];
				}
				path.push_back(N);
				return depth;
			}

			if (here - 1 >= 0 && !discovered[here - 1]) {
				q.push(here - 1);
				from[here - 1] = here;
				discovered[here - 1] = true;
			}
			if (here + 1 <= 100000 && !discovered[here + 1]) {
				q.push(here + 1);
				from[here + 1] = here;
				discovered[here + 1] = true;
			}
			if (here * 2 <= 100000 && !discovered[here * 2]) {
				q.push(here * 2);
				from[here * 2] = here;
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

	for (std::vector<int>::reverse_iterator iter = path.rbegin(); iter != path.rend(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	return 0;
}
