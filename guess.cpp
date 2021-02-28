#include "guess.hpp"

Guess::Guess(){
    row=0;col=0;
};
Guess::Guess(int r, int c){
    row=r;col=c;
};
Guess& Guess::operator=(const Guess& g){
    this->row = g.row ;
    this->col = g.col ;
    return *this ;
};
Guess::~Guess(){};
int Guess::getRow(){return row ;}
int Guess::getCol(){return col ;}
void Guess::setRow(int r){ row=r; }
void Guess::setCol(int c){ col=c; }