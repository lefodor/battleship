//rungame.hpp
#include <iostream>
#include "utils.hpp"
#include "board.hpp"
#include "ship.hpp"
#include "guess.hpp"
#include "player.hpp"

int menu() ;
int runGameMenu(Player*);
void shipMenu(Player*);
Guess inputTarget(Player*,Player*);
void adminGuess(Guess&, Player*, Player*);
int rungame(Player&,Player&,int);