#include <iostream>

int main() {
  // 1 x 1 x 1 Matrix
  std::cout << "1 x 1 x 1 Matrix:" << std::endl;
  std::cout << "-----------------" << std::endl;
  int a[1][1][1] = {1};
  std::cout << a[0][0][0];
  std::cout << '\n' << '\n' << '\n';

  // 3 x 1 x 1 Matrix
  std::cout << "3 x 1 x 1 Matrix:" << std::endl;
  std::cout << "-----------------" << std::endl;
  int b[3][1][1] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 1; j++)
  for (int k = 0; k < 1; k++)
    std::cout << b[i][j][k] << " ";
  std::cout << '\n' << '\n' << '\n';

// 3 x 3 x 1 Matrix
  std::cout << "3 x 3 x 1 Matrix:" << std::endl;
  std::cout << "-----------------" << std::endl;
  int c[3][3][1] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
  for (int k = 0; k < 1; k++)
    std::cout << c[i][j][k] << " ";
  std::cout << '\n' << '\n' << '\n';

  // 3 x 3 x 3 Matrix
  std::cout << "3 x 3 x 3 Matrix:" << std::endl;
  std::cout << "-----------------" << std::endl;
  int d[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}, {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}};
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
  for (int k = 0; k < 3; k++)
    std::cout << d[i][j][k] << " ";
  std::cout << '\n' << '\n' << '\n';


  return 0;
}