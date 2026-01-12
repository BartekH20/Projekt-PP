#ifndef WYNALAZEK_H
#define WYNALAZEK_H

typedef enum {
    PROTOTYP,
    W_TESTACH,
    DOPUSZCZONY,
    ZAKAZANY,
    NIESTABILNY
} Status;

typedef struct Wynalazek {
    char nazwa[101];
    char typ[32];
    int niezawodnosc;
    float energia;
    Status status;
    struct Wynalazek *next;
} Wynalazek;

Wynalazek* dodaj(Wynalazek *lista);
void wyswietl(Wynalazek *lista);
Wynalazek* edytuj(Wynalazek *lista);
Wynalazek* usun(Wynalazek *lista);
void wyszukaj(Wynalazek *lista);
void zwolnij(Wynalazek *lista);
const char* status_str(Status s);
Wynalazek* sortuj_nazwa(Wynalazek *lista);
Wynalazek* sortuj_niezawodnosc(Wynalazek *lista);



#endif
