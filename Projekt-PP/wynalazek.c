#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wynalazek.h"

static Status wczytaj_status() {
    int x;
    printf("0-PROTOTYP 1-W_TESTACH 2-DOPUSZCZONY 3-ZAKAZANY 4-NIESTABILNY: ");
    scanf("%d", &x);
    getchar();
    return (Status)x;
}

const char* status_str(Status s) {
    const char *t[] = {"PROTOTYP","W_TESTACH","DOPUSZCZONY","ZAKAZANY","NIESTABILNY"};
    return t[s];
}

Wynalazek* dodaj(Wynalazek *lista) {
    Wynalazek *nowy = malloc(sizeof(Wynalazek));
    if (!nowy) return lista;

    printf("Nazwa: ");
    fgets(nowy->nazwa, 101, stdin);
    nowy->nazwa[strcspn(nowy->nazwa,"\n")] = 0;

    for (Wynalazek *p = lista; p; p = p->next)
        if (!strcmp(p->nazwa, nowy->nazwa)) {
            printf("Nazwa musi byc unikalna!\n");
            free(nowy);
            return lista;
        }

    printf("Typ: ");
    fgets(nowy->typ, 32, stdin);
    nowy->typ[strcspn(nowy->typ,"\n")] = 0;

    printf("Niezawodnosc (0-100): ");
    scanf("%d", &nowy->niezawodnosc);

    printf("Zapotrzebowanie energetyczne: ");
    scanf("%f", &nowy->energia);
    getchar();

    nowy->status = wczytaj_status();
    nowy->next = lista;
    return nowy;
}

void wyswietl(Wynalazek *lista) {
    printf("\n%-20s %-15s %-5s %-8s %-15s\n", "NAZWA","TYP","NZ","ENERGIA","STATUS");
    for (; lista; lista = lista->next)
        printf("%-20s %-15s %-5d %-8.2f %-15s\n",
               lista->nazwa, lista->typ,
               lista->niezawodnosc, lista->energia,
               status_str(lista->status));
}

Wynalazek* edytuj(Wynalazek *lista) {
    char nazwa[101];
    printf("Podaj nazwe: ");
    fgets(nazwa,101,stdin);
    nazwa[strcspn(nazwa,"\n")] = 0;

    for (Wynalazek *p=lista;p;p=p->next)
        if (!strcmp(p->nazwa,nazwa)) {
            printf("Nowy typ: ");
            fgets(p->typ,32,stdin);
            p->typ[strcspn(p->typ,"\n")] = 0;

            printf("Nowa niezawodnosc: ");
            scanf("%d",&p->niezawodnosc);
            printf("Nowa energia: ");
            scanf("%f",&p->energia);
            getchar();
            p->status = wczytaj_status();
            return lista;
        }
    printf("===Nie znaleziono!===\n");
    return lista;
}

Wynalazek* usun(Wynalazek *lista) {
    char nazwa[101];
    printf("Podaj nazwe: ");
    fgets(nazwa,101,stdin);
    nazwa[strcspn(nazwa,"\n")] = 0;

    Wynalazek *p=lista,*prev=NULL;
    while (p) {
        if (!strcmp(p->nazwa,nazwa)) {
            if (p->status==ZAKAZANY || p->status==NIESTABILNY) {
                printf("===Nie mozna usunac!===\n");
                return lista;
            }
            if (prev) prev->next=p->next;
            else lista=p->next;
            free(p);
            printf("===Usunieto pomyslnie!===");
            return lista;
        }
        prev=p; p=p->next;
    }
    printf("===Nie znaleziono!===\n");
    return lista;
}

void wyszukaj(Wynalazek *lista) {
    char szukana[101];
    printf("Podaj nazwe wynalazku do wyszukania: ");
    fgets(szukana, 101, stdin);
    szukana[strcspn(szukana, "\n")] = 0;

    int znaleziono = 0;
    for (; lista; lista = lista->next) {
        if (strcmp(lista->nazwa, szukana) == 0) {
            printf("%-20s %-15s %-5d %-8.2f %-15s\n",
                   lista->nazwa, lista->typ,
                   lista->niezawodnosc, lista->energia,
                   status_str(lista->status));
            znaleziono = 1;
            break;
        }
    }

    if (!znaleziono)
        printf("===Nie znaleziono wynalazku o nazwie \"%s\".===\n", szukana);
}

void zwolnij(Wynalazek *lista) {
    while (lista) {
        Wynalazek *tmp=lista;
        lista=lista->next;
        free(tmp);
    }
}
Wynalazek* sortuj_nazwa(Wynalazek *lista) {
    Wynalazek *sorted=NULL;
    while (lista) {
        Wynalazek *x=lista;
        lista=lista->next;
        if (!sorted || strcmp(x->nazwa,sorted->nazwa)<0) {
            x->next=sorted; sorted=x;
        } else {
            Wynalazek *p=sorted;
            while (p->next && strcmp(p->next->nazwa,x->nazwa)<0)
                p=p->next;
            x->next=p->next; p->next=x;
        }
    }
    printf("===Posortowano alfabetycznie!===\n");
    return sorted;
}

Wynalazek* sortuj_niezawodnosc(Wynalazek *lista) {
    Wynalazek *sorted=NULL;
    while (lista) {
        Wynalazek *x=lista;
        lista=lista->next;
        if (!sorted || x->niezawodnosc>sorted->niezawodnosc) {
            x->next=sorted; sorted=x;
        } else {
            Wynalazek *p=sorted;
            while (p->next && p->next->niezawodnosc>x->niezawodnosc)
                p=p->next;
            x->next=p->next; p->next=x;
        }
    }
    printf("===Posortowano wg najwiekszej niezawodnosci!===\n");
    return sorted;
}
