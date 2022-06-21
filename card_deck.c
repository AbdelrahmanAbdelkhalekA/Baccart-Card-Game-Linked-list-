//
// Created by Connor Fuhrman on 1/25/22.
//

#include <stdlib.h>
#include <assert.h>

#include "card_deck.h"

static void make_card_deck_suit(card_deck_t d, card_suit_t s) {
  for (int i = 0; i != num_members_card_rank_t; ++i) {
    card_t c = {.rank = i, .suit = s};
    d[i] = c;
  }
}

card_deck_t* make_card_deck(const unsigned int num_decks) {
  // Allocate an array of pointers where each element points to a card_t
  // pointer which is an array of cards that makes a "deck"
  card_deck_t* d = (card_deck_t*)malloc(num_decks*sizeof(card_deck_t));
  for (unsigned int i = 0; i != num_decks; ++i) {
    // Allocate an array of size 52 to hold 52 card_t struct types
    card_deck_t _d = (card_t*)malloc(CARD_DECK_SIZE*sizeof(card_t));
    // Loop over each card and assign the appropriate rank and suit
    for (int j = 0; j != num_members_card_suit_t; ++j) {
      make_card_deck_suit(_d + j*num_members_card_rank_t, j);
    }
    d[i] = _d;
  }

  return d;
}

// Give me a random integer between 0 and 'm'
static inline int rrand(int m)
{
  return (int)((double)m * ( rand() / (RAND_MAX+1.0) ));
}

// Function to get a card from mulitple decks
static card_t* get_card_from_decks(card_deck_t* decks, const unsigned int idx) {
  unsigned int decks_idx = 0;
  unsigned int deck_idx = idx;

  while(deck_idx >= CARD_DECK_SIZE) {
    ++decks_idx;
    deck_idx -= CARD_DECK_SIZE;
  }

  return &decks[decks_idx][deck_idx];
}

// Function to shuffle the cards in all the decks
void shuffle_card_deck(card_deck_t* d, const unsigned int num_decks) {
  card_t tmp;
  size_t i = num_decks*CARD_DECK_SIZE-1;
  while(i > 1) { // Swap element i with element j
    size_t j = rrand(i--);
    // Move element i to tmp 
    tmp = *get_card_from_decks(d, i);
    // Move element j to i
    *get_card_from_decks(d, i) = *get_card_from_decks(d, j);
    // Move tmp to element j
    *get_card_from_decks(d, j) = tmp;
  }
}

// Function to draw a card from our N number of decks
card_t draw_card(card_deck_t* d, const unsigned int num_decks) {
  static unsigned int idx = 0;

  card_t* c = get_card_from_decks(d, idx);
  if (++idx == num_decks*CARD_DECK_SIZE-1) {
    // Then we've exhausted all the possible cards. We need to shuffle again and start
    // at idx 0
    shuffle_card_deck(d, num_decks);
    idx = 0;
  }
  
  return *c;
}

void free_card_deck(card_deck_t* d, const unsigned int num_decks) {
  for (unsigned int i = 0; i != num_decks; ++i) {
    free(d[i]);
  }
  free(d);
}
