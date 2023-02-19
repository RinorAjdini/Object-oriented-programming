#include <stdio.h>
typedef struct proizvod
{
    char ime[30];
    float kolicina;
    float cena;
}proizvod;
int main(){
proizvod p[100];
int i,n;
float total=0;
scanf("%d", &n);
for(int i=1;i<=n; i++)
{
    scanf("%s", &p[i].ime);
    scanf("%f", &p[i].cena);
    scanf("%f", &p[i].kolicina);
}
for(int i=1; i<=n; i++)
{
    printf("%d. %s\t%.2f x %.1f = %.2f\n",i,p[i].ime,p[i].cena,p[i].kolicina,p[i].kolicina*p[i].cena);
    total=total+p[i].cena*p[i].kolicina;
}
printf("Total: %.2f",total);
return 0;
}
