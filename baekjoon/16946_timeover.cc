// https://www.acmicpc.net/problem/16946

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M = -1; // [1, 1000]
std::vector<int> map;
std::queue<std::vector<int>::iterator> q;

int cal(std::vector<int> temp, int index) {
	int nMove = 0;
	temp[index] = -1;
	nMove++;
	q.push(temp.begin() + index);

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			auto pos = q.front();
			q.pop();

			int index = std::distance(temp.begin(), pos);
			// left
			if (M != 1 && index % M != 0 && temp[index - 1] == 0) {
				temp[index - 1] = -1;
				q.push(pos - 1);
				nMove++;
			}
			// right
			if (M != 1 && index % M != M - 1 && temp[index + 1] == 0) {
				temp[index + 1] = -1;
				q.push(pos + 1);
				nMove++;
			}
			// up
			if (index / M != 0 && temp[index - M] == 0) {
				temp[index - M] = -1;
				q.push(pos - M);
				nMove++;
			}
			// down
			if (index / M != N - 1 && temp[index + M] == 0) {
				temp[index + M] = -1;
				q.push(pos + M);
				nMove++;
			}
		}
	}

	return nMove;
}


int main() {
	// get lab status
	std::cin >> N >> M;
	int size = N * M;

	for (int i = 0; i < size; i++) {
		int temp;
		scanf_s("%1d", &temp);
		//std::cin >> temp;
		map.push_back(temp);
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		if (*it == 1) {
			*it = cal(map, std::distance(map.begin(), it));
		}
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		std::cout << *it;
		if (std::distance(map.begin(), it) % M == (M - 1))
			std::cout << std::endl;
	}

	std::cin.get();
	std::cin.get();
}
