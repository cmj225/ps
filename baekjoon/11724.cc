// https://www.acmicpc.net/problem/11724

#include <iostream>

int N, M;
int connected_component = 0;

bool connection[1001][1001] = { false };
bool check[1001] = { false };

void dfs(int node) {
  for (int j = 1; j <= N; ++j) {
    if (connection[node][j] == true && check[j] == false) {
      check[j] = true;
        dfs(j);
    }
  }
}

int main() {
  std::cin >> N >> M; // 1 <= N <= 1000
  for (int i = 0; i < M; i++) {
    int from, to;
    std::cin >> from >> to;
    connection[from][to] = connection[to][from] = true;
  }

  for (int i = 1; i <= N; ++i) {
    if (check[i] == false) {
      check[i] = true;
      ++connected_component;
      dfs(i);
    }
  }

  std::cout << connected_component << std::endl;
}
