// Šimon Ustal II.B 06.06.2021 ========== Tic-Tac-Toe ==========

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"


int main(void) {
  int indicator [1];
  char name[10];
    printf("Zadej sve jmeno (bez mezer): ");
    scanf("%[^\n]s", name);

    system("cls");

    printf("Vitej %s, uzij si svoji hru piskvorek! :)\n", name);

    printf("\n");
    printf("========== Tic-Tac-Toe ==========\n\n");
    printf("Pro spusteni hry stisknete [Num 1]\n");
    printf("Pro ukonceni hry stisknete [Num 2]\n\n");
    printf("Vybrany znak: ");
    scanf("\n%c", &indicator[1]);

  fflush(stdin);

  if(indicator[1] == '1'){
  game();
  }

  else if(indicator[1] == '2') {
  return 0;
  }

}