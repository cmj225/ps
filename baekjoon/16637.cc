// https://www.acmicpc.net/problem/16637

#include <iostream>
#include <string>
#include <limits>

int N; // [1, 19]
std::string str;
int ans = std::numeric_limits<int>::min(); // [-2^31, 2^31] -> int range 2^32


int calc(int pre, int post, char op) {
	switch (op) {
	case '+' :
		return pre + post;
		break;
	case '-' :
		return pre - post;
		break;
	case '*' :
		return pre * post;
		break;
	}
};

void dfs(int sum, int op_idx) {
	if (op_idx > N - 1) {
		ans = ans > sum ? ans : sum;
		return;
	}

	// n1 op n2
	dfs(calc(sum, (str[op_idx + 1] - '0'), str[op_idx]), op_idx + 2);
	
	// n1 op1 (n2 op2 n3)
	if(op_idx + 2 <= N-1)
		dfs(calc(sum, calc(str[op_idx + 1] - '0', str[op_idx + 3] - '0', str[op_idx + 2]), str[op_idx]), op_idx + 4);
};

int main() {
	std::cin >> N >> str;

	dfs(str[0] - '0', 1);

	std::cout << ans << std::endl;
}
