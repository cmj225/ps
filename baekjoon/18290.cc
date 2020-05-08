// https://www.acmicpc.net/problem/18290

#include <stdio.h>
#include <vector>

int n, m, k, size;
int temp = 0;
int ans = -40000; // N X M X 10000, 10^6

struct cell {
	int data;
	bool bPicked = false;
};
std::vector<cell> vec;

bool canPick(int i) {
	// check left
	if ((m != 1) && ((i % m) != 0) && (vec.at(i - 1).bPicked == true))
		return false;

	// check up
	if (((i / m) != 0) && vec.at(i - m).bPicked == true)
		return false;

	return true;
};

// NM <= 100, 10^8 ~ 1sec
void pick(int k, int smallest) {
	if (k == 0) {
		ans = ans > temp ? ans : temp;
		return;
	}

	for (size_t i = smallest; i < vec.size(); i++) {
		if (canPick(i)) {
			vec.at(i).bPicked = true;
			temp += vec.at(i).data;
			pick(k - 1, i + 1);
			vec.at(i).bPicked = false;
			temp -= vec.at(i).data;
		}
	}

	return;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	size = n * m;

	// get input
	for (int i = 0; i < size; i++) {
		cell *pCell = new cell();
		scanf("%d", &pCell->data);
		vec.push_back(*pCell);
	}

	pick(k, 0);

	printf("%d\n", ans);

    return 0;
}
