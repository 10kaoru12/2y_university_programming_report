#include <stdio.h>
#include <stdlib.h>
#define ZEI 1.08

typedef struct
{
    char *name;
    int tanka;
    int sotozei;
} SHOHIN;

typedef struct
{
    int code;
    int num;
} URIAGE;

typedef struct uriagelist
{
    struct uriagelist *next;
    URIAGE *uriage;
} URIAGELIST;

void printUriageList(URIAGELIST *l);
URIAGELIST *newlist(void);
void freeUriageList(URIAGELIST *l, int purge);
URIAGELIST *add(URIAGELIST *l, URIAGE *u);

SHOHIN shohin[] = {{"Apple", 150}, {"Orange", 100}, {"Banana", 200}, {"Book1", 500, 1}, {"", 0}};

int main(void)
{
    URIAGE u1 = {1, 2};
    URIAGE u2 = {2, 3};
    URIAGE u3 = {3, 4};
    URIAGELIST l0 = {NULL};
    URIAGELIST l1 = {&l0, &u1};
    URIAGELIST l2 = {&l1, &u2};
    URIAGELIST l3 = {&l2, &u3};
    printf("-----\n");
    printUriageList(&l0);
    printf("-----\n");
    printUriageList(&l1);
    printf("-----\n");
    printUriageList(&l2);
    printf("-----\n");
    printUriageList(&l3);
    return 0;
}

void printUriageList(URIAGELIST *l)
{
    int i;
    int sotozei;
    int tanka;
    int num;
    char *name;
    int syoukei;
    double zeisyoukei;
    int sum = 0;
    for (i = 0; l->next != NULL; i++)
    {
        sotozei = shohin[l->uriage->code].sotozei;
        tanka = shohin[l->uriage->code].tanka;
        num = l->uriage->num;
        name = shohin[l->uriage->code].name;
        syoukei = num * tanka;
        zeisyoukei = num * tanka * ZEI;
        if (l->next != NULL)
        {
            if (sotozei == 0)
            {
                printf("%s\t単価%d円(内税) %d 個\t%d 円\n", name, tanka, num, syoukei);
            }
            else
            {
                printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", name, tanka, num, zeisyoukei);
                sum += zeisyoukei;
            }
        }
        l = l->next;
    }
}
