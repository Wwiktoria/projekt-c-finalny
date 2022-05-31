#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// ustalam wielkosc siatki
int rzad = 20;
int kolumna = 20;
int k = 1;
char s = '*';
char d = ' ';

// tworzymy granice
int linia_rzedu() {
  printf("\n");
}

// zwracamy ilość żywych sąsiadów
int licz_ilosc_zywych_sasiadow(int a[rzad][kolumna], int r, int c) {
  int i, j, count = 0;
  for (i = r - 1; i <= r + 1; i++) {
    for (j = c - 1; j <= c + 1; j++) {
      if ((i == r && j == c) || (i < 0 || j < 0) ||
          (i >= rzad || j >= kolumna)) {
        continue;
      }
      if (a[i][j] == 1) {
        count++;
      }
    }
  }
  return count;
}

int main() {

  int a[rzad][kolumna], b[rzad][kolumna];
  int i, j;
  int zywe_komorki_sasiadow;
  int c[rzad][kolumna];

  // tworzę macierz z żywymi i martwymi komórkami (losowa)
  for (i = 0; i < rzad; i++) {
    for (j = 0; j < kolumna; j++) {
      a[i][j] = rand() % 2;
    }
  }
  do {

    // obliczam zależności z żywymi sąsiadami
    for (i = 0; i < rzad; i++) {
      for (j = 0; j < kolumna; j++) {
        zywe_komorki_sasiadow = licz_ilosc_zywych_sasiadow(a, i, j);
        if (a[i][j] == 1 &&
            (zywe_komorki_sasiadow == 2 || zywe_komorki_sasiadow == 3)) {
          b[i][j] = 1;
        }

        else if (a[i][j] == 0 && zywe_komorki_sasiadow == 3) {
          b[i][j] = 1;
        }

        else {
          b[i][j] = 0;
        }
      }
    }
     for(i = 0; i < rzad; i++) {
        for (j = 0; j < kolumna; j++) {
            a[i][j]=b[i][j];
        }
    }
    //zamieniamy cyfry na gwiazdki i kropki
    for (i = 0; i < rzad; i++) {
      for (j = 0; j < kolumna; j++) {
            if(b[i][j]==1){
                b[i][j]=s;
            }else{
            b[i][j]=d;
            }
      }
  }

    // wyświetlam następną generację
    printf("\nNastępna generacja:");
    linia_rzedu(rzad);
    for (i = 0; i < rzad; i++) {
      for (j = 0; j < kolumna; j++) {
        printf(" %c ", b[i][j]);
      }
      linia_rzedu(rzad);
    }
    Sleep(2000);
    system("cls");
  } while (k > 0);

  return 0;
}
