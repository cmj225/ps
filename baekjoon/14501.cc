// https://www.acmicpc.net/problem/14501

#include <stdio.h>
#include <limits>

int N;// 1<=N<=15
int array[15][2] = { 0 };
int temp = 0;
int ans = std::numeric_limits<int>::min();

void scheduleling(int day) {
	int task_end = day + array[day][0] - 1;
	if (task_end > N || day > N) {
		ans = ans > temp ? ans : temp;
		return ;
	}

	temp += array[day][1];
	for (int i = task_end; i <= N; i++) {
		scheduleling(i+1);
	}
	temp -= array[day][1];
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &array[i][0], &array[i][1]);
	}

	scheduleling(1);

	printf("%d\n", ans);

	return 0;
}
