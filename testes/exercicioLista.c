#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node, *list;

void inicializa_lista(list *l){
    *l = NULL;
}
void insere_lista(list *l, int x){
    node *novo = malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    novo->data = x;
    novo->next = *l;
    *l = novo;
}
void imprime_lista(list* l){
    node *aux = *l;
    printf("[ ");
    while(aux != NULL && aux->next != NULL){
        printf("%d,", aux->data);
        aux = aux->next;
    }
    printf("%d ]", aux->data);
    printf("\n");
}
int add_data(){
    int x;
    printf("Digite o valor a ser inserido na lista: ");
    scanf("%d", &x);
    return x;
}
void remove_duplicata(list *l){
    printf("Removendo duplicatas...\n");
    node *aux = *l;
    node *aux2;
    while(aux != NULL){
        aux2 = aux;
        while(aux2->next != NULL){
            if(aux->data == aux2->next->data){
                node *aux3 = aux2->next;
                aux2->next = aux2->next->next;
                free(aux3);
                printf("Saindo da removendo duplicatas...\n");
            }
            else
                aux2 = aux2->next;
        }
        aux = aux->next;
    }
}
int main (void){
    list l;
    inicializa_lista(&l);
    for(int i = 0; i < 10; i++)
        insere_lista(&l, add_data());
    imprime_lista(&l);
    remove_duplicata(&l);
    imprime_lista(&l);

    return 0;
}