#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE  10
#define BUCKET_SIZE 3

typedef struct tipodado {
    char nome;
    int idade;
}tipodado;

typedef struct bucket {

    tipodado pessoas[BUCKET_SIZE];
    int qtt_pessoas;

}bucket;

int main (void){

    bucket tabela[TABLE_SIZE];

    //percorreria, definiria como 0 a qtt.
    //
while(true){
    //onde o programa pede entrada e chama as respectivas funcoes
}
}
int hash (int chave, int tentativa){
    return (chave * tentativa) % TABLE_SIZE;
}