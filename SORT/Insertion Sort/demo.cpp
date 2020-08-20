#include <iostream>
#include "Insertion.h"
using namespace std;

int main() {
  // Demo //
  //////////
  int arr[] = {3, 4, 5, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionsort(arr, n);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
}