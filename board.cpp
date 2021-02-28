#include <iostream>
#include <string>
#include "board.hpp"
#include "ship.hpp"


Board::Board(){
    for(int i = 0; i<10 ; i++){
        for(int j = 0 ; j<10; j++){
            board[i][j] = '.' ;
        }
    }
};

Board::~Board() {} ;

Board::Board(const Board& b){
    for(int i = 0; i<10 ; i++){
        for(int j = 0 ; j<10; j++){
            board[i][j] = b.board[i][j];
        }
    }
    for( auto s : b.shipsOnBoard ){
        this->addShip(s);
    }
}

Board& Board::operator=(const Board& b){
    for(int i = 0; i<10 ; i++){
        for(int j = 0 ; j<10; j++){
            (this->board)[i][j] = b.board[i][j];
        }
    }
    for( auto s : b.shipsOnBoard ){
        Ship* s_cpy = new Ship(s);
        this->addShip(s_cpy);
    }
    return *this ;
}

Ship& Board::operator[](int n){
    return (*shipsOnBoard[n-1]) ;
}

void Board::displayBoard(){
    for(int i = 0; i<10 ; i++){
        std::cout << "+-+-+-+-+-+-+-+-+-+-+" << std::endl << "|" ;
        for(int j = 0 ; j<10; j++){
            std::cout << board[i][j] << "|" ;
        }
        std::cout << std::endl ;
    }
    std::cout << "+-+-+-+-+-+-+-+-+-+-+" << std::endl ;
};

char Board::getField(int r, int c){
    return board[r][c];
};

void Board::setField(int r, int c, char ch){
    board[r][c]=ch;
};
void Board::addShip(Ship* s){
    shipsOnBoard.emplace_back(s);
};
void Board::displayShipsOnBoard(){
    int cnt=0;
    for(auto s : shipsOnBoard){
        cnt++ ;
        std::cout << cnt << ". " << s->getshipname() << std::endl;
    }
};
void Board::chkShips(){
    for(auto s : shipsOnBoard){
        s->setxHits(*this) ;
        s->setSunk() ;
    }
};
int Board::cntShips(){
    int cnt=0;
    for(auto s : shipsOnBoard){
        cnt++ ;
    }
    return cnt ;
}
void Board::getAddresses(){
    for(auto s : shipsOnBoard){
        std::cout << s << std::endl ;
    }
}