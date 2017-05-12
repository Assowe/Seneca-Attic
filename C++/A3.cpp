#define _CRT_SECURE_NO_WARNINGS
#define AR_SIZE 391
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
     void playBattleship(void);
     void updateData(char*, char*, int*, int*, int*, char*, char*);
     void drawGame(char*, int, int, int, char*);
     void initGame(char*, char*);
     void loadShips(char*, char*);
     int checkMove(char*);
     int main(){
         srand((unsigned int)time(NULL));
         playBattleship();
         getchar(); getchar();
         return 0;
     }
     void playBattleship(void){
         int mFired = 0, mRem = 100, score = 0;
         char mask[AR_SIZE], board[AR_SIZE], pMove[31] = { "N/A" }, coord[2] = "";
         initGame(board, mask);
         drawGame(mask, mFired, mRem, score, pMove);
         updateData(board, mask, &mFired, &mRem, &score, pMove, coord);
        
     }
     void initGame(char board[], char mask[]){
         int i = 0, j = 0;
         for (i = 0; i<390; i++) {
             board[i] = '~';
             mask[i] = '~';
         }
         mask[i] = '\0'; /* add the null byte to use as a string if required */
         board[i] = '\0';

         loadShips(board, "[F>");
         loadShips(board, "[SS=>");
         loadShips(board, "[DDD=>");
         loadShips(board, "[CCCCC=>");
     }
     void loadShips(char board[], char ship[]){
         int i, Row = 0, Colm = 0, index = 0, len = 0, boundarie = 0;
         len = strlen(ship);

         Row = (rand() % 14) + 1;
         Colm = (rand() % 25) + 1;
         
         boundarie = Colm + len;
         index = Row * 26 + Colm;

         for (i = 0; i < len && boundarie < 26; i++){//Placeses the ship on the board at a random location 
             board[index + i] = ship[i];
         }
     }
     void drawGame(char mask[], int missilesFired, int missilesRemaining, int score, char previousMove[]){
         int i, j, a= 0;
         printf("   C Battleship...\n");
         printf("   ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
         for (i = 0; i<15; i++) {                /* display 15 rows of information (incl. border) */
             if (i < 9) {
                 printf(" %c|", i + 1 + '0');   /* for each digit character */
             }
             else {
                 printf(" %c|", i + 1 + 55);    /* for each alphabetic character 'A' through 'F' */
             }
             for (j = 0; j<26; j++) {             /* display all 26 columns in each row */
                 printf("%c", mask[j + (i * 26)]);
             }
             printf("|\n");
         }
         
         printf("\nMissiles Fired: %.2d  Missiles Remaining: %.3d", missilesFired, missilesRemaining);
         printf("\nCurrent  Score: %.3d Previous Move:      %s\n", score, previousMove);
         
     }
     void updateData(char board[], char mask[], int *missilesFired, int *missilesRemaining, int *score, char previousMove[], char currentMove[]){
         int i = 0;
         while (*missilesRemaining != 0 && *score != 110){
             i = checkMove(currentMove);
             if (board[i] == '~'){
                 mask[i] = 'X';//Miss
                 previousMove = currentMove;
             }
             else{//'score' is only ever updated (increasing by 5) if a "HIT" is registered
                 mask[i] = board[i];
                 *score += 5;
             }
             *missilesRemaining -= 1;
             *missilesFired += 1;
             drawGame(mask, *missilesFired, *missilesRemaining, *score, previousMove);

         }
         if (*missilesRemaining == 0){
             printf("\nSorry...  You lost the WAR!");
         }
         else if (*score == 110){
             printf("\nHooray... You SUNK ALL the Battleships! You won the WAR!");
         }
         drawGame(board, *missilesFired, *missilesRemaining, *score, previousMove);

     }
     int checkMove(char coord[]){
         int index = -1, row = 0, colm = 0, i = 0, len = 0;
         
         while (index == -1){
             printf("\nEnter Target Coordinates--> ");
             scanf("%s", coord);

             len = strlen(coord);
             if (len == 2){// Verifies if 'coord' meets all requirements and returns the index if pass else returns -1 
                 if ((coord[0] >= 'A' && coord[0] <= 'F') ||
                     (coord[0] >= '1' && coord[0] <= '9') &&
                     (coord[1] >= 'A' && coord[1] <= 'Z')){
                     if (coord[0] >= '1' && coord[0] <= '9'){
                         row = coord[0] - 49;
                     }
                     else if (coord[0] >= 'A' && coord[0] <= 'F'){
                         row = coord[0] - 56;
                     }

                     colm = coord[1] - 65;
                     index = row * 26 + colm;
                 }
             }
             else{  
                 printf("Sorry... '%s' is not a valid coordinate... Try again!", coord);  
             }
         }
         return index;
     }