#include <ctype.h>

#include "escape.h"

#ifndef MASTERMIND_H
#define MASTERMIND_H

#define DIM_COL 4

char sceltaColori() {
  char colore;

  do {
    printf("--> ");

    fflush(stdin);
    scanf("%c", &colore);

    colore = (char) toupper(colore);

    if (colore != 'R' && colore != 'M' && colore != 'V' && colore != 'A' && colore != 'G')
      printf(RED_BG "Inserisci un valore valido!!\n" RESET);
  } while (colore != 'R' && colore != 'M' && colore != 'V' && colore != 'A' && colore != 'G');

  return colore;
}

void printfColori(char colori[]) {
  int i;

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
}

#endif