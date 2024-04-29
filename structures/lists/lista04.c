#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no * proximo;
} No;

typedef struct {
  No * inicio;
  int size;
} Lista;

void criar_lista(Lista * lista) {
  lista->inicio = NULL;
  lista->size = 0;
}

void inserir_no_inicio(Lista * lista, int valor) {
  No * novo = malloc(sizeof(No));

  if (!novo) {
    printf("erro ao alocar memória");

    return;
  }

  novo->valor = valor;
  novo->proximo = lista->inicio;

  lista->inicio = novo;
  lista->size++;
}

// inserir no final
void inserir_no_fim(Lista * lista, int valor) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória");

    return;
  }
  
  novo->valor = valor;
  novo->proximo = NULL;

  if (lista->inicio == NULL) {
    lista->inicio = novo;
  } else {
    tmp = lista->inicio;

    while (tmp->proximo) {
      tmp = tmp->proximo;
    }

    tmp->proximo = novo;
  }

  lista->size++;
}

void inserir_no_meio(Lista * lista, int valor, int elem) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória!");

    return;
  }

  novo->valor = valor;

  if (lista->inicio == NULL) {
    novo->proximo = NULL;
    lista->inicio = novo;
  } else {
    tmp = lista->inicio;

    while (tmp->valor != elem && tmp->proximo) {
      tmp = tmp->proximo;
    }

    novo->proximo = tmp->proximo;
    tmp->proximo = novo;
  }

  lista->size++;
}

void inserir_ordenado(Lista * lista, int valor) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória!\n");
    return;
  }

  novo->valor = valor;

  if (lista->inicio == NULL) {
    novo->proximo = NULL;
    lista->inicio = novo;
  } else if (novo->valor < lista->inicio->valor) {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
  } else {
    tmp = lista->inicio;

    while (tmp->proximo && novo->valor > tmp->proximo->valor) {
      tmp = tmp->proximo;
    }

    novo->proximo = tmp->proximo;
    tmp->proximo = novo;
  }

  lista->size++;
}

void imprimir(Lista lista) {
  printf("\tLista (%d): ", lista.size);
  
  No * no = lista.inicio;

  while (no) {
    printf("%d ", no->valor);

    no = no->proximo;
  }
  
  printf("\n");
}

int main() {
  int opcao, valor, anterior;

  Lista lista;

  criar_lista(&lista);
  
  // inserir_ordenado(&lista, 2);
  // inserir_ordenado(&lista, 1);
  // inserir_ordenado(&lista, 5);
  // inserir_ordenado(&lista, 3);

  // imprimir(lista);

  // return 0;

  do {
    printf(".0 - Sair\n.1 - Inserir inicio\n.2 - Inserir fim\n.3 Inserir meio\n.4 Inserir ordenado\n.5 Imprimir\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserir_no_inicio(&lista, valor);

        break;
      case 2:
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserir_no_fim(&lista, valor);

        break;
      case 3:
        printf("Digite um valor e o valor de referência: ");
        scanf("%d %d", &valor, &anterior);

        inserir_no_meio(&lista, valor, anterior);

        break;
      case 4:
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserir_ordenado(&lista, valor);

        break;
      case 5:
        imprimir(lista);

        break;
    }
    
  } while(opcao != 0);

  return 0;
}
