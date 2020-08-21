#include <iostream>

int linearsearch(int arr[], int n, int x){
  for (int i = 0; i < n; i++)
    if (arr[i] == x)
      return i;
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = linearsearch(arr, n, 4);
  std::cout << "Index of Target:" << arr[result];
}