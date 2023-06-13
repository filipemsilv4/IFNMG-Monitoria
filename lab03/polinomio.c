#include "lab.03.c"
#include <stdlib.h>
/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){
    *ap_pol = (No*) calloc (1,sizeof(No));
    (*ap_pol)->prox = (*ap_pol)->antec = (*ap_pol);
}

/* Define que o coeficiente de grau g do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    
    if (pol->prox == pol){

        No* novo_no = malloc (sizeof(No));
        novo_no->valor.coef = coef;
        novo_no->valor.grau = grau;
        
        novo_no->prox = pol;
        novo_no->antec = pol;

        pol->prox = novo_no;
        pol->antec = novo_no;
        
        return;
    }
    No* percorre = pol->prox;

    while (grau > percorre->valor.grau && percorre != pol)
        percorre = percorre->prox;
    
    if (grau == percorre->valor.grau){
        percorre->valor.grau = grau;
        percorre->valor.coef = coef;
    } else {
        No* novo_no = (No*) malloc (sizeof(No));
        novo_no->valor.coef = coef;
        novo_no->valor.grau = grau;

        novo_no->prox = percorre->prox;
        novo_no->antec = percorre;
        // ligo  primeiramente o novo_no e, depois o seu sucessor e antecessor a ele
        percorre->prox->antec = novo_no;
        percorre->prox = novo_no;
    }


    
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){

    return;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
    
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){

}

/* /\* Computa a multiplicacao dos polinomios a e b colocando o resultado em res.  */
/*  * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. *\/ */
/* void multiplica(Polinomio res, Polinomio a, Polinomio b); */

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol){

    No* percorre = pol->prox;
    printf("[");
    while(percorre->prox != pol){
        printf ("(%d,%d),", percorre->valor.grau, percorre->valor.coef);
        percorre = percorre->prox;
    }
    printf ("(%d,%d)]\n", percorre->valor.grau, percorre->valor.coef);
    return;
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){
        
    No* apagando = (*ap_pol)->prox;
    (*ap_pol)->antec->prox = NULL;
    while (apagando->prox != NULL || apagando != NULL){   //
        No* apagar = apagando;
        apagando = apagando->prox;
        free (apagar);
    }   
    free(ap_pol); 
    return;
}