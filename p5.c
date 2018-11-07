#include <stdio.h>

typedef 
unsigned long long int 
Bytes8; 
typedef struct LCG { 
Bytes8 a, c, m, rand_max, atual; 
} 
LCG;

void semente(LCG *r, Bytes8 seed);
Bytes8 lcg_rand(LCG *r);
double lcg_rand_01(LCG *r);
void gera_numeros(float *vetor, int tam, float min, float max, LCG *r);
float soma(float vet[50], int n, int i);
float produto(float vet[50], int n, int i);
void operacao(float vet[50], int n);

int main(int argc, char const *argv[]) {
  LCG random;
  float vetor[50];
  semente(&random, 123456);
  gera_numeros(vetor, 50, 0.5, 1.5, &random);
  operacao(vetor, 50);
  return 0;
}

void operacao(float vet[50], int n)
{
	int input = 0;
	printf("1 - Somatorio\n2 - Produtorio\n");
	scanf("%d", &input);
	getchar();
	if (input==1){
		printf("%f", soma(vet, n, 0));
	} 
	else if (input==2){
		printf("%f", produto(vet, n, 0));
	}
	
}

float soma(float vet[50], int n, int i) {
    float resultado=0;
    if(i+1 <= n)
	{
	resultado = vet[i] + soma(vet, n, i+1);
    }
    return resultado;
}

float produto(float vet[50], int n, int i) {
    float resultado=1;
    if(i+1 <= n)
	{
	resultado = vet[i] * produto(vet, n, i+1);
    }
    return resultado;
}

void semente(LCG * r, Bytes8 seed) {
    r->a = 0x5DEECE66DULL; r->c = 11ULL; 
    r->m = (1ULL << 48); 
    r->rand_max = r->m - 1; 
    r->atual = seed; 
} 
Bytes8 lcg_rand(LCG * r) { 
    r->atual = (r->a * r->atual + r->c) % r->m; 
    return r->atual; 
} 
double lcg_rand_01(LCG * r) { 
    return ((double) lcg_rand(r))/(r->rand_max); 
}

void gera_numeros(float *vetor, int tam, float min, float max, LCG *r) {
  int i;
  for(i = 0; i < tam; i++) {
    vetor[i] = (max - min) * lcg_rand_01(r) + min;
  }
}

