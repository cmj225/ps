// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <limits.h>
#include <algorithm>


long long min = LLONG_MAX;
long long max = LLONG_MIN;
int N; // [2, 11]
int number[11] = { 0 };
int nOperator[4] = { 0 };
int op[11] = { -1 }; // -1: unhandled, 0: +, 1: -, 2: *, 3: /

void cal() {
	do {
		long long ret = number[0];
		for (int i = 0; i < N -1; i++) {
			switch (op[i]) {
			case 1: // +
				ret += number[i + 1];
				break;
			case 2: // -
				ret -= number[i + 1];
				break;
			case 3: // *
				ret *= number[i + 1];
				break;
			case 4: // /
				ret /= number[i + 1];
				break;
			}
		}
		max = max > ret ? max : ret;
		min = min < ret ? min : ret;
	} while (std::next_permutation(&op[0], &op[N-1]));
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> number[i];
	}

	int index = 0;
	for (int i = 0; i < 4; i++) {
		int k = i + 1;
		std::cin >> nOperator[i];
		for (int j = 0; j < nOperator[i]; j++)
			op[index++] = k;
	}

	cal();

	std::cout << max << std::endl << min << std::endl;

	return 0;
}
