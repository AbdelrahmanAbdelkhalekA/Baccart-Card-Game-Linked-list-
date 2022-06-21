set( sources 
  card.c 
  card_deck.c
  baccarat.c )


add_library( baccarat SHARED ${sources} )
set_property(TARGET baccarat PROPERTY C_STANDARD 11)

target_include_directories( baccarat PUBLIC ${CMAKE_SOURCE_DIR}/utils )

if (NOT TESTING_ONLY)
  add_executable( baccarat_ex game.c )
  target_link_libraries( baccarat_ex PUBLIC baccarat )
  target_include_directories( baccarat_ex PUBLIC ${CMAKE_SOURCE_DIR}/utils )
endif()

