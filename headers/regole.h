#include "escape.h"
                                                                                                                                 
#ifndef REGOLE_H
#define REGOLE_H

#define X_POS 140

void regole() {
  int i, y, x, temp;

  gotoxy(X_POS, 1);
  printf("%c", 201);
  for (i = 0; i < 65; i++) {
    printf("%c", 205);
  }
  printf("%c", 187);
  for (i = 0; i < 9; i++) {
    y = 2 + i;
    gotoxy(X_POS + 66, y);
    printf("%c", 186);
  }
  gotoxy(X_POS + 66, y + 1);
  printf("%c", 188);
  for (i = 1; i <= 65; i++) {
    x = X_POS + 66 - i;
    gotoxy(x, y + 1);
    printf("%c", 205);
  }
  gotoxy(x - 1, y + 1);
  printf("%c", 200);
  temp = y;
  for (i = 0; i < 9; i++) {
    y = temp - i;
    gotoxy(x - 1, y);
    printf("%c", 186);
  }

  printf(CYAN_TEXT);
  gotoxy(X_POS + 1, 2);
  printf("Ci sono 5 colori* il mastermind ne deve");
  gotoxy(X_POS + 1, 3);
  printf("scelgliere 4 e il codebreaker li deve indovinare");
  gotoxy(X_POS + 1, 4);
  printf("in 10 tentativi, con aiuti del mastermind.");
  gotoxy(X_POS + 1, 5),
  printf("Essi sono i seguenti:");
  gotoxy(X_POS + 1, 6);
  printf("Se il colore e' giusto nella giusta posizione");
  gotoxy(X_POS + 1, 7);
  printf("si posiziona uno spillo bianco sotto al colore.");
  gotoxy(X_POS + 1, 8);
  printf("Se il colore e' giusto nella posizione sbagliata");
  gotoxy(X_POS + 1, 9);
  printf("si posizionano due spilli bianchi sotto il colore.");
  gotoxy(X_POS + 1, 10);
  printf("Se il colore e' sbagliato non si posiziona nulla.");
  printf(RESET);
  gotoxy(X_POS + 51, 2);
  printf("*I colori sono:");
  gotoxy(X_POS + 51, 3);
  printf(RED_TEXT "Rosso" RESET " - " RED_BG "  " RESET);
  gotoxy(X_POS + 51, 4);
  printf(PURPLE_TEXT "Magenta" RESET " - " PURPLE_BG "  " RESET);
  gotoxy(X_POS + 51, 5);
  printf(GREEN_TEXT "Verde" RESET " - " GREEN_BG "  " RESET);
  gotoxy(X_POS + 51, 6);
  printf(LIGHT_BLUE_TEXT "Azzurro" RESET " - " LIGHT_BLUE_BG "  " RESET);
  gotoxy(X_POS + 51, 7);
  printf(YELLOW_TEXT "Giallo" RESET " - " YELLOW_BG "  " RESET);

  gotoxy(1, 1);
}

#endif