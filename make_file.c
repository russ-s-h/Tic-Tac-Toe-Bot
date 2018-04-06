#include <stdio.h>
#include "tictactoe.h"

int main() {
   struct strategy_struct x;
   int i;
   FILE *stratFile;
   /* assign placeholder values to record*/
   x.best_move = -1;
   x.winner = ' ';
   stratFile = fopen("strategyfile.bin","wb");
   /* write placeholders into each possible move location */
   for (i = 0; i < 19683; ++i) {
      fwrite(&x, sizeof(x),1,stratFile);
   }
   fclose(stratFile);
   return 0;
}
