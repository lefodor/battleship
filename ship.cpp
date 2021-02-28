#include <iostream>
#include <string>
#include "board.hpp"
#include "ship.hpp"

Ship::Ship(int s) : size{s} {} ;
Ship::Ship(Ship* s) {
    shipname=s->getshipname();
    ind=s->getind();
    size=s->getsize();
    orientation=s->getorientation() ;
    position[0]=s->getposition0();
    position[1]=s->getposition1();
    sunk = s->getsunk();
    xhit = s->getxhits() ;
} ;
Ship::Ship(const Ship& s){
    shipname=s.shipname ;
    ind=s.ind;
    size=s.size;
    orientation=s.orientation;
    position[0]=s.position[0];
    position[1]=s.position[1];
    sunk = s.sunk ;
    xhit = s.xhit;
};
Ship::~Ship() {} ;
std::string Ship::getshipname(){return shipname;}
bool Ship::getorientation(){return orientation;}
int Ship::getposition0(){return position[0];}
int Ship::getposition1(){return position[1];}
int Ship::getsize(){return size;}
char Ship::getind(){return ind;}
int Ship::getrow(){return position[0];}
int Ship::getcol(){return position[1];}
bool Ship::getsunk() {return sunk;}

void Ship::setshipname(std::string n){shipname = n ;}
void Ship::setind(char i){ind = i ;}
void Ship::setorientation(int o){orientation = o ;}
void Ship::setposition0(int p){position[0]=p;}
void Ship::setposition1(int p){position[1]=p;}
void Ship::setxHits(Board& b){
    int cntHits=0;
    char spot;
    if(orientation==0){
        for(int i=0;i<size;i++){
            spot=b.getField(position[0],position[1]+i);
            if(spot=='X'){
                cntHits++;
            }
        }
    }
    else{
        for(int i=0;i<size;i++){
            spot=b.getField(position[0]+i,position[1]);
            if(spot=='X'){
                cntHits++;
            }
        }
    }
    xhit=cntHits;
}

void Ship::setSunk(){
    if( xhit>=size && sunk==false ){ 
        sunk=true; 
        std::cout << shipname << " is destroyed" << std::endl ;}
};

int Ship::getxhits(){
    return xhit ;
}

void Ship::showShipStatus(){
    std::cout << "hits: " << getxhits() << '/' << getsize() << " sunk: " << getsunk() << std::endl ;
}