#include <iostream>

template <typename T> void bubblesort(T arr[], int n) {
  for (int i = 0; i < n-1; i++)        
    for (int j = 0; j < n-i-1; j++)  
      if (arr[j] > arr[j+1]){
        
        T tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      
      }
}

int main(){

  int demo[] = {3, 5, 1, 4, 2};

  bubblesort(demo, sizeof(demo) / sizeof(demo[0]));
  
  for (int i = 0; i < sizeof(demo)/sizeof(demo[0]); i++)
    std::cout << demo[i] << " ";

  return 0;
}