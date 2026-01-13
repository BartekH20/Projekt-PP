#include <stdio.h>
#include "wynalazek.h"
#include "plik.h"

void menu();

int main(int argc, char **argv) {
        const char *plik = "wynalazki.bin";

    if (argc >= 2) {
        plik = argv[1];
    }
    Wynalazek *lista=NULL;
    int x;
    do {
        menu();
        scanf("%d",&x);
        getchar();
        switch(x) {
            case 1: lista=dodaj(lista); break;
            case 2: lista=edytuj(lista); break;
            case 3: lista=usun(lista); break;
            case 4: wyswietl(lista); break;
            case 5: wyszukaj(lista); break;
            case 6: lista = sortuj_nazwa(lista); break;
            case 7: lista = sortuj_niezawodnosc(lista); break;
            case 8: zapisz(lista,argv[1]); break;
            case 9: zwolnij(lista); lista=wczytaj(argv[1]); break;
        }
    } while (x!=0);
    zwolnij(lista);
    return 0;
}
