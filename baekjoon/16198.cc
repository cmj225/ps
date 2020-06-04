// https://www.acmicpc.net/problem/16198

#include <iostream>

int N; // [3, 10]
int save[10] = { 0 };
bool exist[10] = { false };
int ans = INT_MIN; // 10^6 * 18 ~ 10^8 < INT_MAX
int energy = 0;

void dfs(int n) {
	if (n == 2) {
		ans = energy > ans ? energy : ans;
		return ;
	}

	for (int i = 1; i < N - 1; i++) {
		if (!exist[i]) continue;

		int left = i - 1;
		int right = i + 1;
		while (!exist[left])
			left--;
		while (!exist[right])
			right++;
		
		exist[i] = false;
		energy += save[left] * save[right];
		dfs(n - 1);
		energy -= save[left] * save[right];
		exist[i] = true;
	}
};

int main() {
	std::cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		std::cin >> save[i];
		exist[i] = true;
	}

	dfs(N);

	std::cout << ans << std::endl;
}
