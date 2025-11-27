#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SA.h"

int main() {
    FILE *arq = fopen("entrada.txt", "r");
    if(!arq){
        printf("Erro ao abrir entrada.txt\n");
        return 1;
    }

    int n;
    float capacidade;
    fscanf(arq, "%d %f", &n, &capacidade);

    float *peso = (float*) malloc(n * sizeof(float));
    float *valor = (float*) malloc(n * sizeof(float));
    int *s = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        fscanf(arq, "%f %f", &peso[i], &valor[i]);
        s[i] = rand() % 2;
    }
    fclose(arq);

    srand(time(NULL));

    float melhor = SimulatedAnnealing(n, s, peso, valor, capacidade,
                                      1000.0f, 0.01f, 0.95f, 200);

    printf("Itens escolhidos: ");
    for(int i = 0; i < n; i++) printf("%d ", s[i]);
    printf("\n");

    free(peso);
    free(valor);
    free(s);
    return 0;
}
