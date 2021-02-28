#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "ship.hpp"
#include "board.hpp"

class Player{
    private:
        std::string name ;
        int hits ;
        Board gBoard ;
        Board sBoard ;

        AircraftCarrier aircraftcarrier ;
        Battleship battleship ;
        Cruiser cruiser ;
        Destroyer destroyer ;
        Submarine submarine ;

    public:
        Player() ;
        Player(Player&) ;
        ~Player() ;
        // gets
        std::string getname();
        Board& getgBoard();
        Board& getsBoard();
        void showgBoard();
        void showsBoard();
        void showBoard(Board&);
        int getHits();
        void incrementHits();

        void putShip(Ship&, Board&);
};

#endif //PLAYER_H