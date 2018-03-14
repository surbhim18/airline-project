#include <cstring>
#include<iostream>
#include "PassengerList.h"
#include "MyException.h"

using namespace std;

PassengerList::PassengerList()
{
  head = tail = 0;
  noOfPass = 0;
  counter  = 2000;
}

PassengerList::~PassengerList()
{
 Pnode* temp;

    while(head)
    {
       temp = head;
       head = head-> next;
       delete temp;
    }
}


bool PassengerList:: noPassengers() const
{
    if(head == 0)
        return true;

    return false;
}


int PassengerList:: getNoOfPass() const
{
    return noOfPass;
}

int PassengerList::reserveTicket()
{
    Pnode passObj(counter);
    cout<<"\n\nEnter the details of the passenger:";
    passObj.enterN();


    if(noPassengers())
    {
        head = new Pnode(passObj);
        tail = head;
        noOfPass++;
        counter++;
        return head->getTktNo();
    }
    else if(strcasecmp(passObj.getPname(),head->getPname())<0)
    {
        Pnode* temp = new Pnode(passObj);
        temp->next = head;
        head = temp;
        noOfPass++;
        counter++;
        return head->getTktNo();
    }
    else if(strcasecmp(passObj.getPname(),tail->getPname())>=0)
    {
        tail->next  = new Pnode(passObj);
        tail = tail->next;
        tail->next=0;
        noOfPass++;
        counter++;
        return tail->getTktNo();
    }
    else
    {
        Pnode* temp = head;

        while(strcasecmp(passObj.getPname(),temp->next->getPname())>=0)
            temp = temp->next;

        Pnode* temp1 = new Pnode(passObj);
        temp1->next = temp->next;
        temp->next = temp1;
        noOfPass++;
        counter++;
        return temp1->getTktNo();
    }
}

void PassengerList:: displayL() const
{
    Pnode* temp = head;

    if(temp == 0)
       throw MyException("This flight has no passengers.");
    else
    {
        cout<<"\nThe list of passengers:";
        while(temp!=0)
        {
            temp->displayN();
            temp = temp->next;
        }
    }

}

bool PassengerList:: confirmTicket(int ticketNo)
{
    if(noPassengers())
        throw MyException("This flight has no passengers.");

    if(tail->getTktNo() == ticketNo)
    {
        tail->displayN();
        return true;
    }

    Pnode* temp = head;
    while(temp->next)
    {
        if(temp->getTktNo() == ticketNo)
            {
                temp->displayN();
                return true;
            }

        temp = temp->next;
    }

    return false;

}

bool confirmDeletion(Pnode* temp)
{
    char ch;
    cout<<"\nDetails for the entered ticket:";
    temp->displayN();

    cout<<"\nAre you sure you want to delete this ticket?(y/n) :";
    cin>>ch;

    if(ch=='y'||ch=='Y')
        return true;

    return false;

}

bool PassengerList::cancelTicket(int ticketNo)
{
    if(noPassengers())
    {
        throw MyException("This flight has no passengers.");
    }
    else if(head->getTktNo()==ticketNo)
    {
        if(head->next==0)
        {
            if(confirmDeletion(head))
            {
                delete head;
                head=0;
                tail=0;

                noOfPass--;
                return true;
            }
        }
        else
        {
            if(confirmDeletion(head))
            {
                Pnode *temp=head;
                head=head->next;
                delete temp;

                noOfPass--;
                return true;
            }
        }

    }
    else
    {
        Pnode *temp;

        for( temp=head; (temp!=tail)&&(temp->next->getTktNo()!=ticketNo) ;temp=temp->next);
        if(temp==tail)
        {
            throw MyException("There is no reservation for this ticket no.");
        }

        if(confirmDeletion(temp->next))
        {
            Pnode *deleteMe = temp->next;
            temp->next=deleteMe->next;
            delete deleteMe;

            noOfPass--;
            return true;
        }
    }
    return false;
}
