#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>

class Ship;

class Board{
    private:
        char board[10][10] ;
        std::vector<Ship*> shipsOnBoard;
    public:
        Board();
        ~Board() ;
        Board(const Board&);
        Board& operator=(const Board&);
        Ship& operator[](int);
        bool chkShipsOnBoard() {return shipsOnBoard.empty();}

        void displayBoard();
        char getField(int, int);
        void setField(int, int, char);
        void addShip(Ship*);
        void displayShipsOnBoard();
        void chkShips();
        int cntShips();
        void getAddresses();
};

#endif //BOARD_H