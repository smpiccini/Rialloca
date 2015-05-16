#include <stdio.h>
#include <stdlib.h>

int* rialloca(int* ArrayCorrente, int dimensioneCorrente);

int main(int argc, char** argv) {
    int dimensione=2;
    int i;
    int *p;
    p=(int*)malloc(dimensione*sizeof(int));
    int numeriInseriti;
    i=0;
    do {
        if (i==dimensione) {
            p=rialloca(p, dimensione);
            dimensione*=2;
        }
        printf("Inserisci il %d° numero (0 per terminare): ", i+1);
        scanf("%d", &p[i]);
        i++;
    } while(p[i-1]!=0);
    numeriInseriti=i;
    printf("\nSono stati inseriti i seguenti numeri:\n");
    for(i=0;i<numeriInseriti;i++) {
        printf("%d\n", p[i]);
    }
    return (EXIT_SUCCESS);
}

int* rialloca(int* ArrayCorrente, int dimensioneCorrente){
    int* nuovoArray;
    int i;
    nuovoArray=(int*)malloc(2*dimensioneCorrente*sizeof(int));
    for(i=0;i<dimensioneCorrente;i++){
        *(nuovoArray+i)=*(ArrayCorrente+i);
    }
    free(ArrayCorrente);
    return nuovoArray;
}
