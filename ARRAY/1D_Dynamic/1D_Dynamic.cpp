#include <iostream>

int main() {
  int *ptr;
  int n = 5;
  printf("Enter number of elements: %d\n", n);

  ptr = (int*)malloc(n * sizeof(int));

  if (ptr == NULL){
    printf("Memory is not allocated.\n");
    exit(0);
  } else {
    printf("Memory succesffuly allocated using malloc");

    for (int i = 0; i < n; ++i){
      ptr[i] = i + 1;
    }

    printf("The elements of the array are: ");
    for (int i = 0; i < n; ++i)      printf("%d ", ptr[i]);
  }
return 0;
}