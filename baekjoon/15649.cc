#include <iostream>
#include <stdio.h>
#include <vector>

int m, n;
std::vector<bool> vec;
std::vector<int> ans;

void print(std::vector<int>::iterator begin,
   std::vector<int>::iterator end) {
   while (begin != end) {
      printf("%d ", *begin);
      //std::cout << *begin << " ";
      begin++;
   }
   printf("\n");
   //std::cout << std::endl;
}

void pick(int k) {
   if (k == 0)
      print(ans.begin(), ans.end());

   for (int i = 0; i < n; i++) {
      if (vec[i] == true)
         continue;

      vec[i] = true;
      ans.push_back(i + 1);
      pick(k - 1);
      ans.pop_back();
      vec[i] = false;
   }
}

int main() {
   scanf("%d %d", &n, &m);
   //std::cin >> n >> m;

   for (int i = 0; i < n; i++)
      vec.push_back(false);

   pick(m);
    
    return 0;
}
