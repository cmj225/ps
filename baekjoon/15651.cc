// https://www.acmicpc.net/problem/15651

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

void pick(int k) {
  if (k == 0) {
	  print(ans.begin(), ans.end());
	  return;
  }

  for (int i = 0; i < n; i++) {
	  ans.push_back(i + 1);
	  pick(k - 1);
	  ans.pop_back();
  }

  return;
}

int main() {
  scanf("%d %d", &n, &m);

  pick(m);

  return 0;
}
