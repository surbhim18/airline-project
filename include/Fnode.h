#include "PassengerList.h"

#ifndef FNODE_H
#define FNODE_H

class Fnode
{
    private:
        char* fname;
        char* fcode;                       // ADMIN:- fcode is unique
        char* source;
        char* destination;
        int capacity;
    public:
        Fnode();
        Fnode* next;
        char* getFcode() const;
        char* getSource() const;
        char* getDestination() const;
        PassengerList* passengers;
        bool isFull() const;
        int availableSeats() const;               //returns the no of seats left
        void enterInfo();
        void displayName() const;                //display fname,code,source,destination
        void displayF() const;                   //display passengers also
        ~Fnode();
};

#endif // FNODE_H
