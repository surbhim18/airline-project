#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Flights.h"
#include "MyException.h"

using namespace std;

Flights:: Flights()
{
    head = tail = 0;
}

Flights:: ~Flights()
{
    Fnode* temp;

    while(head)
    {
       temp = head;
       head = head-> next;
       delete temp;
    }
}

bool Flights:: noFlights() const
{
    if(head==0)
        return true;

    return false;
}

void Flights:: createNewFlight()
{
    if(tail == 0)
    {
        tail = new Fnode();
        tail->next = 0;
        head = tail;
    }
    else
    {
        tail->next  = new Fnode();
        tail = tail->next;
        tail->next = 0;
    }
    tail->enterInfo();
}

Fnode* Flights:: findFlight(char* _source, char* _dest) const
{
    if(noFlights())
        throw MyException("There are no flights.");

    if(strcasecmp(tail->getSource(),_source)==0 && strcasecmp(tail->getDestination(),_dest)==0)
        return tail;

    Fnode* temp = head;
    while(temp->next)
    {
        if(strcasecmp(temp->getSource(),_source)==0 && strcasecmp(temp->getDestination(),_dest)==0)
            return temp;

        temp = temp->next;
    }

     throw MyException("Sorry. No flights for this route are available.");
}

bool Flights:: reserveTkt(char* _source, char* _dest,int noOfTkts)
{
    try
    {
        Fnode* temp = findFlight(_source,_dest);

        cout<<"\nDetails for the flight:\nFrom: "<<_source<<" To: "<<_dest;
        temp->displayName();

        if(temp->isFull())
            throw MyException("Sorry. This flight is full.");
        else if(temp->availableSeats()<noOfTkts)
        {
            cout<<"\nOnly "<<temp->availableSeats()<<" available.";
            throw MyException("Try again for lesser no. of tickets.");
        }
        else
        {
            int ticketNo;
            for(int i=0;i<noOfTkts;i++)
            {
                ticketNo = temp->passengers->reserveTicket();
                cout<<"\nYour ticket no. is: "<<temp->getFcode()<<ticketNo<<endl;
            }
        }
        return true;
    }
     catch(MyException ex)
    {
                throw;
    }
}

void Flights:: displayAllFlights() const
{
    Fnode* temp = head;

    if(temp == 0)
       throw MyException("There are no flights.");
    else
    {
        cout<<"\nFLIGHTS:";
        while(temp!=0)
        {
            temp->displayName();
            temp = temp->next;
        }
    }

}

Fnode* Flights:: findByFcode(char* _fcode) const
{
    if(noFlights())
        throw MyException("There are no flights.");

    if(strcasecmp(tail->getFcode(),_fcode)==0)
        return tail;

    Fnode* temp = head;
    while(temp->next)
    {
        if(strcasecmp(temp->getFcode(),_fcode)==0)
            return temp;

        temp = temp->next;
    }

     throw MyException("INVALID flight. Please try again.");

}

void Flights:: displayPassOfFlight(char* _fcode) const
{
  try
  {
    Fnode* temp = findByFcode(_fcode);
    temp->displayF();
  }
  catch(MyException ex)
  {
      throw;
  }
}

bool Flights:: ticketConfirmation(char* tktcode) const
{
    char _fcode[5], _tktNo[5];
    strncpy(_fcode,tktcode,4);
    _fcode[4] = '\0';

    for(int i=4,k=0; tktcode[i]!='\0';i++)
            _tktNo[k++] = tktcode[i];

    _tktNo[4] = '\0';

    int tktNo = atoi(_tktNo);
    try
    {
        Fnode* temp = findByFcode(_fcode);

        if(!temp->passengers->confirmTicket(tktNo))
           throw MyException(" You entered invalid ticket no");
    }
    catch(MyException ex)
    {
        throw;
    }
    return true;
}

bool Flights:: cancelTicket(char* tktcode)
{
    char _fcode[5], _tktNo[5];
    strncpy(_fcode,tktcode,4);
    _fcode[4] = '\0';

    for(int i=4,k=0; tktcode[i]!='\0';i++)
            _tktNo[k++] = tktcode[i];

    _tktNo[4] = '\0';

    int tktNo = atoi(_tktNo);

    try
    {
        Fnode* temp = findByFcode(_fcode);
        if(!temp->passengers->cancelTicket(tktNo))
            return false;
    }
    catch(MyException ex)
    {
        throw;
    }

    return true;
}
