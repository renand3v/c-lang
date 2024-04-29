#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no * proximo;
} No;

void inserir_no_inicio(No ** lista, int valor) {
  No * novo = malloc(sizeof(No));

  if (!novo) {
    printf("erro ao alocar memória");

    return;
  }

  novo->valor = valor;
  novo->proximo = *lista;

  *lista = novo;
}

void inserir_no_fim(No ** lista, int valor) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória");

    return;
  }
  
  novo->valor = valor;
  novo->proximo = NULL;

  if (*lista == NULL) {
    *lista = novo;
  } else {
    tmp = *lista;

    while (tmp->proximo) {
      tmp = tmp->proximo;
    }

    tmp->proximo = novo;
  }
}

void inserir_no_meio(No ** lista, int valor, int elem) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória!");

    return;
  }

  novo->valor = valor;

  if (*lista == NULL) {
    novo->proximo = NULL;
    *lista = novo;
  } else {
    tmp = *lista;

    while (tmp->valor != elem && tmp->proximo) {
      tmp = tmp->proximo;
    }

    novo->proximo = tmp->proximo;
    tmp->proximo = novo;
  }
}

void inserir_ordenado(No ** lista, int valor) {
  No * novo = malloc(sizeof(No));
  No * tmp;

  if (!novo) {
    printf("erro ao alocar memória!");
    
    return;
  }

  novo->valor = valor;
  
  if (*lista == NULL) {
    novo->proximo = NULL;
    *lista = novo;
  } else if (novo->valor < (*lista)->valor) {
    novo->proximo = *lista;
    *lista = novo;
  } else {
    tmp = *lista;

    while (tmp->proximo && novo->valor > tmp->proximo->valor) {
      tmp = tmp->proximo;
    }

    novo->proximo = tmp->proximo;
    tmp->proximo = novo;
  }
}

No * remover(No ** lista, int valor) {
  No * remover = NULL;
  No * tmp;

  if (*lista == NULL) {
    return remover;
  }

  if ((*lista)->valor == valor) {
    remover = *lista;
    *lista = remover->proximo;
  } else {
    tmp = *lista;

    while (tmp->proximo && tmp->proximo->valor != valor) {
      tmp = tmp->proximo;
    }

    if (tmp->proximo) {
      remover = tmp->proximo;
      tmp->proximo = remover->proximo;
    }
  }

  return remover;
}

void imprimir(No * no) {
  printf("\tLista: ");
  
  while (no) {
    printf("%d ", no->valor);

    no = no->proximo;
  }
  
  printf("\n");
}

int main() {
  int opcao, valor, anterior;

  No * lista = NULL;

  do {
    printf(".0 - Sair\n.1 - Inserir inicio\n.2 - Inserir fim\n.3 Inserir meio\n.4 Inserir ordenado\n.5 Remover\n.6 Imprimir\n");
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
        printf("Digite um valor: ");
        scanf("%d", &valor);

        No * num = remover(&lista, valor);

        printf("Num: %d\n", num->valor);

        break;
      case 6:
        imprimir(lista);

        break;
    }
    
  } while(opcao != 0);

  return 0;
}
