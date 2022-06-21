//
// Created by Connor Fuhrman on 1/25/22.
//

#include "card.h"

#include <stdio.h>

// "stringification"
#define enum_str(e) #e
#define enum_case(e) case e : return enum_str(e)

// Define the function to return the string
// of a given card rank
const char* card_rank_str(const card_rank_t r) {
    switch (r) {
        enum_case(Ace);
        enum_case(Two);
        enum_case(Three);
        enum_case(Four);
        enum_case(Five);
        enum_case(Six);
        enum_case(Seven);
        enum_case(Eight);
        enum_case(Nine);
        enum_case(Ten);
        enum_case(Jack);
        enum_case(Queen);
        enum_case(King);
			default: return "";
    }
}

const char* card_suit_str(const card_suit_t s) {
    switch(s) {
        enum_case(Clubs);
        enum_case(Diamonds);
        enum_case(Hearts);
        enum_case(Spades);
			default: return "";
    }
}

// Define the function to print the card overall
void print_card(const card_t c) {
    printf("%s of %s\n", 
            card_rank_str(c.rank), card_suit_str(c.suit));
}
