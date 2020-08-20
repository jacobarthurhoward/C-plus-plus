#include <iostream>

void selectionsort(int arr[], int n) {  
  for (int i = 0; i < n-1; i++) {  
    int min_idx = i;  
    for (int j = i+1; j < n; j++)  
      if (arr[j] < arr[min_idx])  
        min_idx = j;  
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }  
}  

int main() {
  int demo[] = {2, 5, 4, 1, 3};
  int n = sizeof(demo) / sizeof(demo[0]);

  selectionsort(demo, n);

  for (int i = 0; i < n; i++)
    std::cout << demo[i] << " ";
  
  return 0;
}