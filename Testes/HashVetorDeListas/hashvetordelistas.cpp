#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <exception>

#define TABLE_SIZE 15

typedef unsigned long long int ulli;

typedef struct{
    int idade;
    char nome[50];
    ulli cpf;
}tipodado;

typedef struct Node {
    tipodado pessoa;
    struct Node* prox;
} No, *Lista;

void inicializa_hash (Lista* tabela[]);
No* cria_no (No* proximo, tipodado pessoa);
void insere_no (No* atual, No* proximo);
tipodado cria_ficha();
void insere_tabela (Lista* tabela[], tipodado pessoa); 
int hash (int chave);
bool busca_na_tabela(Lista* tabela[], int idade, char* nome, int cpf);

void imprime (Lista* tabela[TABLE_SIZE]);

int main (void){
    Lista* tabela[TABLE_SIZE];
    int i;
    inicializa_hash(tabela);
    printf("joao\n");
    printf("Digite 1 para inserir na tabela, 2 para imprimir toda a tabela\n");
    scanf ("%d",&i);
    switch(i){
        case  1: insere_tabela (tabela, cria_ficha());
    }
    imprime (tabela);

    return 0;
}

void inicializa_hash(Lista* tabela[]){    
    try{
        for(int i = 0; i != TABLE_SIZE; i++){
            tabela[i] = NULL;
        }
    } catch(const std::exception& e){
        printf("Erro na funct inicializa_hash: %s", e.what());
        exit(0);
    }
}


int hash (int chave){return chave % TABLE_SIZE;}

No* cria_no (No* proximo, tipodado pessoa){
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->pessoa = pessoa;

    novo_no->prox = proximo;
    return novo_no;
}



void insere_tabela (Lista* tabela[], tipodado pessoa){
    tabela[hash (pessoa.idade)] = cria_no((*tabela[hash(pessoa.idade)]), cria_ficha());
    
}

tipodado cria_ficha (){
    tipodado nova_pessoa;
    printf ("Digite respectivamente, Nome,Idade,CPF.\n");
    // gets (nova_pessoa.nome);
    // while ((getchar()) != '\n');
    // scanf ("%i", &nova_pessoa.idade);
    // while ((getchar()) != '\n');
    // scanf ("%i",&nova_pessoa.cpf);
    
    try{
        strcpy (nova_pessoa.nome, "Joao");
    } catch(const std::exception& e){
        printf ("Erro ao copiar string, funçao cria_ficha\n");
        exit(1);
    }

    nova_pessoa.idade = 20;
    nova_pessoa.cpf = 17786167625;
    return nova_pessoa;
}

void imprime (Lista* tabela[]){
    for (int i = 0; i < TABLE_SIZE; i++){
        for(No* atual = (*tabela[i]); atual != NULL; atual = atual->prox)
            printf ("(%i) Nome: %s, Idade: %i, CPF: %llu\n", i,atual->pessoa.nome, atual->pessoa.idade, atual->pessoa.cpf);
    }
}
