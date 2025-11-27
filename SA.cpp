#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "SA.h"

float calcula_fo(int n, int *s, float *peso, float *valor, float capacidade) {
    float peso_total = 0, valor_total = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 1){
            peso_total += peso[i];
            valor_total += valor[i];
        }
    }
    if(peso_total > capacidade)
        return valor_total - 1000.0f * (peso_total - capacidade); // penalização
    return valor_total;
}

float SimulatedAnnealing(int n,
                         int *s,
                         float *peso,
                         float *valor,
                         float capacidade,
                         float temp_inicial,
                         float temp_final,
                         float alpha,
                         int SAmax)
{
    FILE *log = fopen("SA_log.txt", "w");
    fprintf(log, "Passo;Temperatura;FO_atual;FO_vizinho;Melhor_FO;Movimento_Aceito\n");

    float fo = calcula_fo(n, s, peso, valor, capacidade);
    float melhor_fo = fo;

    int *melhor_s = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) melhor_s[i] = s[i];

    float temp = temp_inicial;

    clock_t inicio = clock();

    while(temp > temp_final){
        for(int iter = 0; iter < SAmax; iter++){
            int k = rand() % n;
            s[k] = 1 - s[k]; // flip

            float fo_viz = calcula_fo(n, s, peso, valor, capacidade);
            float delta = fo_viz - fo;

            int aceito = 0;

            if(delta >= 0){
                fo = fo_viz;
                aceito = 1;

                if(fo > melhor_fo){
                    melhor_fo = fo;
                    for(int i = 0; i < n; i++) melhor_s[i] = s[i];
                }
            } else {
                float x = ((float) rand() / RAND_MAX);
                if(x < exp(delta / temp)){
                    fo = fo_viz;
                    aceito = 1;
                } else {
                    s[k] = 1 - s[k]; // desfaz
                }
            }

            fprintf(log, "%d;%.4f;%.4f;%.4f;%.4f;%d\n", iter, temp, fo, fo_viz, melhor_fo, aceito);
        }
        temp *= alpha;
    }

    clock_t fim = clock();
    double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // GAP relativo à melhor solução
    double gap = (melhor_fo - fo) / melhor_fo * 100.0;

    printf("\n=== RESULTADOS FINAIS ===\n");
    printf("Melhor valor encontrado: %.2f\n", melhor_fo);
    printf("Tempo de execução: %.4f segundos\n", tempo_total);
    printf("GAP: %.4f %%\n", gap);

    for(int i = 0; i < n; i++) s[i] = melhor_s[i];
    free(melhor_s);
    fclose(log);

    return melhor_fo;
}
