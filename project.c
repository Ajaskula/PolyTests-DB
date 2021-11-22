#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 11
void suma(int wynik[], int skladnik[]) {
        for (int i = 0; i < N; i++) 
                wynik[i] += skladnik[i];
}
 
void iloczyn(int wynik[], int czynnik[],int stopien_czynnika) {
        int tab_pom[N];
        for (int i = 0; i < N; i++) tab_pom[i] = wynik[i];
        for (int i = 0; i < N; i++) wynik[i] = 0;
        for (int i = 0; i <= stopien_czynnika; i++) {
                for (int j = 0; j < N; j++) {
                        wynik[j + i] += tab_pom[j] * czynnik[i];
                }
        }
} 


char wczytaj() {
        char znak = (char) getchar();
        if (znak != ' ') return znak;
        else return wczytaj();
}

int wczytywanie_wspolczynnika(int cyfry[], int j, char *cyfra) {
        while (*cyfra != '+' && *cyfra != '-' && *cyfra != '^' && *cyfra != '\n' && *cyfra != 'x') {>
                cyfry[j] = (int) *cyfra - 48;
        //      printf("\n%d\n", cyfry[j]);
                *cyfra = wczytaj();
                j++;
        }
        int wspolczynnik = 0;
        for (int k = 1; k < j; k++) 
                wspolczynnik += cyfry[k] * (int) pow(10, j-k-1);
        if (cyfry[0] == 0) wspolczynnik = -wspolczynnik;
        return wspolczynnik;
} 
char wczytywanie_potegi(int tab[],int *stopien_wielomianu, int wspolczynnik) {
//      printf("jest x\n");
        char znak_potegowania = wczytaj();
        char znak;
        if (znak_potegowania != '^' && znak_potegowania != '\n') {
                if (wspolczynnik != 0) tab[1] = wspolczynnik;
                else tab[1] = 1;
                *stopien_wielomianu = (int) fmax(*stopien_wielomianu, 1);
                znak = znak_potegowania;;
        }
        else if (znak_potegowania == '\n') {
                tab[1] = 1; 
                znak = '\n';
        }
        else {
                char potega = wczytaj();
                znak = wczytaj();
                if (znak == '0') {
                        tab[10] = wspolczynnik;
                        znak = wczytaj();
                }
                else tab[(int) potega - 48] = wspolczynnik;
        *stopien_wielomianu = (int) fmax(*stopien_wielomianu,(int) potega - 48);
        }
        return znak;
}
void input(int tab[], int *stopien_wielomianu, char *dzialanie, bool *kolejny_wiersz) {
        for (int i = 0; i < N; i++) tab[i] = 0;
        *stopien_wielomianu = 0;
        *dzialanie = wczytaj();
        if (*dzialanie == '.') *kolejny_wiersz = false;
        char znak = wczytaj();
        while (znak != '\n' && *kolejny_wiersz) {
        //      printf("znowu\n");
                int cyfry[11];
                for (int i = 1; i < 11; i++) cyfry[i] = 0;
                cyfry[0] = 1;                                 // Wczytywanie znaku wspolczynnika w t>
                int j = 1;
                bool skladnik_wielomianu_wczytany = false;
                if (znak == '-') cyfry[0] = 0;
                else if (znak != '+') {
                        if (znak != 'x' ) {           //jesli wczytany znak nie jest '+' ani '-', to>
                                cyfry[1] = (int) znak - 48;
                                j++;
                        }
                        else {
                                int wspolczynnik = 1;
                                znak = wczytywanie_potegi(tab, stopien_wielomianu, wspolczynnik);
                                skladnik_wielomianu_wczytany = true;
                        }                                   //jesli przed x nie wystepuje zadna cyfr>
                }
//              printf("%d\n", cyfry[1]);
                if (!skladnik_wielomianu_wczytany) {
                        char cyfra = wczytaj();
        //              putchar(cyfra);
                        if (cyfra != '\n') {
        //                      printf("cyfra to nie enter\n");
                                int wspolczynnik = wczytywanie_wspolczynnika(cyfry, j, &cyfra);

                                if (cyfra == 'x') {
                                        znak = wczytywanie_potegi(tab, stopien_wielomianu, wspolczyn>
                                }
                                else {
        //                              printf("Nie ma x\n");
                                        tab[0] = wspolczynnik;
                                        znak = cyfra;
                                }
                        }
                        else {
                                tab[0] = cyfry[1];
                                znak = '\n';
                        }
                }
        }

}
void zwracanie_skladnikow_wielomianu(int wynik[], int i) {
        if (i == 0) printf("%d", abs(wynik[i]));
        else if (i == 1){
                if (wynik[i] != 1 && wynik[i] != -1)
                 printf("%dx", abs(wynik[i]));
                else printf("x");
        }
        else if (wynik[i] != 1 && wynik[i] != -1)
                printf("%dx^%d", abs(wynik[i]), i);
        else printf("x^%d", i);
}

void output(int wynik[]) {
        int i = N-1;
        while (i >= 0 && wynik[i] == 0) i--;
        if (i < 0)
                printf("0\n");
        else
                zwracanie_skladnikow_wielomianu(wynik, i);
        for (int j = i - 1; j >= 0; j--)
                if (wynik[j] != 0) {
                        if (wynik[i] > 0) printf(" + ");
                        else printf(" - ");
                        zwracanie_skladnikow_wielomianu(wynik, j);
                }
        printf("\n");
}
                                                                 
void zwracanie_skladnikow_wielomianu(int wynik[], int i) {
        if (i == 0) printf("%d", abs(wynik[i]));
        else if (i == 1){
                if (wynik[i] != 1 && wynik[i] != -1)
                 printf("%dx", abs(wynik[i]));
                else printf("x");
        }
        else if (wynik[i] != 1 && wynik[i] != -1)
                printf("%dx^%d", abs(wynik[i]), i);
        else printf("x^%d", i);
}

void output(int wynik[]) {
        int i = N-1;
        while (i >= 0 && wynik[i] == 0) i--;
        if (i < 0)
                printf("0\n");
        else
                zwracanie_skladnikow_wielomianu(wynik, i);
        for (int j = i - 1; j >= 0; j--)
                if (wynik[j] != 0) {
                        if (wynik[i] > 0) printf(" + ");
                        else printf(" - ");
                        zwracanie_skladnikow_wielomianu(wynik, j);
                }
        printf("\n");
}


