#include <iostream>

void swap(int *a, int *b){
  int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++){
    if (arr[j] <= pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high){
  if (low < high){
    int partition_index = partition(arr, low, high);
    quicksort(arr, low, partition_index - 1);
    quicksort(arr, partition_index + 1, high);
  }
}

int main(){
  int arr[] = {2, 3, 1, 5, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, n-1);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
}