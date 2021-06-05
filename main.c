// Šimon Ustal II.B 06.06.2021 ========== Tic-Tac-Toe ==========

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

int main(void) {
  char indicator;
    printf("\n");
    printf("========== Tic-Tac-Toe ==========\n\n");
    printf("Pro spusteni hry stisknete [Num 1]\n");
    printf("Pro ukonceni hry stisknete [Num 2]\n\n");
    printf("Vybrany znak: ");
    scanf("%c", &indicator);

  fflush(stdin);

  if(indicator == '1'){
  game();
  }

  else if(indicator == '2') {
  return 0;
  }

}