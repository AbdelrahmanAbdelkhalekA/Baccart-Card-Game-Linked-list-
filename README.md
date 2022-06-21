# Baccart Card Game




## Rules of Baccarat: 
Find an overview of the rules of Baccarat [here](https://baccaratsystem.org/baccarat-drawing-rules/). 
The rules are also briefly outlined below. 

The objective of the game is to be closer to 9 than the dealer. Face cards are scored as 0, Ace's are 1, and all others are scored according 
to their value. If a score goes above 9 it is rolled back to 0. 
Both the dealer and the player are dealt two cards on the initial deal. 
If either the dealer or the player has a *natural* (a score of 8 or 9 on the first two cards) then no third card is dealt and the outcome is 
decided from only the initial deal. 
If there is not a natural then the player will be dealt a third card only if their score is not above 6. 
After the player is optionally dealt a third card then the dealer will decide to deal a third card or not. 
If the player was not dealt a third card the dealer only draws a third card if their score is strictly less than 6. 
If the player was dealt a third card then the dealer takes a third card corresponding to the score on their first two cards and the value
of the player's third card. Find the specific rules [here](https://baccaratsystem.org/wp-content/uploads/2014/08/drawing-rules-baccarat.jpg). 
Finally, the game has three possible outcomes: a tie, the player wins, or the dealer wins.

## Data Type description:
You must utilize the predefined `enum` and `struct` types to describe a baccarat game's outcome and the game itself, respectively: 

```c
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
```

The game is fully described by the `baccarat_game_t` struct-type. 

The member `deck` is a pointer to a `card_deck_t`-type variable. 
The member `num_decks` describes how many decks are currently in use for this game. 
The members `player_cards` and `dealer_cards` are fixed-size arrays (of length 3) which will hold the player's and dealer's cards, respectively. 
The members `num_player_cards` and `num_dealer_cards` describe how many cards the dealer and player have currently. 
The members `player_score` and `dealer_score` describe the player's and the dealer's score during the game. 


## Code's functions description and functionality:

```c
void start_baccarat(baccarat_game_t*, unsigned int);
```

This function start a game of Baccarat. This involves creating the deck of cards (`make_card_deck` start a deck of cards and then assign the 
result to the field `deck` in the first argument. Then shuffling the deck by calling `shuffle_card_deck`!) and assigning the 
appropriate struct members in the first argument. The result of this function set `baccarat_game_t::deck` to a non-NULL pointer, `baccarat_game_t::num_decks` to the appropriate value, `baccarat_game_t::num_player_cards`, `baccarat_game_t::num_dealer_cards`, `baccarat_game_t::player_score`, and `baccarat_game_t::dealer_score` to 0 since no cards have been dealt yet. 


```c
void deal_init_baccarat(baccarat_game_t*);
```

This function deal the first two cards to first the player and then the dealer, i.e., two cards are dealt to the player then 
two cards are dealt to the dealer. The function should indicate that the number of cards for both the player and the dealer are 2
but should *not* set the score, i.e., leave the player and dealer's score at 0. 

```c
void deal_finalize_baccarat(baccarat_game_t*);
```

This function run through the logic for both the player and the dealer to deal a third card or not. calculating the score for both the player and the dealer then call 
the functions outlined below which should indicate if a third card should be dealt or not to either the player or the dealer. 
The result of this function should set the appropriate fields in the first argument to indicate the number of cards for both the player and 
the dealer along with their respective score. The player's and dealer's cards should also be placed in `baccarat_game_t::player_cards` 
and `baccarat_game_t::dealer_cards` respectively. 

```c
void end_baccarat(baccarat_game_t*);
```

This function must end the game of Baccarat. 

```c
bool deal_player_third_card(baccarat_game_t*);

bool deal_dealer_third_card(baccarat_game_t*);
```

These functions should return `true` if a third card is to be dealt or `false` if a third card is not to be dealt according to the 
dealing rules of Baccarat. 

```c
baccarat_outcome_t get_baccarat_outcome(const baccarat_game_t*);
```

This function must return the outcome of the Baccarat game, i.e., who is closer to 9. 

```c
unsigned int score_baccarat_rank(card_rank_t);
```

This function must return the appropriate score for a card's rank according to the scoring rules of Baccarat. 


```c
unsigned int score_baccarat_hand(const card_t[], unsigned int);
```

This function must return the score for an entire hand given a constant array of `card_t`-type variables in the first argument
and how many cards are in the array in the second argument. 
