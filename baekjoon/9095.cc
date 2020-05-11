// https://www.acmicpc.net/problem/9095

#include <stdio.h>
#include <vector>

int T, cnt = 0;
std::vector<int> n; // 1<= n <=11

void merge(int n, int pos) {
	if (pos > n)
		return ;

	if (pos == n) {
		cnt++;
		return ;
	}
	
	merge(n, pos + 1);
	merge(n, pos + 2);
	merge(n, pos + 3);

	return;
}


int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int temp;
		scanf("%d", &temp);
		n.push_back(temp);
	}

	for (auto iter = n.begin(); iter != n.end(); iter++) {
		cnt = 0;
		merge(*iter, 0);
		printf("%d\n", cnt);
	}

	return 0;
}
