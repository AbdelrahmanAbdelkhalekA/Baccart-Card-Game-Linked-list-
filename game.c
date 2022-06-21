#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "baccarat.h"
 
  
int main(void) {
  // Set the random seed for deck shuffling
  srand(time(NULL));
	
  baccarat_game_t g;
  start_baccarat(&g, 3);
  deal_init_baccarat(&g);
  deal_finalize_baccarat(&g);

  baccarat_outcome_t o = get_baccarat_outcome(&g);
  switch(o) {
  case tie:
    printf("Tie!\n"); break;
  case dealer_win:
    printf("Dealer won!\n"); break;
  case player_win:
    printf("Player won!\n"); break;
  }

  //end_baccarat(&g);

	
  return 0;
}
