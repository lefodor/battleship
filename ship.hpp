#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
#include <vector>

class Board;

class Ship{
    private:
        std::string shipname ;
        char ind ;
        int size ;
        bool orientation ;
        int position[2];
        bool sunk = false;
        int xhit = 0 ;
    public:
        Ship(int);
        Ship(const Ship&);
        Ship(Ship*);
        virtual ~Ship() ;

        std::string getshipname();
        bool getorientation();
        int getposition0();
        int getposition1();
        int getsize();
        char getind();
        int getrow();
        int getcol();
        int getxhits();
        bool getsunk();

        void setshipname(std::string);
        void setind(char);
        void setorientation(int);
        void setposition0(int);
        void setposition1(int);
        void setxHits(Board& b);
        void setSunk();
        void showShipStatus() ;
};

class AircraftCarrier : public Ship{
    private:

    public:
        AircraftCarrier() : Ship(5) { setshipname("AircraftCarrier") ; setind('A'); };
        ~AircraftCarrier() {} ;
};

class Battleship : public Ship{
    private:

    public:
        Battleship() : Ship(4) { setshipname("Battleship") ; setind('B');};
        ~Battleship() {} ;
};

class Cruiser : public Ship{
    private:

    public:
        Cruiser() : Ship(3) { setshipname("Cruiser") ; setind('C');}
        ~Cruiser() {} ;
};

class Destroyer : public Ship{
    private:

    public:
        Destroyer() : Ship(3) { setshipname("Destroyer") ; setind('D');};
        ~Destroyer() {} ;
};

class Submarine : public Ship{
    private:

    public:
        Submarine() : Ship(2) { setshipname("Submarine") ; setind('S');};
        ~Submarine() {} ;
};

#endif //SHIP_H