#ifndef SA_H
#define SA_H

float SimulatedAnnealing(int n, int *s, float *peso, float *valor, float capacidade, float temp_inicial, float temp_final, float alpha, int SAmax);
float calcula_fo(int n, int *s, float *peso, float *valor, float capacidade);

#endif
