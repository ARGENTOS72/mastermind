#include <stdbool.h>
#include <conio.h>

#include "mastermind.h"
#include "regole.h"

#ifndef CODEBREAKER_H
#define CODEBREAKER_H

int consigliVettore[DIM_COL];

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
  int i, counter = 0, j, consigliV[DIM_COL], copiaConsigliV[DIM_COL];
  char copiaMind[DIM_COL], copiaBreaker[DIM_COL];
  bool vincita = false;

  printf("\n\n");

  j = 0;

  for (i = DIM_COL; i > 0; i--) {
    copiaMind[j] = mind[i - 1];
    j++;
  }

  j = 0;

  for (i = DIM_COL; i > 0; i--) {
    copiaBreaker[j] = breaker[i - 1];
    j++;
  }

  for (i = 0; i < DIM_COL; i++) {
    for (j = 0; j < DIM_COL; j++) {
      if (breaker[i] == mind[i]) {
        counter++;

        consigliV[i] = 1;

        mind[i] = 'N';

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

  counter = 0;

  for (i = 0; i < DIM_COL; i++) {
    for (j = 0; j < DIM_COL; j++) {
      if (copiaBreaker[i] == copiaMind[i]) {
        counter++;

        copiaConsigliV[i] = 1;

        copiaMind[i] = 'N';

        break;
      } else if (copiaBreaker[i] == copiaMind[j]) {
        if (i != j) {
          copiaConsigliV[i] = 2;

          break;
        }
      } else {
        copiaConsigliV[i] = 0;
      }
    }
  }

  j = 0;

  for (i = DIM_COL; i > 0; i--) {
    if (consigliV[j] > copiaConsigliV[i - 1])
      consigliV[j] = copiaConsigliV[i - 1];

    j++;
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

  for (i = 0; i < DIM_COL; i++)
    consigliVettore[i] = consigliV[i];

  if (counter == 4){
    vincita = true;
    return vincita;
  } else {
    counter = 0;
    return vincita;
  }
}

void printfColoriConsigli(char colori[]) {
  int i;
  gotoxy(X_POS + 35, 12);

  printf("Aiuti del mastermind:");

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

void printfConsigli() {
  gotoxy(X_POS + 56, 14);
  int i;
  
  for (i = 0; i < DIM_COL; i++) {
    switch (consigliVettore[i]) {
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

  gotoxy(1, 1);
}

int getConsiglio(int i, int tentativi) {
  if (tentativi) {
    return consigliVettore[i];
  } else {
    return 0;
  }
}

#endif