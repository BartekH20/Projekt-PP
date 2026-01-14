#include <stdio.h>
#include <stdlib.h>
#include "plik.h"

void zapisz(Wynalazek *lista, const char *nazwa) {
    FILE *f=fopen(nazwa,"wb");
    if (!f) return;
    for (;lista;lista=lista->next)
        fwrite(lista,sizeof(Wynalazek)-sizeof(Wynalazek*),1,f);
    fclose(f);
    printf("===Zapisano pomyslnie!=== \n");
}


Wynalazek* wczytaj(const char *nazwa) {
    FILE *f=fopen(nazwa,"rb");
    if (!f) return NULL;
    Wynalazek *lista=NULL;
    while (1) {
        Wynalazek *x=malloc(sizeof(Wynalazek));
        if (fread(x,sizeof(Wynalazek)-sizeof(Wynalazek*),1,f)!=1) {
            free(x); break;
        }
        x->next=lista; lista=x;
    }
    fclose(f);
    printf("===Wczytano pomyslnie!=== \n");
    return lista;

}
