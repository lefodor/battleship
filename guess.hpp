#ifndef GUESS_H
#define GUESS_H

class Guess{
    private:
        int row ;
        int col ;
    public:
        Guess();
        Guess(int, int);
        Guess& operator=(const Guess&);
        ~Guess();

        int getRow();
        int getCol();

        void setRow(int);
        void setCol(int);
};

#endif