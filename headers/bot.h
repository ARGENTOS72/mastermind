#include <stdlib.h>
#include <time.h>

#include "mastermind.h"

#ifndef BOT_H
#define BOT_H

int counter2 = 0;
char dizionario[5] = {'R', 'M', 'V', 'A', 'G'};
char colUtilizzati[4];
char colGiusti[4];

char stampaColore(int x) {
  char colore;
  
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

char indovinoBotColori(int consiglio, int i) {
  char coloreC;
  int coloreInt;

  srand(time(NULL));

  printf("--> ");

  if (counter2 < 4) {
    int coloreR;

    coloreR = rand() % 5 + 1;

    coloreC = stampaColore(coloreR);

    colUtilizzati[i] = coloreC;

    counter2++;
  } else {
    int j;

    switch (consiglio) {
    case 0:
      for (j = 0; j < 5; j++)
        if (colUtilizzati[i] == dizionario[j])
          dizionario[j] = 'N';

      if (dizionario[i] != 78)
        coloreC = dizionario[i];
      else
        if (i == 0)
          coloreC = dizionario[i + rand() % 4 + 1];
        else
          switch (i) {
          case 1:
            if (rand() % 2)
              coloreC = dizionario[i + rand() % 3 + 1];
            else
              coloreC = dizionario[0];

            break;
          case 2:
            if (rand() % 2)
              coloreC = dizionario[i + rand() % 2 + 1];
            else
              coloreC = dizionario[i - rand() % 2 + 1];

            break;
          case 3:
            if (rand() % 2)
              coloreC = dizionario[i - rand() % 3 + 1];
            else
              coloreC = dizionario[4];

            break;
          case 4:
            coloreC = dizionario[i - rand() % 4 + 1];

            break;
          }
      break;
    case 1:
      colGiusti[i] == colUtilizzati[i];
      
      coloreC = colGiusti[i];

      break;
    case 2:
      if (dizionario[i] != 78)
        coloreC = dizionario[i];
      else
        if (i == 0)
          coloreC = dizionario[i + rand() % 4 + 1];
        else
          switch (i) {
          case 1:
            if (rand() % 2)
              coloreC = dizionario[i + rand() % 3 + 1];
            else
              coloreC = dizionario[0];

            break;
          case 2:
            if (rand() % 2)
              coloreC = dizionario[i + rand() % 2 + 1];
            else
              coloreC = dizionario[i - rand() % 2 + 1];

            break;
          case 3:
            if (rand() % 2)
              coloreC = dizionario[i - rand() % 3 + 1];
            else
              coloreC = dizionario[4];

            break;
          case 4:
            coloreC = dizionario[i - rand() % 4 + 1];
            break;
          }
      break;
    }

    coloreInt = (int) coloreC;

    char prova = stampaColore(coloreInt);
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