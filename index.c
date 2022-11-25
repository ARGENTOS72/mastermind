#include <Windows.h>

#include "headers/codebreaker.h"
#include "headers/masterMind.h"
#include "headers/escape.h"
#include "headers/regole.h"
#include "headers/bot.h"

void fullScreen() {
  keybd_event(VK_MENU,0x38,0,0);
  keybd_event(VK_RETURN,0x1c,0,0);
  keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
  keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

int main() {
  fullScreen();

  const int sleep_time = 1000;
  char colori[DIM_COL], indovinoColori[DIM_COL];
  int scelta, i, tentativi = 0;
  bool vincita = false;

  printf("Premi qualsiasi tasto per iniziare a giocare...");
  getch();

  clrscr();

  regole();

  printf("Che modalita' vuole giocare?\n");

  printf("1: Giocatore (MasterMind) - Giocatore (CodeBreaker) LOCALE\n");
  printf("2: Giocatore (MasterMind) - Bot (CodeBreaker) LOCALE\n");
  printf("3: Bot (MasterMind) - Giocatore (CodeBreaker) LOCALE\n");
  printf("4: Bot (MasterMind) - Bot (CodeBreaker) LOCALE\n");

  do {
    printf("--> ");
    scanf("%d", &scelta);

    if (scelta < 1 || scelta > 4)
      printf(RED_BG "Inserisci un valore valido!!\n" RESET);
  } while (scelta < 1 || scelta > 4);

  
  switch (scelta) {
  case 1: // Giocatore (MasterMind) - Giocatore (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Inserisci 4 colori tra questi (si possono ripetere)\n");

    printf("R: colore rosso\n");
    printf("M: colore magenta\n");
    printf("V: colore verde\n");
    printf("A: colore azzurro\n");
    printf("G: colore giallo\n");

    for (i = 0; i < DIM_COL; i++) {
      colori[i] = sceltaColori();
    }

    printf("I tuoi colori inseriti sono i seguenti:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker...");
    getch();

    do {
      clrscr();

      regole();

      if (tentativi) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }

      printf("Inserisci i colori che secondo te ha scelto il MasterMind\n");

      printf("R: colore rosso\n");
      printf("M: colore magenta\n");
      printf("V: colore verde\n");
      printf("A: colore azzurro\n");
      printf("G: colore giallo\n");
      
      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = controlloColori();
      }

      printf("I colori che hai inserito sono:\n");
      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(colori, indovinoColori);

      if (!vincita) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();

        tentativi++;
      }

    } while (!vincita && tentativi < 10);

    if (vincita)
      printf("\n\nIl codebreaker ha vinto!!!");

    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();

    break;
  case 2: // Giocatore (MasterMind) - Bot (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Inserisci 4 colori tra questi (si possono ripetere)\n");

    printf("R: colore rosso\n");
    printf("M: colore magenta\n");
    printf("V: colore verde\n");
    printf("A: colore azzurro\n");
    printf("G: colore giallo\n");

    for (i = 0; i < DIM_COL; i++) {
      colori[i] = sceltaColori();
    }

    printf("I tuoi colori inseriti sono i seguenti:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker(bot)...");
    getch();

    do {
      clrscr();

      regole();

      if (tentativi) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }
      
      printf("Il bot sta inserendo dei colori...\n");

      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = indovinoBotColori(getConsiglio(i), i);
        Sleep(sleep_time);
      }

      printf("\n");

      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(colori, indovinoColori);

      if (!vincita) {
        printf("\n\n\nIl codebreak(bot) deve fare un'altro turno...");
        getch();

        tentativi++;
      }

    } while (!vincita && tentativi < 10);

    if (vincita)
      printf("\n\nIl codebreaker ha vinto!!!");
      
    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();

    break;
  case 3: // Bot(MasterMind) - Giocatore (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Il mastermind(bot) sta scegliendo i colori...");

    for (i = 0; i < DIM_COL; i++) {
      colori[i] = sceltaBotColori();
      Sleep(sleep_time);
    }

    printf("\n\nI colori inseriti dal mastermind(bot) sono:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker(bot)...");
    getch();

    do {
      clrscr();

      regole();

      if (tentativi) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }

      printf("Inserisci i colori che secondo te ha scelto il MasterMind\n");

      printf("R: colore rosso\n");
      printf("M: colore magenta\n");
      printf("V: colore verde\n");
      printf("A: colore azzurro\n");
      printf("G: colore giallo\n");
      
      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = controlloColori();
      }

      printf("I colori che hai inserito sono:\n");
      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(colori, indovinoColori);

      if (!vincita) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();

        tentativi++;
      }

    } while (!vincita && tentativi < 10);

    if (vincita)
      printf("\n\nIl codebreaker ha vinto!!!");
      
    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();
    
    break;
  case 4: // Bot (MasterMind) - Bot (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Il mastermind(bot) sta scegliendo i colori...");

    for (i = 0; i < DIM_COL; i++) {
      colori[i] = sceltaBotColori();
      Sleep(sleep_time);
    }

    printf("\n\nI colori inseriti dal mastermind(bot) sono:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker(bot)...");
    getch();

    do {
      clrscr();

      regole();

      coloriSceltiBotPrint(colori);

      if (tentativi) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }
      
      printf("Il bot sta inserendo dei colori...\n");

      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = indovinoBotColori(getConsiglio(i), i);
        Sleep(sleep_time);
      }

      printf("\n");

      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(colori, indovinoColori);

      if (!vincita) {
        printf("\n\n\nIl codebreak(bot) deve fare un'altro turno...");
        getch();

        tentativi++;
      }

    } while (!vincita && tentativi < 10);

    if (vincita)
      printf("\n\nIl codebreaker ha vinto!!!");
      
    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();
    
    break;
  }

  return 0;
}