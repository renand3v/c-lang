#include <stdio.h>
#include <stdlib.h>

void print_array(int * array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

// void selection(int * array, int primeiro, int size) {
//   if (primeiro >= size) {
//     return;
//   }

//   int menor = primeiro;

//   for (int i = menor + 1; i < size; i++) {
//     if (array[i] < array[menor]) {
//       menor = i;
//     }
//   }

//   int tmp = array[primeiro];

//   array[primeiro] = array[menor];
//   array[menor] = tmp;

//   selection(array, primeiro + 1, size);
// }

void selection(int * array, int size) {
  int menor;

  for (int i = 0; i < size; i++) {
    menor = i;

    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[menor]) {
        menor = j;
      }
    }

    int tmp = array[i];

    array[i] = array[menor];
    array[menor] = tmp;
  }
}

int main() {
  int array[7] = {7, 5, 1, 4, 8, 2, 9};

  print_array(array, 7);

  // selection(array, 0, 7);
  selection(array, 7);

  print_array(array, 7);

  return 0;
}
