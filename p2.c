/* P2.c */
/* Henrique Rodrigues de Sousa */
/* 11811ECP011 */

#include <stdio.h>

static void dec_bin15(int dec)
{
  int bit;
  int k;
  printf("Numero em binario: ");
  for (bit = 14; bit; bit--)
  {
    k = (unsigned int)dec >> bit;
    printf("%d", (k&1)?1:0);
  }
  k = (unsigned int)dec >> bit;
  printf("%d\n", (k&1)?1:0);
  return;
}

long dec_bin10(long n) {
    int remainder; 
 long binary = 0, i = 1;
  
    while(n != 0) {
        remainder = n%2;
        n = n/2;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

int main ()
{
    long int binario;
	int opcao, num;
    char bit[256];
    printf("Main Menu\n");
    printf("1 - Binario para Decimal\n");
    printf("2 - Binario para Hexadecimal\n");
    printf("3 - Hexadecimal para Decimal\n");
    printf("4 - Hexadecimal para Binario\n");
    printf("5 - Decimal para Binario\n");
    printf("6 - Decimal para Hexadecimal\n");
    printf("7 - Octal para Decimal\n");
    printf("8 - Decimal para Octal\n");
    printf("9 - Sair do programa\n");
    scanf("%d",&opcao);

    switch(opcao){

    case 1:
        printf("Digite o numero que deseja converter:\n");
        scanf("%s", bit);
        getchar();
        printf("Numero em decimal: %d", bin_dec(bit));
        break;
    case 2:
        printf("Digite o numero que deseja converter:\n");
        scanf("%ld", &binario);
        getchar();
        printf("Numero em hexadecimal: %lX", bin_hex(binario));
        break;
    case 3:
        printf("Digite o numero que deseja converter:\n");
        scanf("%x", &num);
        getchar();
        printf("Numero em decimal: %d", num);
        break;
    case 4:
        printf("Digite o numero que deseja converter:\n");
        scanf("%x", &num);
        getchar();
        dec_bin15(num);
        break;
    case 5:
        printf("Digite o numero que deseja converter:\n");
        scanf("%d", &num);
        getchar();
	    printf("Numero em binario: %ld", dec_bin10(num));
		
        break;
    case 6:
        printf("Digite o numero que deseja converter:\n");
        scanf("%d", &num);
        getchar();
        printf("Numero em hexadecimal: %x", num);
        break;
    case 7:
        printf("Digite o numero que deseja converter:\n");
        scanf("%o", &num);
        getchar();
        printf("Numero em decimal: %d", num);
        break;
    case 8:
        printf("Digite o numero que deseja converter:\n");
        scanf("%d", &num);
        getchar();
        printf("Numero em octal: %o", num);
        break;
    case 9:

        break;
    }

while(opcao != 9);

}




int bin_hex(long int binario)
{
    long int  hexadecimal = 0, i = 1, resto; 
    while (binario != 0)
    {
        resto = binario % 10;
        hexadecimal = hexadecimal + resto * i;
        i = i * 2;
        binario = binario / 10;
    }
    
    return hexadecimal;
}

int bin_dec(char bit[])
{
	int i=0, dec=0, a=0;
	for (a; bit[a] != '\0'; a++){}
	a = a-1;
	for (a, i; bit[a] != '\0'; a--, i++){
		if (bit[a]=='1'){
			dec = dec + power(2, i);
		}
		else 
		dec = dec;
	}
    
	return dec;
}


int power(int base,int exp)
{
	int i=0, pow=1;
	for (i; i < exp; i++){
		pow = pow * base;
	}
	return(pow);
}
