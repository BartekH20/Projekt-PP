#include <stdio.h>
#include "wynalazek.h"

void menu();

int main() {
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
        }
    } while (x!=0);
    zwolnij(lista);
    return 0;
}
