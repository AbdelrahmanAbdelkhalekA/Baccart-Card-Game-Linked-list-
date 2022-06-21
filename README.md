# ECE 275 Project 0: Baccarat

<center>
	![img](https://www.pspcentral.org/wp-content/uploads/2019/05/Details-for-Baccarat.jpg)
</center>

## Overview: 
This project is to be completed in the C programming language (i.e., **not** C++) and is to ensure everyone is up to speed on the required
prerequisite skills for ECE 275 before we move into the C++ language. 
The project requires that you utilize the provided code for a deck of cards (specifically the functionality to create a deck and draw a card) 
to play the game of Baccarat, a classic casino game. 
As will be the norm in ECE 275, you will submit your code to [GitLab](https://git.engr.arizona.edu) where it will be automatically graded and scored. 

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


## Requirements: 

### Data Type Requirements:
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


### Function Requirements:
You must implement the following functions as specified: 

```c
void start_baccarat(baccarat_game_t*, unsigned int);
```

This function must start a game of Baccarat. This involves creating the deck of cards (hint: you must call `make_card_deck` and assign the 
result to the field `deck` in the first argument. Don't forget to shuffle the deck by calling `shuffle_card_deck`!) and assigning the 
appropriate struct members in the first argument. 

The result of this function should set `baccarat_game_t::deck` to a non-NULL pointer, `baccarat_game_t::num_decks` to the appropriate 
value, `baccarat_game_t::num_player_cards`, `baccarat_game_t::num_dealer_cards`, `baccarat_game_t::player_score`, and `baccarat_game_t::dealer_score` to 0 since no cards have been dealt yet. 


```c
void deal_init_baccarat(baccarat_game_t*);
```

This function must deal the first two cards to first the player and then the dealer, i.e., two cards are dealt to the player then 
two cards are dealt to the dealer. The function should indicate that the number of cards for both the player and the dealer are 2
but should *not* set the score, i.e., leave the player and dealer's score at 0. 

```c
void deal_finalize_baccarat(baccarat_game_t*);
```

This function must run through the logic for both the player and the dealer to deal a third card or not. **Hint**: you will want to 
calculate the score for both the player and the dealer then call 
the functions outlined below which should indicate if a third card should be dealt or not to either the player or the dealer. 
The result of this function should set the appropriate fields in the first argument to indicate the number of cards for both the player and 
the dealer along with their respective score. The player's and dealer's cards should also be placed in `baccarat_game_t::player_cards` 
and `baccarat_game_t::dealer_cards` respectively. 

```c
void end_baccarat(baccarat_game_t*);
```

This function must end the game of Baccarat. **Hint**: you should only need to call `free_card_deck`.

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
and how many cards are in the array in the second argument. **Hint**: You will want to call the above function to calculate
the score for one single card rank in a loop for all the cards in this hand. Remember that scores above 9 roll back to 0!


### Program Requirements:
Place the types and function prototypes outlined above in the file baccarat.h (**Hint** Don't forget your header guards) 
and implement the function in baccarat.c. 
You are free (and encouraged) to add extra functions as you see fit. 


## Utilities:
A logging macro is provided for you in the file logger.h: 

```c
#define log_msg(fmt, ...)						\
  fprintf(stdout, "[%s:%d] " fmt,  __FUNCTION__, __LINE__, ##__VA_ARGS__)
```

This macro, who can be used just as [`printf`](https://en.cppreference.com/w/c/io/fprintf), e.g., `log_msg("i = %d\n", i);` 
or `log_msg("string is '%s'\n", myStr);`, and will display your message along with the function name and line number where the 
log message originates. 

A checking macro is also provided for you: 

```c
#define check(cond, msg, ...)			   \
  do {								       \
    if (!(cond)) log_msg(msg, ##__VA_ARGS__); \
  } while(0)
```

This macro can be used by passing a boolean condition to the first value and a formatted output string (just like to `printf`) which
will be displayed if the condition is false. Example usage: `check(x > 0, "x is %d but it must be gt 0!\n", x);`. 

To enable the macros define `ENABLE_DEBUG_MSG` ***before*** including the header. 
Any output from your program, via these macros or otherwise, will be displayed in the resulting test artifacts. 
If this is not defined the macros will have no effect. 


## Program Testing:
There are 7 tests run each worth 1/7 of the total score. 
Your score is calculated out of 1, i.e., a 100% is a 1.0. 


When (not 'if', 'when') you get an error in the tests start at the top and go down. The tests build off one another 
so if there's an issue in, e.g., the initialization test, the subsequent tests are almost guaranteed to fail because
they all call the routine to initialize a baccarat game. Anything that your program prints will be in the file ctest.log. 
The other log file is there for the instructor in the event there's an error with the tester itself. The file results.ini
holds your score for each tests and the overall score in the `[total]` section. 

The tests are enumerated below: 

### rank\_score\_test
This test calls the function `score_baccarat_rank` and tests that the function returns the correct score for a given rank. 
Note that ranks are randomly generated. 

### hand\_score\_test
This test calls the function `score_baccarat_hand`and tests that the function returns the correct score for a given hand
of baccarat. 
Note that the cards in the hand and the number of cards are randomly generated. 

### initialize\_game\_test
This test generates a `baccarat_game_t` struct and calls `start_baccarat`. The test checks that the deck of cards is created, 
that the number of cards dealt is 0, and that the score for both the player and the dealer is 0. 

### first\_deal\_test
This test generated a `baccarat_game_t` struct and calls `deal_init_baccarat`. The test checks that the deck of cards was shuffled, 
that the cards were dealt in the correct order (player, player, dealer, dealer), that the number of cards for both the player and
the dealer is set to 2 and the score for both the player and the dealer is 0. 


### player\_third\_card\_test
This test generated a `baccarat_game_t` which has been initialized and initially dealt then tests that the call to 
`deal_player_third_card` returns the correct value given the current game state. 


### dealer\_third\_card\_test
This test generated a `baccarat_game_t` which has been initialized and initially dealt then tests that the call to 
`deal_dealer_third_card` returns the correct value given the current game state. 


### game\_outcome\_test
This test generates a `baccarat_game_t` which has been initialized, initially dealt, and finally dealt then tests 
that the call to `get_baccarat_outcome` returns the correct value. 
