/* Algorithm |  INSERTION SORT (input::array, input::size_of_array)
-------------------------------------------------------------------
  (7 Steps)
  ---------

  1.  Mark First Element as Sorted
  2.  For Each Unsorted Element 
  3.    'EXTRACT' X
  4.    For j <- lastSortedIndex down to 0
  5.      If Current Element j > X
  6.        Then -> Move Sorted Element 1 Right
  7.  Break Loop, Insert X 

END INSERTION SORT */


void insertionsort(int arr[], int n){
  for (int i = 1; i < n; i++){
    int key = arr[i];  // This position will be sorted after the inner loop

    // Compare key with each element left of it
    int j = i - 1;
    while (key < arr[j] && j >= 0){
      arr[j + 1] = arr[j]; 
      --j;
    }
    
    arr[j + 1] = key;
  }
}