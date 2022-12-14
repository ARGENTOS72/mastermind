#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "mastermind.h"

#ifndef BOT_H
#define BOT_H

char dizionario[5] = {'R', 'M', 'V', 'A', 'G'};
char colUtilizzati[4];
char colGiusti[4];

char stampaColore(int x) {
  char colore;

  printf("%d ", x);
  
  switch (x) {
  case 82:
  case 1:
    printf(RED_BG "  " RESET);
    colore = 'R';
    break;
  case 77:
  case 2:
    printf(PURPLE_BG "  " RESET);
    colore = 'M';
    break;
  case 86:
  case 3:
    printf(GREEN_BG "  " RESET);
    colore = 'V';
    break;
  case 65:
  case 4:
    printf(LIGHT_BLUE_BG "  " RESET);
    colore = 'A';
    break;
  case 71:
  case 5:
    printf(YELLOW_BG "  " RESET);
    colore = 'G';
    break;
  }

  return colore;
} 

char sceltaBotColori() {
  int coloreR;
  char colore;

  srand(time(NULL));

  coloreR = rand() % 5 + 1;

  switch (coloreR) {
  case 1:
    colore = 'R';
    break;
  case 2:
    colore = 'M';
    break;
  case 3:
    colore = 'V';
    break;
  case 4:
    colore = 'A';
    break;
  case 5:
    colore = 'G';
    break;
  }

  return colore;
}

char indovinoBotColori(int consiglio, int i, int tentativi) {
  char coloreC;
  int coloreInt, x, j;

  srand(time(NULL));

  printf("--> ");

  if (!tentativi) {
    int coloreR;

    coloreR = rand() % 5 + 1;

    coloreC = stampaColore(coloreR);

    colUtilizzati[i] = coloreC;
  } else {
    switch (consiglio) {
    case 0:
      for (j = 0; j < 5; j++) {
        if (colUtilizzati[i] == dizionario[j]) {
          dizionario[j] = 'N';
        }
      }

      if (dizionario[i] != 'N') {
        while (true) {
          x = rand() % 5;
          if (dizionario[x] != 'N') {
            coloreC = dizionario[x];

            break;
          }
        }
      } else {
        if (i == 0) {
          while (true) {
            x = rand() % 4 + 1;
            if (dizionario[x] != 'N') {
              coloreC = dizionario[x];

              break;
            }
          }
        } else {
          switch (i) {
          case 1:
            while (true) {
              x = rand() % 3 + 1;
              if (dizionario[i + x] != 'N') {
                coloreC = dizionario[i + x];

                break;
              } else if (dizionario[0] != 'N') {
                coloreC = dizionario[0];

                break;
              }
            }
            break;
          case 2:
            while (true) {
              x = rand() % 2 + 1;
              if (dizionario[i + x] != 'N') {
                coloreC = dizionario[i + x];

                break;
              } else if (dizionario[0] != 'N') {
                dizionario[i - x];

                break;
              }
            }
            break;
          case 3:
            while (true) {
              x = rand() % 3 + 1;
              if (dizionario[i - x] != 'N') {
                coloreC = dizionario[i - x];

                break;
              } else if (dizionario[4] != 'N') {
                coloreC = dizionario[4];

                break;
              }
            }
            break;
          case 4:
            while (true) {
              x = rand() % 4 + 1;
              if (dizionario[i - x] != 'N') {
                coloreC = dizionario[i - x];

                break;
              }
            }
            break;
          }
        }
      }
      break;
    case 1:     
      coloreC = colUtilizzati[i];

      break;
    case 2:
      if (dizionario[i] != 'N') {
        while (true) {
          x = rand() % 5;
          if (dizionario[x] != 'N') {
            coloreC = dizionario[x];

            break;
          }
        }
      } else {
        if (i == 0) {
          while (true) {
            x = rand() % 4 + 1;
            if (dizionario[i + x] != 'N') {
              coloreC = dizionario[i + x];

              break;
            }
          }
        } else {
          switch (i) {
          case 1:
            while (true) {
              x = rand() % 3 + 1;
              if (dizionario[i + x] != 'N') {
                coloreC = dizionario[i + x];

                break;
              } else if (dizionario[0] != 'N') {
                coloreC = dizionario[0];

                break;
              }
            }
            break;
          case 2:
            while (true) {
              x = rand() % 2 + 1;
              if (dizionario[i + x] != 'N') {
                coloreC = dizionario[i + x];

                break;
              } else if (dizionario[0] != 'N') {
                dizionario[i - x];

                break;
              }
            }
            break;
          case 3:
            while (true) {
              x = rand() % 3 + 1;
              if (dizionario[i - x] != 'N') {
                coloreC = dizionario[i - x];

                break;
              } else if (dizionario[4] != 'N') {
                coloreC = dizionario[4];

                break;
              }
            }
            break;
          case 4:
            while (true) {
              x = rand() % 4 + 1;
              if (dizionario[i - x] != 'N') {
                coloreC = dizionario[i - x];

                break;
              }
            }
            break;
          }
        }
      }
      break;
    }

    coloreInt = (int) coloreC;

    char prova = stampaColore(coloreInt);

    colUtilizzati[i] = coloreC;
  }

  printf("\n");

  return coloreC;
}

void coloriSceltiBotPrint(char colori[]) {
  int i;

  gotoxy(X_POS - 46, 1);

  printf("Colori scelti dal mastermind(bot):");

  for (i = 0; i < DIM_COL; i++) {
    switch (colori[i]) {
    case 'R':
      printf(RED_BG "  " RESET);
      break;
    case 'M':
      printf(PURPLE_BG "  " RESET);
      break;
    case 'V':
      printf(GREEN_BG "  " RESET);
      break;
    case 'A':
      printf(LIGHT_BLUE_BG "  " RESET);
      break;
    case 'G':
      printf(YELLOW_BG "  " RESET);
      break;
    }

    printf(" ");
  }

  gotoxy(1, 1);
}

#endif