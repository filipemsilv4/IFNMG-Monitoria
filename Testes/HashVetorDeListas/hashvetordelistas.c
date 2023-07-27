#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TABLE_SIZE 15

typedef unsigned long long int ulli;

typedef struct{
    int idade;
    char* nome;
    ulli cpf;
}tipodado;

typedef struct no{
    tipodado pessoa;
    struct no* prox;
}No, *Lista;
void insere_auto (Lista tabela[]);
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
    inicializa_hash(tabela);
    printf("Digite 1 para inserir na tabela\n 2 para imprimir toda a tabela\n");
    while(true){
        scanf ("%d",&i);
        switch(i){
            case 1: insere_tabela (tabela, cria_ficha());
            case 2: imprime (tabela);
            case 3: insere_auto(tabela);
        }
    }
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
    char nome[50];
    scanf("%[^\n]",nome);
    while(getchar() != '\n');
    int i = strlen(nome);
    tipodado nova_pessoa;
    nova_pessoa.nome = malloc (i * sizeof(char));
    strcpy(nova_pessoa.nome, nome);
    while(getchar() != '\n');
    scanf("%d", &nova_pessoa.idade);
    while(getchar() != '\n');
    scanf("%lli", &nova_pessoa.cpf);

    printf("%s", nova_pessoa.nome);
    return nova_pessoa;
}

void imprime (Lista tabela[]){
    for(int i = 0; TABLE_SIZE > i; i++){
        printf("Lista %d: ", i);
        No* percorre = tabela[i];
        while(percorre != NULL){
            // Lista x: [nome, idade, cpf]
            printf("[%s, %d, %lli]", percorre->pessoa.nome, percorre->pessoa.idade, percorre->pessoa.cpf);
            percorre = percorre->prox;
        }
        printf("\n");
    }
}
void insere_tabela (Lista tabela[], tipodado pessoa){
    tabela[hash(pessoa.idade)] = cria_no( pessoa, tabela[hash(pessoa.idade)]);
}
void insere_auto(Lista tabela[]){
    int i  = 0;
    tipodado pessoa;
    pessoa.nome = "Teste";
    pessoa.cpf = 17786167625;
    while(i < TABLE_SIZE){
        pessoa.idade = i + rand() % 100;
        i++;
        sleep(2);
        insere_tabela (tabela, pessoa);
        imprime (tabela);
    }
}