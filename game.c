#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

struct EnemyLoc
{
    int EnemyLocationX;
    int EnemyLocationY; 
};

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
    return;
}

char doMove(char playerChar, int positionX, int positionY, int numOfPoles, char poles[][numOfPoles]){
    
poles[positionX - 1 ][positionY - 1] = playerChar;

        for (int i = 0; i < numOfPoles; i++){
         for(int j = 0; j < numOfPoles; j++){
            printf("%c ", poles[i][j]);
        }
    printf("\n");
        }
return 1;
}

int RandGenNum(int numOfPoles){
int upperX = numOfPoles - 1;
int lowerX = 0;   
int numX = (rand() % (upperX - lowerX + 1)) + lowerX;
return numX;
}

void enemyPlayLoad(){
system("cls");
printf("Nyni hraje souper.\n");
sleep(750);
system("cls");
printf("Nyni hraje souper..\n");
sleep(750);
system("cls");
printf("Nyni hraje souper...\n");
sleep(750);
system("cls");
return;
}

struct EnemyLoc AIMove(int positionX, int positionY, int numOfPoles, char poles[][numOfPoles], int attempts){
    
    int numberX = RandGenNum(numOfPoles);   // Generování random X pozice v poli
    int numberY = RandGenNum(numOfPoles);   // Generování random Y pozice v poli

    struct EnemyLoc s1;

//Generating of X position
    int enemyXPosition = (positionX - numberX) / 2;

    if(enemyXPosition < 1){ // Pokud je pozice X menší než je délka pole...
    enemyXPosition = 1;
    enemyXPosition = enemyXPosition + numberX;
    } 
    
    else if (enemyXPosition > numOfPoles - 1){ // Pokud je pozice X více než je délka pole...
    enemyXPosition = numOfPoles;
    enemyXPosition = enemyXPosition - numberY;
    }

//Generating of Y position
    int enemyYPosition = (numberY - numberY) / 2;

if(enemyYPosition < 1){
    enemyYPosition = 1;
    enemyYPosition = enemyYPosition + numberY;
    } 
    
else if (enemyYPosition > numOfPoles - 1){
    enemyYPosition = numOfPoles;
    enemyYPosition = enemyYPosition - numberY;
    }

// ------------------------------------------------------------

for (int i = 0; i < numOfPoles; i++){      // Ověření znaku
    for (int f = 0; i < numOfPoles; i++){ 

    if (poles[enemyXPosition][enemyYPosition] == 'x' || poles[enemyXPosition][enemyYPosition] == 'o'){ 
                enemyXPosition = enemyXPosition +1;
                enemyYPosition = enemyYPosition +1;
                printf("Tady funguju kokote\n");
                }
   
    }
} 

    s1.EnemyLocationX = enemyXPosition;
    s1.EnemyLocationY = enemyYPosition;

    printf("osa X: %d\n", enemyXPosition);
    printf("osa Y: %d\n", enemyYPosition);

    return s1;
}

void game(void){

    int numberOfPoles, positionX, positionY, enemyPositionX = 1, enemyPositionY = 1, attempts;
    char playerChar, enemyChar;

    system("cls");

    while(playerChar != 'x' && playerChar != 'o'){
        printf("Za jaky znak chcete hrat? (x - o) \n"); // Vyber znaku
        printf("Chci hrat za: ");
        scanf("%c", &playerChar);
        system("cls");
        }

    if(playerChar == 'x'){
    enemyChar = 'o'; 
    } else{
    enemyChar = 'x';    
    }


    while(numberOfPoles < 3 || numberOfPoles > 5 ){
        printf("Na kolik poli chcete hrat?\n");
        printf("Chci hrat na: ");
        scanf("%d", &numberOfPoles);
        system("cls");
    }
        
    char generatedPoles [numberOfPoles][numberOfPoles];

fflush(stdin);

        system("cls");

        for (int i = 0; i < numberOfPoles; i++){
        for(int j = 0; j < numberOfPoles; j++){
        generatedPoles [i][j] = '-';
        printf("%c ", generatedPoles[i][j]);
    }
    printf("\n");
}
    while(1){
        printf("Na jakou pozici po ose X chcete umistit znak: ");
        scanf("%d", &positionX);

        printf("Na jakou pozici po ose Y chcete umistit znak: ");
        scanf("%d", &positionY);

        system("cls");


        doMove(playerChar, positionX, positionY, numberOfPoles, generatedPoles);

        enemyPlayLoad();

        struct EnemyLoc s1 =  AIMove(positionX, positionY, numberOfPoles, generatedPoles, attempts);

        enemyPositionX = s1.EnemyLocationX;
        enemyPositionY = s1.EnemyLocationY;

        doMove(enemyChar, enemyPositionX , enemyPositionY, numberOfPoles, generatedPoles);
    }

return;
}