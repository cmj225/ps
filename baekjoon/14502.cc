#include <iostream>
#include <vector>
#include <algorithm>

int N, M = -1; // [3, 8]
int plane[8][8] = -1;
int max_safe = -1;
std::vector<int>

int calSafe () {
  int temp_plane[8][8] = plane; 

  // spread
  for (int i = 0; i < N; i++) {
	  for (int j = 0; j < M; j++) {
		  if (temp_plane[i][j] == 2) {
			  if (j != N-1 && temp_plane[i][j+1] == 0)
				  plane[i][j+1] = 2;
        if (i != N-1 && temp_plane[i+1][j] == 0)
				  temp_plane[i+1][j] = 2;
			}
		}
	}

  // check safe region
	int temp = 0;
  for (int i = 0; i < N; i++) {
	  for (int j = 0; j < M; j++) {
		  if(temp_plane[i][j] == 0)
			  temp++;
		}
	}
}


// 8 * 8 * 8 = 512
void contagion (int n) {
  if (n == 0) {
    std::max(max_safe, calSafe());
		return;
	}

	// pick
	for (int i = 0; i < N; i++) {
	  for (int j = 0; j < M; j++) {
	    if(plane[i][j] == 0) { 
			  plane[i][j] = 1;
			  contagion(n-1);
				plane[i][j] = 0;
			}
		}
	}
 
}
int main() {
  std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
	  for (int j = 0; j < M; j++) {
      std::cin >> plane[i][j];
		}
	}
 
	std::cout << 

}
