#include <Windows.h>
#include <SFML/Audio.hpp>

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
  sf::SoundBuffer buffer1;
  if (!buffer1.loadFromFile("resources/Intro.wav"))
    return -1;

  sf::Sound sound1(buffer1);
  sound1.play();

  fullScreen();

  const int sleep_time = 1000;
  char colori[DIM_COL], indovinoColori[DIM_COL], copiaColori[DIM_COL];
  int scelta, i, tentativi = 0;
  bool vincita = false;

  clrscr();

  printf("Premi qualsiasi tasto per iniziare a giocare...");
  getch();

  clrscr();

  regole();

  printf("Che modalita' vuole giocare?\n");

  printf("1: Giocatore (MasterMind) - Giocatore (CodeBreaker) LOCALE\n");
  printf("2: Giocatore (MasterMind) - Bot (CodeBreaker) LOCALE\n");
  printf("3: Bot (MasterMind) - Giocatore (CodeBreaker) LOCALE\n");
  printf("4: Bot (MasterMind) - Bot (CodeBreaker) LOCALE\n");

  sound1.stop();

  do {
    printf("--> ");
    scanf("%d", &scelta);

    if (scelta < 1 || scelta > 4)
      printf(RED_BG "Inserisci un valore valido!!\n" RESET);
  } while (scelta < 1 || scelta > 4);

  sf::Music music;
  if (!music.openFromFile("resources/Start.ogg"))
    return -1;

  music.play();
  music.setLoop(true);

  switch (scelta) {
  case 1: // Giocatore (MasterMind) - Giocatore (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Inserisci 4 colori tra questi (inserirli uno alla volta)\n");

    printf("R: colore rosso\n");
    printf("M: colore magenta\n");
    printf("V: colore verde\n");
    printf("A: colore azzurro\n");
    printf("G: colore giallo\n");

    for (i = 0; i < DIM_COL; i++)
      colori[i] = sceltaColori();

    for (i = 0; i < DIM_COL; i++)
      copiaColori[i] = colori[i];

    printf("I tuoi colori inseriti sono i seguenti:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker...");
    getch();

    do {
      tentativi++;

      for (i = 0; i < DIM_COL; i++)
        copiaColori[i] = colori[i];

      clrscr();

      regole();

      if (tentativi > 1) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }

      printf("Turno numero #%d", tentativi);
      printf("\nInserisci i colori che secondo te ha scelto il MasterMind (inserirli uno alla volta)\n");

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
      
      vincita = controlloUguaglianzaColori(copiaColori, indovinoColori);

      if (!vincita && tentativi != 10) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();
      }

    } while (!vincita && tentativi <= 10);

    music.stop();

    if (vincita) {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Win.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha vinto!!!");

      sound2.play();

      Sleep(4000);
    } else {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Lost.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha perso...");

      sound2.play();

      Sleep(4000);
    }

    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();

    break;
  case 2: // Giocatore (MasterMind) - Bot (CodeBreaker) LOCALE
    clrscr();

    regole();

    printf("Inserisci 4 colori tra questi (inserirli uno alla volta)\n");

    printf("R: colore rosso\n");
    printf("M: colore magenta\n");
    printf("V: colore verde\n");
    printf("A: colore azzurro\n");
    printf("G: colore giallo\n");

    for (i = 0; i < DIM_COL; i++)
      colori[i] = sceltaColori();

    for (i = 0; i < DIM_COL; i++)
      copiaColori[i] = colori[i];

    printf("I tuoi colori inseriti sono i seguenti:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker(bot)...");
    getch();

    do {
      tentativi++;

      for (i = 0; i < DIM_COL; i++)
        copiaColori[i] = colori[i];

      clrscr();

      regole();

      if (tentativi > 1) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }

      printf("Turno numero #%d", tentativi);
      printf("\nIl bot sta inserendo dei colori...\n");

      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = indovinoBotColori(getConsiglio(i, tentativi - 1), i, tentativi - 1);
        Sleep(sleep_time);
      }

      printf("\n");

      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(copiaColori, indovinoColori);

      if (!vincita && tentativi != 10) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();
      }

    } while (!vincita && tentativi <= 10);

    music.stop();

    if (vincita) {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Win.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha vinto!!!");

      sound2.play();

      Sleep(4000);
    } else {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Lost.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha perso...");

      sound2.play();

      Sleep(4000);
    }
      
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

    for (i = 0; i < DIM_COL; i++)
      copiaColori[i] = colori[i];

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker...");
    getch();

    do {
      tentativi++;

      for (i = 0; i < DIM_COL; i++)
        copiaColori[i] = colori[i];

      clrscr();

      regole();

      if (tentativi > 1) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }

      printf("Turno numero #%d", tentativi);
      printf("\nInserisci i colori che secondo te ha scelto il MasterMind(bot) (inserirli uno alla volta)\n");

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
      
      vincita = controlloUguaglianzaColori(copiaColori, indovinoColori);

      if (!vincita && tentativi != 10) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();
      }

    } while (!vincita && tentativi <= 10);

    music.stop();

    if (vincita) {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Win.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha vinto!!!");

      sound2.play();

      Sleep(4000);
    } else {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Lost.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha perso...");

      sound2.play();

      Sleep(4000);
    }
      
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

    for (i = 0; i < DIM_COL; i++)
      copiaColori[i] = colori[i];

    printf("\n\nI colori inseriti dal mastermind(bot) sono:\n");
    printfColori(colori);

    printf("\n\nPremi qualsiasi tasto per continuare e dare il turno al codebreaker(bot)...");
    getch();

    do {
      tentativi++;

      for (i = 0; i < DIM_COL; i++)
        copiaColori[i] = colori[i];

      clrscr();

      regole();

      coloriSceltiBotPrint(colori);

      if (tentativi > 1) {
        printfColoriConsigli(indovinoColori);
        printfConsigli();
      }
      
      printf("Turno numero #%d", tentativi);
      printf("\nIl bot sta inserendo dei colori...\n");

      for (i = 0; i < DIM_COL; i++) {
        indovinoColori[i] = indovinoBotColori(getConsiglio(i, tentativi - 1), i, tentativi - 1);
        Sleep(sleep_time);
      }

      printf("\n");

      printfColori(indovinoColori);
      
      vincita = controlloUguaglianzaColori(copiaColori, indovinoColori);

      if (!vincita && tentativi != 10) {
        printf("\n\n\nIl codebreak deve fare un'altro turno...");
        getch();
      }

    } while (!vincita && tentativi <= 10);
    
    music.stop();  
  
    if (vincita) {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Win.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha vinto!!!");

      sound2.play();

      Sleep(4000);
    } else {
      sf::SoundBuffer buffer2;
      if (!buffer2.loadFromFile("resources/Lost.wav"))
        return -1;

      sf::Sound sound2(buffer2);

      printf("\n\nIl codebreaker ha perso...");

      sound2.play();

      Sleep(4000);
    }
      
    printf("\n\nPremi qualsiasi tasto per continuare...");
    getch();
    
    break;
  }

  return 0;
}