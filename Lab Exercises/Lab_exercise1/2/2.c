#include <stdio.h>
#include <stdlib.h>
typedef struct tocka {
    float x;
    float y;
} tocka;
typedef struct otsecka {
    tocka a;
    tocka b;
} otsecka;

int se_secat(otsecka o1, otsecka o2) {
        int seSecat = 0;
    float  k1 = (o1.a.y - o1.b.y)/(o1.a.x - o1.b.x);
    float k2 = (o2.a.y - o2.b.y)/(o2.a.x - o2.b.x);
    float b1 = o1.a.y - k1*o1.a.x;
    float b2 = o2.b.y - k2*o2.b.x;
    if(k1 == k2)
    {
        float ltocka = o1.a.x;
        float dtocka = o2.b.x;
        return ltocka >= dtocka;
    }
    float fk = k1-k2;
    float fb = b1-b2;
    float rezulatat = -fb/fk;
    seSecat = ((rezulatat>=o1.a.x&&rezulatat <= o1.b.x)
	&&(rezulatat>= o2.a.x&&rezulatat <= o2.b.x));
    return seSecat;
}

int main() {
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t1 = { x1, y1 };
    tocka t2 = { x2, y2 };
    otsecka o1 = { t1, t2 };
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    t1.x = x1;
    t1.y = y1;
    t2.x = x2;
    t2.y = y2;
  //tocka t3 = { x1, y1 };
   // tocka t4 = { x2, y2 };
    otsecka o2 = { t1, t2 };
    printf("%d", se_secat(o1, o2));
    return 0;
}
