// https://www.acmicpc.net/problem/14226

#include <iostream>
#include <queue>

int S = -1; //  [2, 1000]
std::queue<std::pair<int, std::pair<int, int>>> q; // {sec, {nEmotions, nClipboard}}
bool discovered[2000][2000] = { false };   // 2 + 998, 1999 - 999

int bfs() {
	q.push(std::make_pair(0, std::make_pair(1, 0)));
	discovered[q.front().second.first][q.front().second.second] = true;

	while (!q.empty()) {
		auto state = q.front();
		q.pop();
		if (state.second.first == S)
			return state.first;

		int sec = state.first;
		int E = state.second.first;
		int C = state.second.second;
		
		// copy (E, E)
		if (discovered[E][E] == false) {
			q.push(std::make_pair(sec+1, std::make_pair(E, E)));
			discovered[E][E] = true;
		}
		// paste (E+C, C)
		if (E + C < 2000 && discovered[E + C][C] == false) {
			q.push(std::make_pair(sec+1, std::make_pair(E + C, C)));
			discovered[E + C][E] = true;
		}
		// delete (E-1, C)
		if (E - 1 > 0 && discovered[E - 1][C] == false) {
			q.push(std::make_pair(sec+1, std::make_pair(E - 1, C)));
			discovered[E - 1][E] = true;
		}
	}

	return -1; // INF
}

int main() {

	std::cin >> S;

	std::cout << bfs();

	return 0;
}
