#include <stdio.h>
#include <stdlib.h>

void print_array(int * array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

void insertion(int * array, int size) {
  for (int i = 1; i < size; i++) {
    int j = i;
    int tmp = array[j];

    while (j > 0 && tmp < array[j - 1]) {
      array[j] = array[j - 1];
      
      j--;
    }

    array[j] = tmp;
  }
}

int main() {
  int array[5] = {9, 7, 8, 2, 3};

  print_array(array, 5);

  insertion(array, 5);

  print_array(array, 5);

  return 0;
}