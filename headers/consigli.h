#include "mastermind.h"
#include "regole.h"

#ifndef CONSIGLI_H
#define CONSIGLI_H

int consigliVettore[DIM_COL];

void assVar(int consigli[]) {
  int i;

  for (i = 0; i < DIM_COL; i++)
    consigliVettore[i] = consigli[i];
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

  for (i = 0; i < DIM_COL; i++)
    consigliVettore[i] = 0;
}

int getConsiglio(int i) {
  return consigliVettore[i];
}

#endif