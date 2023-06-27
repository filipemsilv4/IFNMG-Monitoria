#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define BUCKET_SIZE 3

void insere_na_tabela(int chave, int pos, bucket tabela[]);

int index_prox_desvio_livre = (TABLE_SIZE / 2) - 1;

typedef struct bucket{
    int chave[BUCKET_SIZE];  // Vetor de chaves
    int qtt_chaves;  // Quantidade de chaves atualmente no bucket
    int desvio_index;  // Indice na tabela onde os próximos elementos de mesmo hash serão armazenados
} bucket;

// Calcula o valor de hash de um dado elemento
// TODO: Modificar para retornar somente indexes até metade da tabela
int hash(int chave){ return chave % TABLE_SIZE; }

int main (void){
    bucket tabela[TABLE_SIZE];  // A tabela é um vetor de buckets

    // Inicializando a tabela
    for (int i = 0; i < TABLE_SIZE; ++i){
        tabela[i].qtt_chaves = 0;
        tabela[i].desvio_index = -1;  // -1 indica que não há desvio (ainda)
    }

    int chave;
    while (true){
        scanf("%i", &chave);
        // chamar a funcao de inserir
        insere_na_tabela(chave, hash(chave), tabela);
    }

}

void insere_na_tabela(int chave, int pos, bucket tabela[]){
    if (tabela[pos].qtt_chaves < BUCKET_SIZE){
        // INSERE
    } else {
        // SPILL
    }
}