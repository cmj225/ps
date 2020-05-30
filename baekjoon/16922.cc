// https://www.acmicpc.net/problem/16922

#include <iostream>

int N = -1, cnt = 0; // N : [1, 20]
int roman[4] = { 1, 5, 10, 50 };
bool ans[1000 + 1] = { false }; // [1, 50*20]
int cnt = 0;


void dfs(int n, int index, int sum) {
	if (n == 0) {
		if (ans[sum] == false) {
			ans[sum] = true;
			cnt++;
		}
		return;
	}

	for (int i = index; i < 4; i++) {
		dfs(n - 1, i, sum + roman[i]);
	}
}

int main() {
	std::cin >> N;

	dfs(N, 0, 0);

	std::cout << cnt << std::endl;
}
