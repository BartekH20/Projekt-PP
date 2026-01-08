#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
PROTOTYP,
W_TESTACH,
DOPUSZCZONY,
ZAKAZANY,
NIESTABILNY
}Status;

typedef struct Wynalazek{
char nazwa[101];
char typ[32];
int niezawodnosc;
float energia;
Status status;
struct Wynalazek *next;
}Wynalazek;
void menu()
{
   printf("\n 1.Dodaj \n 2.Edytuj \n 3.Usun \n 4.Wyswietl \n 5.Wyszukaj \n 6.Sortuj wg nazwy \n 7.Sortuj wg niezawodnosci \n 8.Zapisz \n 9.Wczytaj \n 0.Koniec\n");
}

int main(){
int x;
do{
    menu();
    scanf("%d", &x);
    getchar();
    switch(x){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    }
}while(x!=0);
return 0;
}
