#ifndef PASSENGERLIST_H
#define PASSENGERLIST_H
#include "Pnode.h"

class PassengerList
{
    private:
        Pnode* head;
        Pnode* tail;
        int noOfPass;            // to keep record of no. of passengers
        int counter;             // to generate ticket number

    public:
        PassengerList();
        ~PassengerList();
        int getNoOfPass() const;
        bool noPassengers() const;
        void displayL() const;
        int reserveTicket();
        bool confirmTicket(int);
        bool cancelTicket(int);
};

#endif // PASSENGERLIST_H
