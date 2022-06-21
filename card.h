#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

typedef enum {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    num_members_card_rank_t
} card_rank_t;

// Define enumeration type for the suit of the card
typedef enum {
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    num_members_card_suit_t
} card_suit_t;

typedef struct {
    card_rank_t rank;
    card_suit_t suit;
} card_t;

// Declare a function to return the rank of a given card as a
// string
const char* card_rank_str(card_rank_t);
// Declare a function to return the suit of a given card as a
// string
const char* card_suit_str(card_suit_t);
// Declare a function to print the card overall
void print_card(card_t);

#endif //BLACKJACK_CARD_H
