// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <stdio.h>
#include <vector>

int m, n;
std::vector<int> ans;

void print(std::vector<int>::iterator begin,
  std::vector<int>::iterator end) {
  while (begin != end) {
	  printf("%d ", *begin);
	  begin++;
  }
  printf("\n");
}

void pick(int k, int smallest) {
  if (k == 0) {
	  print(ans.begin(), ans.end());
	  return;
  }

  for (int i = smallest; i < n; i++) {
	  ans.push_back(i + 1);
	  pick(k - 1, i);
	  ans.pop_back();
  }

  return;
}

int main() {
  scanf("%d %d", &n, &m);

  pick(m, 0);

  return 0;
}
