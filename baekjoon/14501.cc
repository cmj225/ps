// https://www.acmicpc.net/problem/14501

#include <stdio.h>

int N;// 1<=N<=15
int array[15][2] = { 0 };
int temp = 0, ans = 0;

void scheduleling(int day) {
	int task_end = day + array[day][0] - 1;
	if (task_end > N - 1 || day > N - 1) {
		ans = ans > temp ? ans : temp;
		return ;
	}

	temp += array[day][1];
	for (int i = task_end; i < N; i++) {
		scheduleling(i+1);
	}
	temp -= array[day][1];
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &array[i][0], &array[i][1]);
	}

	for (int i = 0; i < N; i++)
		scheduleling(i);

	printf("%d\n", ans);

	return 0;
}
