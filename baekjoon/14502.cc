// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M = -1; // [3, 8]
std::vector<int> lab;
int max = -1;
std::queue<std::vector<int>::iterator> q;

void calSafe(std::vector<int>& temp) {
	int nSafe = 0;
	for (auto iter = temp.begin(); iter != temp.end(); iter++) {
		if (*iter == 0)
			nSafe++;
	}
	max = max > nSafe ? max : nSafe;
}

void spread(std::vector<int> temp) {
	// bfs
	for (auto iter = temp.begin(); iter != temp.end(); iter++) {
		if (*iter == 2) {
			q.push(iter);
		}
	}

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			auto virus = q.front(); q.pop();

			int index = std::distance(temp.begin(), virus);
			if (M != 1 && index % M != 0 && temp[index - 1] == 0) {
				temp[index - 1] = 2;
				q.push(virus - 1);
			}
			if (M != 1 && index % M != M - 1 && temp[index + 1] == 0) {
				temp[index + 1] = 2;
				q.push(virus + 1);
			}
			if (index / M != 0 && temp[index - M] == 0) {
				temp[index - M] = 2;
				q.push(virus - M);
			}
			if (index / M != N - 1 && temp[index + M] == 0) {
				temp[index + M] = 2;
				q.push(virus + M);
			}
		}
	}

	calSafe(temp);

	return ;
}

void pick(int n, std::vector<int>::iterator it) {
	if (n == 0) {
		spread(lab);
		return;
	}

	for (auto iter = it; iter != lab.end(); iter++) {
		if (*iter == 0) {
			*iter = 1;
			std::vector<int>::iterator temp = iter;
			pick(n - 1, ++temp);
			*iter = 0;
		}
		continue;
	}
}

int main() {
	// get lab status
	std::cin >> N >> M;
	int size = N * M;

	for (int i = 0; i < size; i++) {
		int temp;
		std::cin >> temp;
		lab.push_back(temp);
	}

	// dfs
	pick(3, lab.begin());

	std::cout << max << std::endl;
}
