// https://www.acmicpc.net/problem/16946

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M = -1; // [1, 1000]
std::vector<std::pair<int, int>> map;
std::queue<std::vector<std::pair<int, int>>::iterator> q;
std::vector<int> group;

void grouping(std::vector<std::pair<int, int>>& temp, int index, int g_index) {
	temp[index].second = g_index;
	group[g_index]++;

	q.push(temp.begin() + index);

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			auto pos = q.front();
			q.pop();
			int index = std::distance(temp.begin(), pos);

			// left
			if (M != 1 && index % M != 0 && temp[index - 1].first == 0 && temp[index - 1].second == -1) {
				temp[index - 1].second = g_index;
				q.push(pos - 1);
				group[g_index]++;
			}
			// right
			if (M != 1 && index % M != M - 1 && temp[index + 1].first == 0 && temp[index + 1].second == -1) {
				temp[index + 1].second = g_index;
				q.push(pos + 1);
				group[g_index]++;
			}
			// up
			if (index / M != 0 && temp[index - M].first == 0 && temp[index - M].second == -1) {
				temp[index - M].second = g_index;
				q.push(pos - M);
				group[g_index]++;
			}
			// down
			if (index / M != N - 1 && temp[index + M].first == 0 && temp[index + M].second == -1) {
				temp[index + M].second = g_index;
				q.push(pos + M);
				group[g_index]++;
			}
		}
	}

	return ;
}

int getSum(int index) {
	int left = -1, right = -1, up = -1, down = -1;
	int cnt = 1;
	
	// left
	if (M != 1 && index % M != 0 && map[index - 1].second != -1) {
		left = map[index - 1].second;
		cnt += group[left];
	}
	// right
	if (M != 1 && index % M != M - 1 && map[index + 1].second != -1) {
		right = map[index + 1].second;
		if (right != left)
			cnt += group[right];
	}
	// up
	if (index / M != 0 && map[index - M].second != -1) {
		up = map[index - M].second;
		if (up != left && up != right)
			cnt += group[up];
	}
	// down
	if (index / M != N - 1 && map[index + M].second != -1) {
		down = map[index + M].second;
		if (down != left && down != right && down != up)
			cnt += group[down];
	}

	return cnt % 10;
}

void cal() {
	int n = 0;
	for (auto iter = map.begin(); iter != map.end(); iter++) {
		if (iter->first == 0 && iter->second == -1) {
			group.push_back(0);
			grouping(map, std::distance(map.begin(), iter), n++);
		}
	}

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		if (iter->first == 1) {
			// sum
			iter->first = getSum(std::distance(map.begin(), iter));
		}
	}
}

int main() {
	// get lab status
	std::cin >> N >> M;
	int size = N * M;

	for (int i = 0; i < size; i++) {
		int temp;
		scanf_s("%1d", &temp);
		//std::cin >> temp;
		map.push_back(std::make_pair(temp, -1));
	}

	cal();

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		std::cout << iter->first;
		if (std::distance(map.begin(), iter) % M == (M - 1))
			std::cout << std::endl;
	}
}

