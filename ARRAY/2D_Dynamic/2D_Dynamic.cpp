#include <iostream>

int main() {
  int r = 3, c = 4, count = 0;
  int *arr = (int *)malloc(r * c *sizeof(int));
  for (int i = 0; i < r; i++)
  for (int j = 0; j < c; j++)
    *(arr + i * c + j) = ++count;

  for (int i = 0; i < r; i++)
  for (int j = 0; j < c; j++)
    printf("%d ", *(arr + i * c + j));

  return 0;
}