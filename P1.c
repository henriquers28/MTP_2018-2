/* P1.c */
/* Henrique Rodrigues de Sousa */
/* 11811ECP011 */
#include <stdio.h>

int main()

{
    
int state=0, i=0;
char bits[256];
printf("Digite a sequencia binaria: ");
scanf("%s", bits);
for(i; bits[i] != '\0'; i++)
{
    if(state==0)
    {
        if(bits[i]=='0')
        state=0;
        else if(bits[i]=='1')
        state=1;
    }
    else if(state==1)
    {
        if(bits[i]=='0')
        state=2;
        else if(bits[i]=='1')
        state=0;
    }
    else if(state==2)
    {
        if(bits[i]=='0')
        state=1;
        else if(bits[i]=='1')
        state=2;
    }
}
if(state==0)
{
printf("%s e multiplo de 3.", bits);
}
else
{
printf("%s nao e multiplo de 3.", bits);
}
    
return 0;
}