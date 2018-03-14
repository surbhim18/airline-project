// ASSUMPTION: Only one flight from one source to a destination

#include "Fnode.h"

#ifndef FLIGHTS_H
#define FLIGHTS_H


class Flights
{
    private:
        Fnode* head;
        Fnode* tail;
        Fnode* findByFcode(char* _fcode) const;
        Fnode* findFlight(char* _source, char* _dest) const;
        bool noFlights() const;
    public:
        Flights();
        void createNewFlight();                                   //ADMIN//
        bool reserveTkt(char* _source, char* _dest, int);         //USER //
        void displayAllFlights() const;                           //ADMIN//flight names,code,source,destination
        void displayPassOfFlight(char* _fcode) const;             //ADMIN//for a particular flight
        bool ticketConfirmation(char* tktcode) const;             //USER //
        bool cancelTicket(char* tktcode);                         //USER //
        ~Flights();
};

#endif // FLIGHTS_H
