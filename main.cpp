#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "utils.hpp"
#include "board.hpp"
#include "ship.hpp"
#include "guess.hpp"
#include "player.hpp"
#include "rungame.hpp"

using namespace std ;

int main(){

    while(true){
        // menu
        menu() ;
        // create players
        Player p1 ;
        //Player p2(p1) ;
        Player p2 ;
        // run game, 17=5+4+3+3+2 (sizes of all ships)
        if( rungame(p1, p2, 17)==1 ){
            return 0 ;
        } ;
    };

    return 0 ;
}
