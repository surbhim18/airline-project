#include "Fnode.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Fnode:: Fnode()
{

   fname = new char[30];
   fcode = new char[4];
   source = new char[30];
   destination = new char[30];
   passengers = new PassengerList();
   capacity = 0;

   next = 0;
}

Fnode:: ~Fnode()
{
    delete []fname;
    delete []fcode;
    delete []source;
    delete []destination;
    delete passengers;
}

char* Fnode:: getFcode() const
{
    return fcode;
}

char* Fnode:: getSource() const
{
    return source;
}
char* Fnode:: getDestination() const
{
    return destination;
}

bool Fnode:: isFull() const
{
    if(capacity==passengers->getNoOfPass())
        return true;

    return false;
}

int Fnode:: availableSeats() const
{
    return (capacity - passengers->getNoOfPass());
}

void Fnode:: enterInfo()
{
    cout<<"\n\nEnter the name of flight: ";
    cin.getline(fname,30);
    cout<<"Enter the flight code   : ";
    cin>>fcode;
    cin.ignore(50,'\n');
    cout<<"Enter source            : ";
    cin.getline(source,30);
    cout<<"Enter destination       : ";
    cin.getline(destination,30);
    cout<<"Enter capacity of flight: ";
    cin>>capacity;
    cout<<endl;
}

void Fnode:: displayName() const
{
    cout<<"\n\nName of flight    : ";
    cout<<fname;
    cout<<"\nFlight code       : ";
    cout<<fcode;
    cout<<"\nSource            : ";
    cout<<source;
    cout<<"\nDestination       : ";
    cout<<destination;
    cout<<"\nCapacity of flight: ";
    cout<<capacity;
    cout<<"\nAvailable seats   : "<<availableSeats();
    cout<<endl;
}

void Fnode:: displayF() const
{
    displayName();
    try
    {
        passengers->displayL();
    }
    catch(MyException)
    {
        throw;
    }
}
