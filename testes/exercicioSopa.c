//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct pote
{
    int sopaA, sopaB;
}pote;


bool remove (pote* balde, int removeA, int removeB){
    if (balde->sopaA < removeA || balde->sopaB < removeB)
        return false; 
    balde->sopaA -= removeA;
    balde->sopaB -= removeB;
    return true;
}
int main (void){
    int n;
    scanf("%i", &n);

    pote balde;
    balde.sopaA = balde.sopaB = n;

    time_t t;
    time(&t);
    unsigned int op = (unsigned int)t;
    srand(op);

    /*Sirva 100ml de sopa A e 0ml de sopa B ,
    Sirva 75ml de sopa A e 25ml de sopa B ,
    Sirva 50ml de sopa A e 50ml de sopa B , e
    Sirva 25ml de sopa A e 75ml de sopa B .*/
    for (int i = 0; i < 100; i++){
        while (balde.sopaA > 0 && balde.sopaB > 0){
            op = rand() % 4;
            switch (op){
                case 0: remove (&balde, 100, 0);
                    break;
                case 1: remove (&balde, 75, 25);
                    break;
                case 2: remove (&balde, 50, 50);
                    break;
                case 3: remove (&balde, 25, 75);
                    break;
                default:
                    break;
            }
        }
        
    }

}