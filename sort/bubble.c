#include <stdio.h>
#include <stdlib.h>

void print_array(int * array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

// void bubble(int * array, int size) {
//   for (int i = 0; i < size; i++) {
//     int current = array[i];
//     int next = array[i + 1];

//     if ((i + 1) > size - 1) {
//       continue;
//     }

//     if (current > next) {
//       int tmp = array[i];

//       array[i] = next;
//       array[i + 1] = tmp;

//       return bubble(array, size);
//     }  
//   }
// }

// void bubble(int * array, int size) {
//   for (int j = 0; j < size; j++) {
//     for (int i = 0; i < size - 1; i++) {
//       if (array[i] > array[i + 1]) {
//         int tmp = array[i];

//         array[i] = array[i + 1];
//         array[i + 1] = tmp;
//       }
//     }
//   }
// }

// void bubble(int * array, int size) {
//   int troca = 1;

//   while (troca) {
//     troca = 0;

//     for (int i = 0; i < size - 1; i++) {
//       if (array[i] > array[i + 1]) {
//         int tmp = array[i];

//         array[i] = array[i + 1];
//         array[i + 1] = tmp;

//         troca = 1;
//       }
//     }

//     size--;
//   }
// }

void bubble(int * array, int size) {
  if (size < 2) {
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    if (array[i] > array[i + 1]) {
      int tmp = array[i];

      array[i] = array[i + 1];
      array[i + 1] = tmp;
    }
  }

  bubble(array, size - 1);
}

int main() {
  // int array[5] = {5, 4, 3, 2, 1};

  // print_array(array, 5);

  // bubble(array, 5);

  // print_array(array, 5);

  int array[15] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

  print_array(array, 15);

  bubble(array, 15);

  print_array(array, 15);

  return 0;
}
