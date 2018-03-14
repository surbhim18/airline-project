#include "iostream"
using namespace std;

#include "stdlib.h"
#include "time.h"

#include "cstring"
#include "conio.h"

#include "Flights.h"
#include "PassengerList.h"
#include "MyException.h"

/// header of all the required functions
void delay(unsigned int);
bool askPassword();
void userPanel();
void adminPanel();

/// a object of class flight
Flights newPassenger;

int main()
{

do
{
    delay(200);
    cout<<"\n";
    cout<<"\n                  ##############################################";
    cout<<"\n                  ##                                          ##";
    cout<<"\n                  ##      AIRLINE  TICKET  RESERVATION        ##";
    cout<<"\n                  ##                                          ##";
    cout<<"\n                  ##############################################";
    cout<<"\n\n\n\n\n";
    delay(800);

    cout<<"\n\t                ##################################";
    cout<<"\n\t                ##                              ##";
    cout<<"\n\t                ##      1. USER  PANEL          ##";
    cout<<"\n\t                ##                              ##";
    cout<<"\n\t                ##################################";
    cout<<"\n\n";
    delay(800);

    cout<<"\n\t                ##################################";
    cout<<"\n\t                ##                              ##";
    cout<<"\n\t                ##      2. ADMIN PANEL          ##";
    cout<<"\n\t                ##                              ##";
    cout<<"\n\t                ##################################";
    delay(800);

   char entry_choice;
   {
    int counter=0;
    do
    {
        if(counter==1)
        {
            cout<<"\n\t\t\t Invalid option , please try again !!!\n";
            counter=0;
        }
        cout<<"\n\n\n\n\n Enter your choice : ";
        cin>>entry_choice;
        cin.ignore(50,'\n');

        counter++;
    }while(!(entry_choice=='1'||entry_choice=='2'));

    cout<<"\n\n\n\t\t\t\tLoading ";
    delay(300);
    cout<<" . ";
    delay(300);
    cout<<" . ";
    delay(300);
    cout<<" . ";
    delay(800);
    system("cls");
   }

    if(entry_choice=='1')
    {
        userPanel();
         system("cls");
    }
    else
    {
        adminPanel();
         system("cls");
    }

}while(1);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

bool askPassword()
{
    string password="jatin";
    cout<<"\n\n\t\tEnter your password : ";
    string enter_password ;
    char ch;
    ch=_getch();
    while(ch!=13) ///  13 is ascii code for 'enter key'
    {
        cout<<"*";
        enter_password.push_back(ch);
        ch=_getch();
    }
   // cin.ignore(50,'\n');

    if(enter_password==password)
        return true;

    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


void userPanel()
{

        delay(300);
        cout<<"\n                   ############################################";
        cout<<"\n                   ##                                        ##";
        cout<<"\n                   ##         WELCOME TO DDUC AIRWAYS        ##";
        cout<<"\n                   ##                                        ##";
        cout<<"\n                   ############################################";
        cout<<"\n\n";
        char entry_user;

         do
         {
            delay(300);
            cout<<"\n\t\t\t1. Reserve Ticket";
            delay(100);
            cout<<"\n\t\t\t2. Confirm Ticket";
            delay(100);
            cout<<"\n\t\t\t3. Cancel Ticket";
            delay(100);
            cout<<"\n\t\t\t4. Return to MAIN MENU";
            delay(100);
            cout<<"\n\t\t\t5. Exit";

             int counter=0;
            do
            {
                if(counter==1)
                {
                    cout<<"\n\t\t\t Invalid option , please try again !!!\n";
                    counter=0;
                }
            cout<<"\n\n\n\n Enter your choice : ";
            //cin.ignore(50,'\n');
            cin>>entry_user;
            cin.ignore(50,'\n');

            counter++;
        }while(!(entry_user>='1'||entry_user<='5'));

        switch(entry_user)
        {
        case '1':
            {
                char _source[30];
                char _destination[30];
                int noOfTickets;
                cout<<"\nEnter source     : ";
                cin.getline(_source,30);
                cout<<"Enter destination: ";
                cin.getline(_destination,30);
                cout<<"Number of tickets to be booked : ";
                cin>>noOfTickets;

                try
                {
                    newPassenger.reserveTkt(_source , _destination , noOfTickets );
                }
                catch(MyException ob)
                {
                    ob.print();
                }
              cout<<"\n\n==============================================================================\n";

            }
            break;

        case '2':
            {
                char _tktNo[10];
                cout<<"\n\nEnter the Ticket no   : ";
                cin.getline(_tktNo,10);

                if(strlen(_tktNo)>8)
                {
                     cout<<"\n\t\t\t The entered ticketNo is INvalid !!!\n";
                     break;
                }

                cout<<"\n\n\t\t\t Searching ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . \n";

                 try
                {
                    if(newPassenger.ticketConfirmation(_tktNo))
                    {
                        cout<<"\nYour ticket has been confirmed ";
                    }
                }
                catch(MyException ob)
                {
                    ob.print();
                }
            cout<<"\n\n==============================================================================\n";

            }
            break;

        case '3':
            {
                char _tktNo[10];
                cout<<"\n\nEnter the Ticket no   : ";
                cin.getline(_tktNo,10);

                if(strlen(_tktNo)>8)
                {
                     cout<<"\n\t\t\t The entered ticketNo is INvalid !!!\n\n";
                     break;
                }

                cout<<"\n\n\t\t\t Searching ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . \n";


                try
                {
                    if(newPassenger.cancelTicket(_tktNo))
                    {
                        cout<<"\nYour Ticket has been cancelled ";
                    }
                    else
                    {
                        cout<<"\nYour Ticket has not been cancelled ";
                    }
                }
                catch(MyException ob)
                {
                    ob.print();
                }
              cout<<"\n\n==============================================================================\n";

            }
            break;
        case '4':
            {
                ///return to main menu
                return;

            }
            break;

         case '5':
        {
            cout<<"\n\t\t ########## User requested exit ##########";
            cout<<"\n\n\t\t\tExiting ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . ";
                delay(300);
                cout<<" . \n";
          cout<<"\n\n==============================================================================\n";
            exit(0);
        }
    }

    }while(1);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void adminPanel()
{

        {
             int i;
            for( i=2; (!askPassword())&&(i>0);i--)
            {
                cout<<"\n\n\n\t\t Incorrect password -_- ";
                cout<<"\n\t\t "<<i<<" attempt left !! \n";
            }
            if(i==0)
            {
                cout<<"\n\n\n\t\t\t AUTHENTICATION FAILURE !!! \n";
                cout<<"\n\t\t\t PROGRAM TERMINATING ";
                delay(500);
                cout<<" . ";
                delay(500);
                cout<<" . ";
                delay(500);
                cout<<" . \n\n";
                delay(1000);
                exit(100);
            }
            cout<<" \n\n\n\n\t\t Logging  Into  The  System ";
            delay(500);
            cout<<" . ";
            delay(500);
            cout<<" . ";
            delay(500);
            cout<<" . \n\n";
            delay(1000);
        }

        system("cls");
        delay(300);
        cout<<"\n\t                 ##################################";
        cout<<"\n\t                 ##                              ##";
        cout<<"\n\t                 ##         ADMIN PANEL          ##";
        cout<<"\n\t                 ##                              ##";
        cout<<"\n\t                 ##################################";
        cout<<"\n\n";
        char entry_admin;

         do
         {
            delay(300);
            cout<<"\n\t\t1. Create a new Flight";
            delay(100);
            cout<<"\n\t\t2. Display all Flights";
            delay(100);
            cout<<"\n\t\t3. Display passenger details of a particular Flight";
            delay(100);
            cout<<"\n\t\t4. Return to MAIN MENU";
            delay(100);
            cout<<"\n\t\t5. Exit";

             int counter=0;
            do
            {
                if(counter==1)
                {
                    cout<<"\n\t\t\t Invalid option , please try again !!!\n";
                    counter=0;
                }
            cout<<"\n\n\n\n Enter your choice : ";
            cin>>entry_admin;
            cin.ignore(50,'\n');

            counter++;
        }while(!(entry_admin>='1'||entry_admin<='5'));

        switch(entry_admin)
        {
        case '1':
            {

                try
                {
                   newPassenger.createNewFlight();
                   cout<<"\nFlight Successfully created \n";
                }
                catch(MyException ob)
                {
                    ob.print();
                }
                 cout<<"\n\n==============================================================================\n";

            }
            break;

        case '2':
            {
                try
                {
                    newPassenger.displayAllFlights();
                }
                catch(MyException ob)
                {
                    ob.print();
                }
                cout<<"\n\n==============================================================================\n";

            }
            break;

        case '3':
            {
                char _Fcode[5];
                cout<<"\nEnter the Fcode of Flight : ";
                //cin.getline(_Fcode,5);
                cin>>_Fcode;
                _Fcode[4]='\0';
                //getc(stdin);
                cin.ignore(50,'\n');

                try
                {
                    newPassenger.displayPassOfFlight(_Fcode);
                }
                catch(MyException ob)
                {
                    ob.print();
                }
                  cout<<"\n\n==============================================================================\n";
            }
            break;

        case '4':
        {
            ///return to main menu
            return;

        }
        break;


         case '5':
        {

            cout<<"\n\t\t ########## User requested exit ##########";
            cout<<"\n\n\t\t\tExiting ";
            delay(300);
            cout<<" . ";
            delay(300);
            cout<<" . ";
            delay(300);
            cout<<" . ";
            delay(300);
            cout<<" . \n";
            cout<<"\n\n==============================================================================\n";
            exit(0);
        }
     }
    }while(1);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
