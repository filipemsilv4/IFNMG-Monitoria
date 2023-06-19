#include "lab.03.c"
#include <stdlib.h>

/* Inicializa um polinômio vazio. */
void inicializa_polinomio (Polinomio * ap_pol){
    *ap_pol = (No*) calloc (1,sizeof(No));
    (*ap_pol)->prox = (*ap_pol)->antec = (*ap_pol);
}

/* Define que o coeficiente de grau g do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente (Polinomio pol, int grau, int coef){

    No* percorre = pol;

    if (pol->prox == pol){
        
        No* novo_no = (No*) malloc (sizeof (No));
        novo_no->valor.grau = grau;
        novo_no->valor.coef = coef;

        novo_no->prox = pol;
        novo_no->antec = pol;

        pol->prox = novo_no;
        pol->antec = novo_no;

        return;

    }

    while (percorre->prox->valor.grau < grau && percorre->prox != pol)
        percorre = percorre->prox;
    
    if (percorre->valor.grau == grau){

        percorre->valor.grau = grau;
        percorre->valor.coef = coef;
        return;

    }
    
    No* novo_no = (No*) malloc (sizeof(No));
    novo_no->valor.grau = grau;
    novo_no->valor.coef = coef;

    novo_no->prox = percorre->prox;
    novo_no->antec = percorre;

    percorre->prox->antec = novo_no;
    percorre->prox = novo_no;
    return;

}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera (Polinomio pol){

    pol->antec->prox = NULL;
    No* apagando = pol->prox;

    while (apagando->prox != NULL || apagando != NULL){   
        No* apagar = apagando;
        apagando = apagando->prox;
        free (apagar);
    }

    pol->prox = pol;
    pol->antec = pol;
    return;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma (Polinomio res, Polinomio a, Polinomio b){

    zera (res);

    if (a->prox == a){
        res = b;
        return;
    }
    if (b->prox == b){
        res = a;
        return;
    }

    No* peratualA = a->prox;
    No* peratualB = b->prox;
    
    while (peratualA != a){

        while (peratualB->valor.grau <= peratualA->valor.grau && peratualB != b){
            peratualB = peratualB->prox;
        }
        if (peratualB->valor.grau == peratualA->valor.grau){

            No* novo_no = calloc (1,sizeof(No));

            novo_no->valor.coef = peratualB->valor.coef + peratualA->valor.coef;
            novo_no->valor.grau = peratualB->valor.grau;

            novo_no->prox = res;
            novo_no->antec = res->antec;

            res->antec->prox = novo_no;
            res->antec = novo_no;

        }

        peratualA = peratualA->prox;
        peratualB = b->prox;
    }

    No* peratualRes = res->prox;
    No* peratual;
    peratualA = a->prox;
    peratualB = b->prox;
    

    while (peratualRes != res ){

        while (peratualRes->valor.grau == peratualA->valor.grau && peratualA != a ){
            peratualA = peratualA->prox;
        }
        while (peratualRes->valor.grau == peratualB->valor.grau && peratualB != b ){
            peratualB = peratualB->prox;
        }
        if (peratualRes->valor.grau != peratualA->valor.grau && peratualRes->valor.grau != peratualB->valor.grau ){
            
            No* novo_noResA = calloc (1,sizeof(No));

            novo_noResA->valor.coef = peratual->valor.coef;
            novo_noResA->valor.grau = peratual->valor.grau;

            novo_noResA->prox = res;                                                 // nao existe o caso em que os dois sao iguais
            novo_noResA->antec = res->antec;

            res->antec->prox = novo_noResA;
            res->antec = novo_noResA;

            No* novo_noResB = calloc (1,sizeof(No));

            novo_noResB->valor.coef = peratual->valor.coef;
            novo_noResB->valor.grau = peratual->valor.grau;

            novo_noResB->prox = res;                                                 // nao existe o caso em que os dois sao iguais
            novo_noResB->antec = res->antec;

            res->antec->prox = novo_noResB;
            res->antec = novo_noResB;
        }
        if (peratualRes->valor.grau != peratualA->valor.grau ){

            No* novo_noResA = calloc (1,sizeof(No));

            novo_noResA->valor.coef = peratual->valor.coef;
            novo_noResA->valor.grau = peratual->valor.grau;

            novo_noResA->prox = res;                                                 // nao existe o caso em que os dois sao iguais
            novo_noResA->antec = res->antec;

            res->antec->prox = novo_noResA;
            res->antec = novo_noResA;


        }
        if(peratualRes->valor.grau != peratualB->valor.grau ){

            No* novo_noResB = calloc (1,sizeof(No));

            novo_noResB->valor.coef = peratual->valor.coef;
            novo_noResB->valor.grau = peratual->valor.grau;

            novo_noResB->prox = res;                                                 // nao existe o caso em que os dois sao iguais
            novo_noResB->antec = res->antec;

            res->antec->prox = novo_noResB;
            res->antec = novo_noResB;
        }
        peratualA = a->prox;
        peratualB = b->prox;
        peratualRes = peratualRes->prox;

    }

}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai (Polinomio res, Polinomio a, Polinomio b){
    
    return;
}

/* /\* Computa a multiplicacao dos polinomios a e b colocando o resultado em res.  */
/*  * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. *\/ */
/* void multiplica(Polinomio res, Polinomio a, Polinomio b); */

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime (Polinomio pol){

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
void desaloca_polinomio (Polinomio *ap_pol){
        
    No* apagando = (*ap_pol)->prox;
    (*ap_pol)->antec->prox = NULL;
    while (apagando->prox != NULL || apagando != NULL){   
        No* apagar = apagando;
        apagando = apagando->prox;
        free (apagar);
    }   
    free (ap_pol); 
    return;
}