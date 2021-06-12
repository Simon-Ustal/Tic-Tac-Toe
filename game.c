// Šimon Ustal II.B 12.06.2021 ========== Tic-Tac-Toe ==========

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include <stdbool.h>

struct EnemyLoc
{
    int EnemyLocationX;
    int EnemyLocationY;
    int attempts;
};

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
    return;
}

char doMove(char playerChar, int positionX, int positionY, int numOfPoles, char poles[][numOfPoles])
{
    poles[positionX - 1][positionY - 1] = playerChar;

    for (int i = 0; i < numOfPoles; i++)
    {
        for (int j = 0; j < numOfPoles; j++)
        {
            printf("%c ", poles[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}

int RandGenNum(int numOfPoles)
{
    int upperX = numOfPoles - 1;
    int lowerX = 0;
    int numX = (rand() % (upperX - lowerX + 1)) + lowerX;
    return numX;
}

void enemyPlayLoad()
{
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

struct EnemyLoc AIMove(int positionX, int positionY, int numOfPoles, char poles[][numOfPoles], int attempts)
{

    int numberX = RandGenNum(numOfPoles); // Generování random X pozice v poli
    int numberY = RandGenNum(numOfPoles); // Generování random Y pozice v poli

    struct EnemyLoc s1;

    //Generating of X position
    int enemyXPosition = (positionX - numberX) / 2;

    if (enemyXPosition < 1)
    { // Pokud je pozice X menší než je délka pole...
        enemyXPosition = 1;
        enemyXPosition = enemyXPosition + numberX;
    }

    else if (enemyXPosition > numOfPoles - 1)
    { // Pokud je pozice X více než je délka pole...
        enemyXPosition = numOfPoles;
        enemyXPosition = enemyXPosition - numberY;
    }

    //Generating of Y position
    int enemyYPosition = (numberY - numberY) / 2;

    if (enemyYPosition < 1)
    {
        enemyYPosition = 1;
        enemyYPosition = enemyYPosition + numberY;
    }

    else if (enemyYPosition > numOfPoles - 1)
    {
        enemyYPosition = numOfPoles;
        enemyYPosition = enemyYPosition - numberY;
    }

    // ------------------------------------------------------------

    
    if ('x' == poles[enemyXPosition-1][enemyYPosition-1] || 'o' == poles[enemyXPosition-1][enemyYPosition-1])
    {
        s1 = AIMove(positionX, positionY, numOfPoles, poles, attempts);
    }

    else{
        s1.EnemyLocationX = enemyXPosition;
        s1.EnemyLocationY = enemyYPosition;
    }

    return s1;
}

bool authAxisEnemy(int numOfPoles, char poles[][numOfPoles], bool vyhraEnemy, char playerChar, char enemyChar)
{

    // Horizontal
    if (numOfPoles == 3)
    {
        if (poles[0][0] == enemyChar && poles[1][0] == enemyChar && poles[2][0] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][1] == enemyChar && poles[1][1] == enemyChar && poles[2][1] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][2] == enemyChar && poles[1][2] == enemyChar && poles[2][2] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 4)
    {

        if (poles[0][0] == enemyChar && poles[1][0] == enemyChar && poles[2][0] == enemyChar && poles[3][0] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][1] == enemyChar && poles[1][1] == enemyChar && poles[2][1] == enemyChar && poles[3][1] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][2] == enemyChar && poles[1][2] == enemyChar && poles[2][2] == enemyChar && poles[3][2] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][3] == enemyChar && poles[1][3] == enemyChar && poles[2][3] == enemyChar && poles[3][3] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == enemyChar && poles[1][0] == enemyChar && poles[2][0] == enemyChar && poles[3][0] == enemyChar && poles[4][0] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][1] == enemyChar && poles[1][1] == enemyChar && poles[2][1] == enemyChar && poles[3][1] == enemyChar && poles[4][1] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][2] == enemyChar && poles[1][2] == enemyChar && poles[2][2] == enemyChar && poles[3][2] == enemyChar && poles[4][2] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][3] == enemyChar && poles[1][3] == enemyChar && poles[2][3] == enemyChar && poles[3][3] == enemyChar && poles[4][3] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][4] == enemyChar && poles[1][4] == enemyChar && poles[2][4] == enemyChar && poles[3][4] == enemyChar && poles[4][4] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }
    //----------------------------------------------------------------> End Of Horizontal

    // Vertical
    if (numOfPoles == 3)
    {
        if (poles[0][0] == enemyChar && poles[0][1] == enemyChar && poles[0][2] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[1][0] == enemyChar && poles[1][1] == enemyChar && poles[1][2] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[2][0] == enemyChar && poles[2][1] == enemyChar && poles[2][2] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 4)
    {
        if (poles[0][0] == enemyChar && poles[0][1] == enemyChar && poles[0][2] == enemyChar && poles[0][3] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[1][0] == enemyChar && poles[1][1] == enemyChar && poles[1][2] == enemyChar && poles[1][3] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[2][0] == enemyChar && poles[2][1] == enemyChar && poles[2][2] == enemyChar && poles[2][3] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[3][0] == enemyChar && poles[3][1] == enemyChar && poles[3][2] == enemyChar && poles[3][3] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == enemyChar && poles[0][1] == enemyChar && poles[0][2] == enemyChar && poles[0][3] == enemyChar && poles[0][4] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[1][0] == enemyChar && poles[1][1] == enemyChar && poles[1][2] == enemyChar && poles[1][3] == enemyChar && poles[1][4] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[2][0] == enemyChar && poles[2][1] == enemyChar && poles[2][2] == enemyChar && poles[2][3] == enemyChar && poles[2][4] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[3][0] == enemyChar && poles[3][1] == enemyChar && poles[3][2] == enemyChar && poles[3][3] == enemyChar && poles[3][4] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[4][0] == enemyChar && poles[4][1] == enemyChar && poles[4][2] == enemyChar && poles[4][3] == enemyChar && poles[4][4] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    //----------------------------------------------------------------> End Of Vertical

    // Diagonal
    if (numOfPoles == 3)
    {
        if (poles[0][0] == enemyChar && poles[1][1] == enemyChar && poles[2][2] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][2] == enemyChar && poles[1][1] == enemyChar && poles[2][0] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 4)
    {
        if (poles[0][0] == enemyChar && poles[1][1] == enemyChar && poles[2][2] == enemyChar && poles[3][3] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][3] == enemyChar && poles[1][2] == enemyChar && poles[2][1] == enemyChar && poles[3][0] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == enemyChar && poles[1][1] == enemyChar && poles[2][2] == enemyChar && poles[3][3] == enemyChar && poles[4][4] == enemyChar)
        {
            vyhraEnemy = true;
        }

        else if (poles[0][4] == enemyChar && poles[1][3] == enemyChar && poles[2][2] == enemyChar && poles[4][1] == enemyChar && poles[5][0] == enemyChar)
        {
            vyhraEnemy = true;
        }
    }

    //----------------------------------------------------------------> End Of Diagonal

    return vyhraEnemy;
}

bool authAxisPlayer(int numOfPoles, char poles[][numOfPoles], bool vyhra, char playerChar, char enemyChar)
{

    // Horizontal
    if (numOfPoles == 3)
    {
        if (poles[0][0] == playerChar && poles[1][0] == playerChar && poles[2][0] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][1] == playerChar && poles[1][1] == playerChar && poles[2][1] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][2] == playerChar && poles[1][2] == playerChar && poles[2][2] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 4)
    {

        if (poles[0][0] == playerChar && poles[1][0] == playerChar && poles[2][0] == playerChar && poles[3][0] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][1] == playerChar && poles[1][1] == playerChar && poles[2][1] == playerChar && poles[3][1] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][2] == playerChar && poles[1][2] == playerChar && poles[2][2] == playerChar && poles[3][2] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][3] == playerChar && poles[1][3] == playerChar && poles[2][3] == playerChar && poles[3][3] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == playerChar && poles[1][0] == playerChar && poles[2][0] == playerChar && poles[3][0] == playerChar && poles[4][0] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][1] == playerChar && poles[1][1] == playerChar && poles[2][1] == playerChar && poles[3][1] == playerChar && poles[4][1] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][2] == playerChar && poles[1][2] == playerChar && poles[2][2] == playerChar && poles[3][2] == playerChar && poles[4][2] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][3] == playerChar && poles[1][3] == playerChar && poles[2][3] == playerChar && poles[3][3] == playerChar && poles[4][3] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][4] == playerChar && poles[1][4] == playerChar && poles[2][4] == playerChar && poles[3][4] == playerChar && poles[4][4] == playerChar)
        {
            vyhra = true;
        }
    }

    // Vertical
    if (numOfPoles == 3)
    {
        if (poles[0][0] == playerChar && poles[0][1] == playerChar && poles[0][2] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[1][0] == playerChar && poles[1][1] == playerChar && poles[1][2] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[2][0] == playerChar && poles[2][1] == playerChar && poles[2][2] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 4)
    {
        if (poles[0][0] == playerChar && poles[0][1] == playerChar && poles[0][2] == playerChar && poles[0][3] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[1][0] == playerChar && poles[1][1] == playerChar && poles[1][2] == playerChar && poles[1][3] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[2][0] == playerChar && poles[2][1] == playerChar && poles[2][2] == playerChar && poles[2][3] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[3][0] == playerChar && poles[3][1] == playerChar && poles[3][2] == playerChar && poles[3][3] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == playerChar && poles[0][1] == playerChar && poles[0][2] == playerChar && poles[0][3] == playerChar && poles[0][4] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[1][0] == playerChar && poles[1][1] == playerChar && poles[1][2] == playerChar && poles[1][3] == playerChar && poles[1][4] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[2][0] == playerChar && poles[2][1] == playerChar && poles[2][2] == playerChar && poles[2][3] == playerChar && poles[2][4] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[3][0] == playerChar && poles[3][1] == playerChar && poles[3][2] == playerChar && poles[3][3] == playerChar && poles[3][4] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[4][0] == playerChar && poles[4][1] == playerChar && poles[4][2] == playerChar && poles[4][3] == playerChar && poles[4][4] == playerChar)
        {
            vyhra = true;
        }
    }

    // Diagonal
    if (numOfPoles == 3)
    {
        if (poles[0][0] == playerChar && poles[1][1] == playerChar && poles[2][2] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][2] == playerChar && poles[1][1] == playerChar && poles[2][0] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 4)
    {
        if (poles[0][0] == playerChar && poles[1][1] == playerChar && poles[2][2] == playerChar && poles[3][3] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][3] == playerChar && poles[1][2] == playerChar && poles[2][1] == playerChar && poles[3][0] == playerChar)
        {
            vyhra = true;
        }
    }

    if (numOfPoles == 5)
    {
        if (poles[0][0] == playerChar && poles[1][1] == playerChar && poles[2][2] == playerChar && poles[3][3] == playerChar && poles[4][4] == playerChar)
        {
            vyhra = true;
        }

        else if (poles[0][4] == playerChar && poles[1][3] == playerChar && poles[2][2] == playerChar && poles[4][1] == playerChar && poles[5][0] == playerChar)
        {
            vyhra = true;
        }
    }
    return vyhra;
}

