/* P3.c */
/* Henrique Rodrigues de Sousa */
/* 11811ECP011 */

#include <stdio.h>

int power(int base,int exp)
{
	int i=0, pow=1;
	if(exp==0)
	pow = 1;
	else
	{
	for (i; i < exp; i++){
		pow = pow * base;
	}
    }
	return pow;
}

int main()
{
	int i, j=0, numero = 0, exp, num[256];
	char str[256];
	scanf("%s", str);
	for(i=0; str[i] != '\0'; i++)
	{
		if(str[i] >= 48 && str[i] <= 57)
		{
			num[j] = str[i] - 48;
			j++;
		}
	}
	if(j==0){
	printf("0");
    }
	else 
	{
	exp = j-1;
	for(i=0; i < j; i++)
	{
		numero = numero + (num[i] * power(10, exp));
		exp--;
	}
	printf("%d", numero);
    }
	return 0;
}

