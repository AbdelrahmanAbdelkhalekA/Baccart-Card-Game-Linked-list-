#ifndef BLACKJACK_CARD_DECK_H
#define BLACKJACK_CARD_DECK_H

#include "card.h"

#define CARD_DECK_SIZE 52

#define card_deck_t card_t*

// We want to create a function to allocate for N card decks
// because in Blackjack there are multiple decks used
card_deck_t* make_card_deck(unsigned int);
// Function to deallocate the arrays
void free_card_deck(card_deck_t*, unsigned int);
// Function to shuffle the card deck
void shuffle_card_deck(card_deck_t*, unsigned int);
// Function to draw a card from the deck
card_t draw_card(card_deck_t*, unsigned int);

#endif //BLACKJACK_CARD_DECK_H