bool Pat(int numOfPoles,char poles[][numOfPoles]){
bool pat;

pat = true;

for(int i = 0;i<numOfPoles;i++)
    for(int a = 0;a<numOfPoles;a++){
        if(poles[i][a] == '-'){
            pat = false;
        }
    }
    return pat;
}

void game(void)
{

    int numberOfPoles, positionX, positionY, enemyPositionX = 1, enemyPositionY = 1, attempts = 0;
    char playerChar, enemyChar, indicator;
    bool vyhra, enemyvyhra, pat;

    srand(time(NULL));

    system("cls");

    while (playerChar != 'x' && playerChar != 'o')
    {
        printf("Za jaky znak chcete hrat? (x - o) \n"); // Vyber znaku
        printf("Chci hrat za: ");
        scanf("%c", &playerChar);
        system("cls");
    }

    if (playerChar == 'x')
    {
        enemyChar = 'o';
    }
    else
    {
        enemyChar = 'x';
    }

    while (numberOfPoles < 3 || numberOfPoles > 5)
    {
        printf("Na kolik poli chcete hrat?\n");
        printf("Chci hrat na: ");
        scanf("%d", &numberOfPoles);
        system("cls");
    }

    char generatedPoles[numberOfPoles][numberOfPoles];

    fflush(stdin);

    system("cls");

    for (int i = 0; i < numberOfPoles; i++)
    {
        for (int j = 0; j < numberOfPoles; j++)
        {
            generatedPoles[i][j] = '-';
            printf("%c ", generatedPoles[i][j]);
        }
        printf("\n");
    }
    while (1)
    {
        printf("Na jakou pozici po ose X chcete umistit znak: ");
        scanf("%d", &positionX);

        printf("Na jakou pozici po ose Y chcete umistit znak: ");
        scanf("%d", &positionY);

        system("cls");

        doMove(playerChar, positionX, positionY, numberOfPoles, generatedPoles);

        enemyPlayLoad();

        struct EnemyLoc s1 = AIMove(positionX, positionY, numberOfPoles, generatedPoles, attempts);

        enemyPositionX = s1.EnemyLocationX;
        enemyPositionY = s1.EnemyLocationY;

        printf("Souper zapsal na X: %d\n", enemyPositionX);
        printf("Souper zapsal na Y: %d\n\n", enemyPositionY);

        doMove(enemyChar, enemyPositionX, enemyPositionY, numberOfPoles, generatedPoles);

        enemyvyhra = authAxisEnemy(numberOfPoles, generatedPoles, vyhra, playerChar, enemyChar);

        vyhra = authAxisPlayer(numberOfPoles, generatedPoles, vyhra, playerChar, enemyChar);

        pat = Pat(numberOfPoles, generatedPoles);

        if (true == enemyvyhra)
        {
            break;
        }

        else if (true == vyhra)
        {
            break;
        }

        else if(true == pat){
            break;
        }
    }

    if (vyhra)
    {
        printf("\n");
        printf("Vyhral jsi! Vyhral %c! Jen smele dal!\n\n", playerChar);
        printf("Pro znovuspusteni hry [Num 1]\n");
        printf("Pro ukonceni hry stisknete [Num 2]\n\n");
        printf("Vybrany znak: ");

        scanf("\n%c", &indicator);

        fflush(stdin);

        if (indicator == '1')
        {
            game();
        }

        else if (indicator == '2')
        {
            return;
        }

        fflush(stdin);
    }
    else if (enemyvyhra)
    {
        printf("\n");
        printf("Prohral jsi! Vyhral %c! Zkus to znovu!\n\n", enemyChar);
        printf("Pro odvetu stisknete [Num 1]\n");
        printf("Pro ukonceni hry stisknete [Num 2]\n\n");
        printf("Vybrany znak: ");

        scanf("\n\n%c", &indicator);

        if (indicator == '1')
        {
            game();
        }

        else if (indicator == '2')
        {
            return;
        }
    }
    else if (pat)
    {
        printf("\n");
        printf("Pat! Nikdo nevyhral! Zkus to znovu!\n\n", enemyChar);
        printf("Pro odvetu stisknete [Num 1]\n");
        printf("Pro ukonceni hry stisknete [Num 2]\n\n");
        printf("Vybrany znak: ");

        scanf("\n\n\n%c", &indicator);

        if (indicator == '1')
        {
            game();
        }

        else if (indicator == '2')
        {
            return;
        }
    }
}