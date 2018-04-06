#include <stdio.h>
#include "tictactoe.h"

int main() {
   unsigned short us;
   char b3[10];
   char board[60];
   char name[60];
   char playerTurn,cpuTurn;
   int input,i;
   struct strategy_struct r;
   FILE *stratfile;
   stratfile = fopen("strategyfile.bin","rb");
   us = 0;
   printf("SHALL WE PLAY A GAME?\n\n");
   /* take user inputs */
   printf("PLEASE ENTER YOUR NAME: ");
   fgets(name,60,stdin);
   printf("\n");
   printf("GREETINGS %s",name);
   printf("Which side would you like to play (X/O)? ");
   scanf("%c",&playerTurn);
   /* assign WOPR's turn to the opposite of the player's */
   cpuTurn = (playerTurn == 'X') ? 'O' : 'X';
   printf("Ok, you will be %c; I will be %c.\n\n",playerTurn,cpuTurn);
   b3fromus(b3,us);
   boardfromb3(board,b3);
   printf("\n");
   /* print out */
   i = 0;
   /* loop until there is a winner or tie */
   while (winner(us) == ' ') {
      if ((cpuTurn == 'X') && (i == 0)) {
         get_record(stratfile,us,&r);
         printf("My turn; my move is %d:\n",r.best_move);
         us = next(us,r.best_move + '0');
         b3fromus(b3,us);
         printf("\n");
         boardfromb3(board,b3);
         printf("\n");
      }
      else if ((playerTurn == 'X') && (i == 0)) {
         printf("Your turn; chose a move [0-8]: ");
         scanf("%d",&input);
         us = next(us,input + '0');
         b3fromus(b3,us);
         printf("\n");
         boardfromb3(board,b3);
         printf("\n");
      }
      else if ((cpuTurn == 'O') && (i == 1)) {
         get_record(stratfile,us,&r);
         printf("My turn; my move is %d:\n",r.best_move);
         us = next(us,r.best_move + '0');
         b3fromus(b3,us);
         printf("\n");
         boardfromb3(board,b3);
         printf("\n");
      }
      else {
         printf("Your turn; chose a move [0-8]: ");
         scanf("%d",&input);
         us = next(us,input + '0');
         b3fromus(b3,us);
         printf("\n");
         boardfromb3(board,b3);
         printf("\n");
      }
      /* change the turn variable */
      if (i == 0) {
         i = 1;
      }
      else {
         i = 0;
      }
   }
   /* check if there is a winner or tie and print appropriate response */
   if (winner(us) != '0') {
      printf("\nI won!\n\n");
   }
   else {
      printf("\nThe game is a tie.\n\n");
   }
   printf("A STRANGE GAME.\nTHE ONLY WINNING MOVE IS\nNOT TO PLAY.\n");
   fclose(stratfile);
   return 0;
}
