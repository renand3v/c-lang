#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(int * array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

int particiona(int * vet, int inicio, int fim) {
  int pivo = (int) (vet[inicio] + vet[fim] + vet[(int) (inicio + fim) / 2]) / 3;
  
  while (inicio < fim) {
    while (inicio < fim && vet[inicio] <= pivo) {
      inicio++;
    }

    while (inicio < fim && vet[fim] >= pivo) {
      fim--;
    }

    int tmp = vet[inicio];

    vet[inicio] = vet[fim];
    vet[fim] = tmp;
  }

  return inicio;
}

void quicksort(int * vet, int inicio, int fim) {
  if (inicio < fim) {
    int pos = particiona(vet, inicio, fim);

    quicksort(vet, inicio, pos - 1);
    quicksort(vet, pos, fim);
  }
}

int main() {
  int vet[15] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

  print_array(vet, 15);

  // printf("%d\n", particiona(vet, 0, 14));
  quicksort(vet, 0, 14);

  print_array(vet, 15);

  return 0;
}
