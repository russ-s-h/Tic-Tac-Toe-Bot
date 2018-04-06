#include <stdio.h>
#include "tictactoe.h"

int main(int argc , char **argv) {
   int input;
   char b3[10];
   unsigned short i;
   struct strategy_struct r;
   FILE *stratfile;
   /* command line arguement */
   if (argc != 2) {
    fprintf(stderr, "Usage: %s [n]\n",argv[0]);
    exit(-1);
   }
   input = atoi(argv[1]);
   stratfile = fopen("strategyfile.bin","rb+");
   /* loop through each possible board and write proper record values */
   for (i = 0; i < 19683; ++i) {
      b3fromus(b3,i);
      if ((get_move(b3) - '0') == input) {
         /* check if there is a winner on the board */
         if (winner(i) != ' ') {
            r.best_move = -1;
            r.winner = winner(i);
            set_record(stratfile,i,r);
         }
         /* if not then evaluate and write the best move and winner */
         else {
            evaluate_move(stratfile,i,&r);
            set_record(stratfile,i,r);
         }
      }
   }
   fclose(stratfile);
   return 0;
}

