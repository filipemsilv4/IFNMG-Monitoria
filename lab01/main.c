#include "lista.h"
#include <stdlib.h>
void inicializa_lista(Lista * ap_lista){
    ap_lista = NULL;
}

No* cria_no (No* proximo, int valor){
    No* novo_no = (No*) malloc (sizeof (No));
    novo_no->valor = valor;
    novo_no->proximo = proximo;
}

void insere_fim(Lista * ap_lista, int valor){
    // criar novo no.
    No* novo_no = cria_no (NULL, valor);
    //percorrendo a lista
    if((*ap_lista) == NULL){
       insere_inicio(ap_lista,valor);
       return;
    }
    No* temp = (*ap_lista)->proximo;
    while (temp->proximo != NULL){
        temp = temp->proximo;
    }
    temp->proximo = novo_no; 
}

void insere_inicio(Lista * ap_lista, int valor){
    //No* novo_no = (No*) malloc (sizeof(No));
    //novo_no->valor = valor;
    //novo_no->proximo = *ap_lista;
    No* novo_no = cria_no (*ap_lista, valor);
    *ap_lista = novo_no;
    return;
}

int remove_fim(Lista * ap_lista){
    No* temp_1 = (No*) malloc (sizeof (No));
    No* temp_2 = (No*) malloc (sizeof (No));
    temp_1 = *ap_lista, temp_2 = temp_1->proximo;
    int valor;

    // no caso de 0 ou 1 elementos.
    if (temp_1 == NULL)
        return NULL;
    if (temp_2 == NULL){
        valor = temp_1->valor;
        free (temp_1);
        *ap_lista = NULL;
        return valor;
    }
    // demais casos.
    while (temp_2->proximo != NULL){
        temp_1 = temp_1->proximo;
        temp_2 = temp_1->proximo;
    }
    temp_1->proximo = NULL;
    valor = temp_2->valor;
    free (temp_2);
    return valor;
}

int remove_inicio(Lista * ap_lista){
    int valor = (*ap_lista)->valor;
    No* temp = *ap_lista;
    *ap_lista = (*ap_lista)->proximo;
    free (temp); 
    return valor;
}

void imprime(Lista lista){
    // TODO: arrumar printf
    printf("(");
    for (No* temp = lista; temp != NULL; temp = temp->proximo)
        printf (",%d",temp->valor);
    printf (")\n");
}

void desaloca_lista(Lista *ap_lista){
    printf("a");
    return;
}
int busca(Lista lista, int valor){
    printf("a");
    return 0;
}
int remove_ocorrencias(Lista *ap_lista, int valor){
    printf("a");
    return 0;
}