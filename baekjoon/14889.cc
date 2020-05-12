// https://www.acmicpc.net/problem/14889

#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>

int N = 0; // NÀº Â¦¼ö, [4, 20]
int ans = std::numeric_limits<int>::max();
int status[20][20] = { std::numeric_limits<int>::min() };
std::vector<int> team_start;
std::vector<int> team_link;
bool b_team_start[20] = { false };

int cal(std::vector<int>& team) {
	int ret = 0;

	for (auto i = team.begin(); i != team.end(); i++) {
		for (auto j = team.begin(); j != team.end(); j++) {
			ret += status[*i][*j];
		}
	}

	return ret;
}

void pick(int n, int index) {
	if (n == 0) {
		// make team link
		for (int i = 0; i < N; i++) {
			if (!b_team_start[i])
				team_link.push_back(i);
		}

		// calculate stat diff
		ans = std::min(ans, abs(cal(team_start) - cal(team_link)));
		team_link.clear();

		return;
	}

	for (int i = index; i < N; i++) {
		team_start.push_back(i); // add to team start
		b_team_start[i] = true;
		pick(n - 1, i + 1);
		team_start.pop_back();
		b_team_start[i] = false;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &status[i][j]);
	}

	pick(N / 2, 0);

	printf("%d\n", ans);

	return 0;
}
