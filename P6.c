/* P6.c */
/* Henrique Rodrigues de Sousa */
/* 11811ECP011 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	float x;
	float y;
} Ponto;

int main()
{
	Ponto *p;
	int divisoes, i;
	float angulo_var;
	printf("Digite o numero de divisoes:\n\n");
	scanf("%d", &divisoes); 
	getchar();
	p = (Ponto *)malloc(divisoes*sizeof(Ponto));
	angulo_var = 2*M_PI/(divisoes-1);
	for (i=0;i<divisoes;i++)
	{
		p[i].x = cos(i*angulo_var);
		p[i].y = sin(i*angulo_var);
		printf("(%.3f, %.3f) ", p[i].x, p[i].y);
	}
	free(p);
	return 0; 
}
