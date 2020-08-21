#include <iostream>

int main() {
  // 1 x 1 Matrix
  int a[1][1] = {1};
  std::cout << a[0][0];
  std::cout << '\n' << '\n';
  
  
  // 2 x 1 Matrix
  int b[2][1] = {{1}, {2}};
  for (int i = 0; i < 2; i++)
  for (int j = 0; j < 1; j++)
    std::cout << b[i][j] << " ";
  std::cout << '\n' << '\n';

  // 1 x 2 Matrix
  int c[1][2] = {1, 2};
  for (int i = 0; i < 1; i++)
  for (int j = 0; j < 2; j++)
    std::cout << c[i][j] << " ";
  std::cout << '\n' << '\n';

  // 2 x 2 Matrix
  int d[2][2] = {{1, 2}, {3, 4}};
  for (int i = 0; i < 2; i++)
  for (int j = 0; j < 2; j++)
    std::cout << d[i][j] << " ";
  std::cout << '\n' << '\n';
  



  return 0;
}