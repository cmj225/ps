// https://www.acmicpc.net/problem/2529

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

int k = 0; // [2, 9]
const char nine = '9';
const char zero = '0';
char symbol[9] = { '0' };

bool validate(std::string& string) {
	for (int i = 0; i < k; i++) {
		switch (symbol[i]) {
		case '>':
			if(string[i] < string[i + 1])
				return false;
			break;
		case '<':
			if (string[i] > string[i + 1])
				return false;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

int main() {
	std::cin >> k;

	for (int i = 0; i < k; i++) {
		std::cin >> symbol[i];
	}

	// make max, min
	std::string min, max;
	for (int i = 0; i < k + 1; i++) {
		max += (nine - i);
		min += (zero + i);
	}

	// find valid max
	while (!validate(max)) {
		std::prev_permutation(max.begin(), max.end());
	}

	// find valid min
	while (!validate(min)) {
		std::next_permutation(min.begin(), min.end());
	}
	
	std::cout << max << std::endl << min << std::endl;

	return 0;
}
