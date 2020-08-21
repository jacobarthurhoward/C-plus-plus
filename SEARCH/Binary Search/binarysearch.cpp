#include <iostream>

int binarysearch(int arr[], int l, int r, int x){
  int mid = l + (r - l) / 2;

  if (arr[mid] == x) return mid;
  
  if (arr[mid] > x) return binarysearch(arr, l, mid-1, x);
  
  return binarysearch(arr, mid+l, r, x);
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarysearch(arr, 0, n-1, 7);
  std::cout << "Index of Target: " << result;

  return 0;
}