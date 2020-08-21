#include <iostream>

void heapify(int arr[], int n, int i){
  int largest = i;
  
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;
  
  if (largest != i){                      
    int temp = arr[i];                    // c = a
    arr[i] = arr[largest];                // a = b
    arr[largest] = temp;                  // b = c = a
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n){
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--){
    int temp = arr[0];                    // c = a
    arr[0] = arr[i];                      // a = b
    arr[i] = temp;                        // b = c = a
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {2, 1, 5, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  heapsort(arr, n);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  return 0;
}