# Baccart-Card-Game-Linked-list-

For the game rules used in this project please visit https://baccaratsystem.org/baccarat-drawing-rules/  and https://baccaratsystem.org/wp-content/uploads/2014/08/drawing-rules-baccarat.jpg

The code functionality and description:

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

