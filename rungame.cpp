#include <string>
#include <sstream>
#include "rungame.hpp"
#include "utils.hpp"

int menu(){
    std::string uinp_s ;
        do{
            std::cout <<"****************************************************\n"
                <<"******************** Battleship ********************\n"
                <<"program written by: Levente Fodor ******************\n"
                << std::endl ;
            std::cout <<"1. Start game" << std::endl ;
            std::cout <<"2. Quit game" << std::endl ;

            std::stringstream uinp ;
            uinp << getLine() ;

            uinp >> uinp_s;

            if(uinp_s=="2") { 
                std::cout << "Thanks for playing. Goodbye.\n" ; 
                exit(3) ; }
            else if(uinp_s=="1") { 
                std::cout << "Start game\n" ;}
            else { 
                std::cout << "Please choose 1 or 2 then hit Enter.\n" ; } ;
        }while(!(uinp_s=="1" || uinp_s=="2"));
        return EXIT_SUCCESS;
};

int runGameMenu(Player* p){
    int outp=0;
    std::string uinp_s ;
        do{
            std::cout << p->getname() << " 's turn" << std::endl ;
            std::cout <<"1. Shoot\n";
            std::cout <<"2. Show Guess board\n";
            std::cout <<"3. Show Ship board\n";
            std::cout <<"4. Go to Ship menu\n";
            std::cout <<"5. Quit Game\n";

            std::stringstream uinp ;
            uinp << getLine() ;

            uinp >> uinp_s;

            if(uinp_s=="5") { 
                std::cout << "Thanks for playing. Goodbye.\n" ; 
                return 1;}
            else if( uinp_s=="2" ){
                p->showgBoard();
            }
            else if( uinp_s=="3" ){
                p->showsBoard();
            }
            else if( uinp_s=="4" ){
                shipMenu(p);
            }
        }while(!(uinp_s=="1"));
        return 0;
};

void shipMenu(Player* p){
    std::string uinp_s ;
    int uinp_i ;
    int shipsOnBoard;
        do{
            std::cout << p->getname() << " 's ships" << std::endl ;
            std::cout << "0. Exit menu" << std::endl ;
            (p->getsBoard()).displayShipsOnBoard();
            std::cout << "Which ship would you like to look at?" ;

            do{ 
                std::stringstream uinp ;
                uinp << getLine() ;

                uinp >> uinp_i;
                shipsOnBoard = (p->getsBoard()).cntShips() ;
                if(uinp_i>shipsOnBoard){
                    std::cout << "No such ship. Try again..." ;
                }
            }while(uinp_i>shipsOnBoard);

            if(uinp_i!=0){
                Ship shipToLook = (p->getsBoard())[uinp_i];
                shipToLook.showShipStatus();
            }
        }while(!(uinp_i==0));
};

Guess inputTarget(Player* p_attack,Player* p_defense){
    int r,c;
    std::cout << p_attack->getname() << " enter target --> row: " ;
    r = converterStringToInt();
    std::cout << p_attack->getname() << " enter target --> column: " ;
    c = converterStringToInt();
    Guess g(r,c);
    return g;
}

void adminGuess(Guess& g, Player* p_attack, Player* p_defense){
    char shot = p_defense->getsBoard().getField(g.getRow(),g.getCol());

    if( shot!='.' ){
        std::cout << "hit" << std::endl ;
        p_defense->getsBoard().setField(g.getRow(),g.getCol(),'X') ;
        p_attack->getgBoard().setField(g.getRow(),g.getCol(),'X') ;
        p_attack->incrementHits();
    }
    else{
        std::cout << "no hit" << std::endl ;
        p_defense->getsBoard().setField(g.getRow(),g.getCol(),'O') ;
        p_attack->getgBoard().setField(g.getRow(),g.getCol(),'O') ;
    }
}

int rungame(Player& p1, Player& p2, int maxhits){
    int round=0 ;
    bool endgame=false;
    Player* p_attack;
    Player* p_defense;

    do{
        // set round
        round++;
        std::cout << "round: " << round << std::endl ;

        if( round%2 != 0 ){
            p_attack = &p1 ;
            p_defense = &p2 ;
        }
        else{
            p_attack = &p2 ;
            p_defense = &p1 ;
        }

        // rungame menu
        if( runGameMenu(p_attack)== 1) {
            return 1 ;
        } ;

        // enter target
        Guess g;
        char c_check;
        do{
            g=inputTarget(p_attack, p_defense);
            c_check = p_defense->getsBoard().getField(g.getRow(),g.getCol());
            if( c_check=='X' || c_check=='O' ){
                std::cout << "you have already shot to that spot, try again...\n" ;
            }
        }while( c_check=='X' || c_check=='O' ) ;

        // administer Guess on guessBoard / shipBoard
        adminGuess(g,p_attack, p_defense) ;
        
        // check if any ship sunk
        (p_defense->getsBoard()).chkShips();

        // check if all ships hit --> endgame
        std::cout <<"hits: " << p_attack->getHits() << std::endl ;
        endgame = ( p_attack->getHits() == maxhits ) ;


    }while(!endgame) ;

    //
    std::cout << "game finished" << std::endl ;
    return 0 ;
}