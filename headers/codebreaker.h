#include <stdbool.h>
#include <conio.h>

#include "mastermind.h"
#include "consigli.h"

#ifndef CODEBREAKER_H
#define CODEBREAKER_H

char controlloColori() {
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

bool controlloUguaglianzaColori(char mind[], char breaker[]) {
  int i, counter = 0, j, consigliV[DIM_COL];
  bool vincita = false;

  printf("\n\n");

  for (i = 0; i < DIM_COL; i++) {
    for (j = 0; j < DIM_COL; j++) {
      if (breaker[i] == mind[i]) {
        counter++;

        consigliV[i] = 1;

        break;
      } else if (breaker[i] == mind[j]) {
        if (i != j) {
          consigliV[i] = 2;

          break;
        }
      } else {
        consigliV[i] = 0;
      }
    }
  }

  for (i = 0; i < DIM_COL; i++) {
    switch (consigliV[i]) {
    case 0:
      goRight(3);

      break;
    case 1:
      printf(WHITE_BG "  " RESET);

      goRight(1);

      break;
    case 2:
      printf(WHITE_BG "  " RESET);

      goDown(2);
      goLeft(2);

      printf(WHITE_BG "  " RESET);

      goUp(2);
      goRight(1);

      break;
    }
  }

  assVar(consigliV);

  if (counter == 4){
    vincita = true;
    return vincita;
  } else {
    counter = 0;
    return vincita;
  }
}

#endif