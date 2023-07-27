#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 15

typedef struct{
    int idade;
    char nome[50];
    int cpf;
}tipodado;

typedef struct{
    tipodado pessoa;
    struct No* prox;
}No, *Lista;

void inicializa_hash (Lista tabela[]);
No* cria_no (tipodado pessoa, No* seu_proximo);
tipodado cria_ficha();
void insere_tabela (Lista tabela[], tipodado pessoa); 
int hash (int chave);
bool busca_na_tabela(Lista tabela[], int idade, char* nome, int cpf);

void imprime (Lista tabela[]);
int main (void){
    Lista tabela[TABLE_SIZE];
    int i;
    inicializa_hash(lista);
    printf("Digite 1 para inserir na tabela\n 2 para imprimir toda a tabela\n");
    scanf ("%d",&i);
    switch(i){
        case  1: insere_tabela (tabela, cria_ficha())
    }
    imprime (lista);
    return 0;
}
int hash (int chave){
    return chave % TABLE_SIZE;
}
void inicializa_hash (Lista tabela[]){
    for(int i = 0; TABLE_SIZE > i; i++){
        tabela[i] = NULL;
    }
}
No* cria_no (tipodado pessoa, No* seu_proximo){
    No* novo_no = malloc (sizeof(No));
    novo_no->pessoa = pessoa;

    novo_no->prox = seu_proximo;
    return novo_no;
}
tipodado cria_ficha(){
    tipodado nova_pessoa;
    gets(nova_pessoa.nome);
    while(getchar() != '\n');
    scanf("%d", &nova_pessoa.idade);
    while(getchar() != '\n');
    scanf("%d", &nova_pessoa.cpf);
}
void imprime (Lista tabela[]){
    for(int i = 0; TABLE_SIZE > i; i++){
        printf("Lista %d: ", i);
        No* percorre = tabela[i].prox;
        while(percorre != NULL){
            printf("%s\n %d\n %d", percorre->pessoa.nome, percorre->pessoa.idade, percorre->pessoa.cpf);
            percorre = percorre->prox;
        }
        printf("\n");
    }
}
void insere_tabela (Lista tabela[], tipodado pessoa){
    tabela[hash(pessoa.idade)] = cria_no( pessoa, tabela[hash(pessoa.idade)].prox);
}