#include <stdio.h>

#ifndef ESCAPES_H
#define ESCAPES_H

#define CYAN_TEXT "\x1b[0;36m"

#define RED_TEXT "\x1b[38;2;255;0;0m"
#define RED_BG "\x1b[48;2;255;0;0m"

#define PURPLE_TEXT "\x1b[38;2;255;0;255m"
#define PURPLE_BG "\x1b[48;2;255;0;255m"

#define GREEN_TEXT "\x1b[38;2;0;255;0m"
#define GREEN_BG "\x1b[48;2;0;255;0m"

#define LIGHT_BLUE_TEXT "\x1b[38;2;153;203;255m"
#define LIGHT_BLUE_BG "\x1b[48;2;153;203;255m"

#define YELLOW_TEXT "\x1b[38;2;255;255;0m"
#define YELLOW_BG "\x1b[48;2;255;255;0m"

#define WHITE_TEXT "\x1b[38;2;255;255;255m"
#define WHITE_BG "\x1b[48;2;255;255;255m"

#define RESET "\x1b[0m"

void clrscr() {
  system("CLS");
}

void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}

void goDown(int x) {
  printf("%c[%dB", 0x1B, x);
}

void goLeft(int x) {
  printf("%c[%dD", 0x1B, x);
}

void goUp(int x) {
  printf("%c[%dA", 0x1B, x);
}

void goRight(int x) {
  printf("%c[%dC", 0x1B, x);
}

#endif