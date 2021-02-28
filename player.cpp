#include "player.hpp"
#include "utils.hpp"

Player::Player() {
    std::cout << "enter name:" ; name = getLine();
    hits=0;
    putShip(aircraftcarrier,sBoard) ;
    putShip(battleship,sBoard) ;
    putShip(cruiser,sBoard) ;
    putShip(destroyer,sBoard) ;
    putShip(submarine,sBoard) ;
    sBoard.displayBoard();

};
Player::Player(Player& p) {
    std::cout << "enter name:" ; name = getLine();
    hits=0;
    sBoard = p.sBoard ;
    sBoard.displayBoard();
}

Player::~Player() {} ;
std::string Player::getname() {return name;}
Board& Player::getgBoard(){return gBoard ;}
Board& Player::getsBoard(){return sBoard ;}
void Player::showgBoard(){gBoard.displayBoard();}
void Player::showsBoard(){sBoard.displayBoard();}
void Player::showBoard(Board &b){
    b.displayBoard();
}
int Player::getHits() {return hits; }
void Player::incrementHits() { hits++; }

void Player::putShip(Ship& s, Board& b){
    char fields[s.getsize()] ;

    do{
        int pos0 = 0 ;
        int pos1 = 0 ;
        std::cout << "enter orientation for " << s.getshipname() << std::endl 
                  << " (0:horizontal, 1:vertical) : " ;
        s.setorientation(converterStringToInt()) ;
        
        if( s.getorientation()==false){
            do{
            std::cout << "enter position for " << s.getshipname() << " --> column: " ;
            pos1 = converterStringToInt();
            std::cout << "enter position for " << s.getshipname() << " --> row: " ;
            pos0 = converterStringToInt();
            }while(!checkSize(pos1, s.getsize()));
        }
        
        if( s.getorientation()==true){
            do{
            std::cout << "enter position for " << s.getshipname() << " --> column: " ;
            pos1 = converterStringToInt();
            std::cout << "enter position for " << s.getshipname() << " --> row: " ;
            pos0 = converterStringToInt();
            }while(!checkSize(pos0, s.getsize()));
        }

        s.setposition1(pos1) ;
        s.setposition0(pos0) ;

        if( s.getorientation()==false){
            int j=0 ;
            for(int i=s.getposition1();i<s.getposition1() + s.getsize();i++){
                fields[j] = b.getField(s.getposition0(),i);
                j++ ;
            }
        }

        if( s.getorientation()==true){
            int j=0 ;
            for(int i=s.getposition0();i<s.getposition0() + s.getsize();i++){
                fields[j] = b.getField(i,s.getposition1());
                j++ ;
            }
        }

    }while(
        !checkBoardPos(s.getsize(),fields));

    if( s.getorientation()==false ){
        for(int i=s.getposition1();i<s.getposition1() + s.getsize();i++){
            b.setField(s.getposition0(),i, s.getind()) ;
        }
    }

    if( s.getorientation()==true ){
        for(int i=s.getposition0();i<s.getposition0() + s.getsize();i++){
            b.setField(i,s.getposition1(), s.getind()) ;
        }
    }

    b.addShip(&s);
}