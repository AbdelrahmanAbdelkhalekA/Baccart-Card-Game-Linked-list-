#include "baccarat.h"
#define RAND(M,N) (M + rand() / (RAND_MAX / (N - M +1) +1 ))
 
void start_baccarat(baccarat_game_t* g, unsigned int x){
  g->num_decks = x; 
  //int numshuffle = RAND(4,12); 
  g->deck = make_card_deck(g->num_decks);
  shuffle_card_deck(g->deck, g->num_decks);
  g->num_player_cards = 0;
  g->num_dealer_cards = 0;
  g->player_score = 0;
  g->dealer_score = 0;
}

void deal_init_baccarat(baccarat_game_t* k){
    for (int i = 0; i < 2;i++){
k->player_cards[i] = draw_card(k->deck, k->num_decks);
  }
  for (int i = 0; i < 2;i++){
k->dealer_cards[i] = draw_card(k->deck, k->num_decks);
  }
  k->num_player_cards = 2;
  k->num_dealer_cards = 2;
}

void deal_finalize_baccarat(baccarat_game_t* g){ 
  bool y = false;
    if (deal_player_third_card(g)){
      //if (g->player_score < 6){
        g->player_cards[g->num_player_cards] = draw_card(g->deck, g->num_decks); 
        g->num_player_cards += 1;
      //}
      y = true;
    } 
    if (y){
       if (deal_dealer_third_card(g)){ 
      g->dealer_cards[g->num_dealer_cards] = draw_card(g->deck, g->num_decks);
      g->num_dealer_cards += 1;
      }
    }
  //player 6 or 7 they dont get a third  card but the dealer does if his score is less tha 6 (only if less than 6) (9 or 8 is nothing)  
       g->player_score = score_baccarat_hand(g->player_cards, g->num_player_cards);
       //g->dealer_score = score_baccarat_hand(g->dealer_cards, g->num_decks);
      g->dealer_score = score_baccarat_hand(g->dealer_cards, g->num_dealer_cards);
    //get_baccarat_outcome(g);
}


bool deal_player_third_card(baccarat_game_t* g){
  g->player_score = score_baccarat_hand(g->player_cards, g->num_player_cards);
  g->dealer_score = score_baccarat_hand(g->dealer_cards, g->num_dealer_cards);
  if ((g->player_score == 8) || (g->player_score == 9)){
     return false;
 }
 else if ((g->dealer_score == 8) || (g->dealer_score == 9)){
     return false;
 }
 else if ((g->player_score == 7) || (g->player_score == 6)){
   return false;
 }
  else if (g->player_score < 6) {
     return true;
 }
 return false;
}

bool deal_dealer_third_card(baccarat_game_t* g){
  g->dealer_score = score_baccarat_hand(g->dealer_cards, g->num_dealer_cards);
  unsigned int x = score_baccarat_rank(g->player_cards[2].rank);
 g->player_score = score_baccarat_hand(g->player_cards, g->num_player_cards);
  
if ((g->player_score == 8) || (g->player_score == 9)){
     return false;
 }
/*  
  if (g->num_player_cards == 3){
      if (g->dealer_score < 6){
        return true;
      }
  }
  else { */

 if (g->dealer_score == 3){
    if ((x <= 9) && (x != 8)){
      return true;
    }
  }
  else if (g->dealer_score == 4){
    if ((x >= 2) && (x <= 7)){
      return true;
    }
  }
  else if (g->dealer_score == 5){
    if ((x >= 4) && (x <= 7)){
      return true;
    }
  }
  else if (g->dealer_score == 6){
    if ((x >= 6) && (x <= 7)){
      return true;
    }
  }
  //}
  //if it is 9 or 8 it will just return false
  return false;
}

baccarat_outcome_t get_baccarat_outcome(const baccarat_game_t* b){
     if (b->player_score < b->dealer_score) return dealer_win;
     if (b->player_score > b->dealer_score) return player_win;
     if (b->player_score == b->dealer_score) return tie;
     return 0;
}

unsigned int score_baccarat_rank(card_rank_t h){
   unsigned int value = 0;
     switch (h){
        case Ace: value = 1; break;
        case Two: value = 2; break;
        case Three: value = 3; break;
        case Four: value = 4; break;
        case Five: value = 5; break;
        case Six: value = 6; break;
        case Seven: value = 7; break;
        case Eight: value = 8; break;
        case Nine: value = 9; break;
        case Ten:
        case Jack:
        case Queen:
        case King: value = 0; break;
         case num_members_card_rank_t:
             break;
     }
    return value;
}

unsigned int score_baccarat_hand(const card_t x[], unsigned int b){
 unsigned int result = 0;
    for (unsigned int i = 0; i < b; i++){
        result += score_baccarat_rank((x[i].rank));
    }

    if (result > 9){
      result = result - 10;
    }
    if (result > 9){
      result = result - 10;
    }
    return result;
}
