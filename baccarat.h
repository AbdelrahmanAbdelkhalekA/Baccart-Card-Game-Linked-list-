

#ifndef BLACKJACK_BACCARAT_H
#define BLACKJACK_BACCARAT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h> 
#include "card.h"
#include "card_deck.h"
#define BACCARAT_MAX_N_CARDS 3

typedef enum {
  dealer_win, 
  player_win, 
  tie
} baccarat_outcome_t;

typedef struct {
  card_deck_t* deck;
  unsigned int num_decks;
  card_t player_cards[BACCARAT_MAX_N_CARDS], dealer_cards[BACCARAT_MAX_N_CARDS];
  unsigned int num_player_cards, num_dealer_cards;
  unsigned int player_score, dealer_score;
} baccarat_game_t;

void start_baccarat(baccarat_game_t*, unsigned int);

void deal_init_baccarat(baccarat_game_t*);

void deal_finalize_baccarat(baccarat_game_t*);

bool deal_player_third_card(baccarat_game_t*);

bool deal_dealer_third_card(baccarat_game_t*);

baccarat_outcome_t get_baccarat_outcome(const baccarat_game_t*);

unsigned int score_baccarat_rank(card_rank_t);

unsigned int score_baccarat_hand(const card_t[], unsigned int);

#endif









