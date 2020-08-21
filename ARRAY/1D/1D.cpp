#include <iostream>

int main() {
  int arr[3] = {1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  std::cout << std::endl;
  
  for (int i = n - 1; i >= 0; i--)
    std::cout << arr[i] << " ";
  return 0;
}