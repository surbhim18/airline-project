#include<iostream>
#include<cstring>
#include<stdio.h>
#include<ctype.h>
#include "Pnode.h"

using namespace std;

Pnode::Pnode(int counter)
{
    tktNo = counter;
    pname = new char[30];
    age = 0;
    gender = '\0';
    next = 0;
}

Pnode:: Pnode(const Pnode& P)
{
    pname = new char[30];
    next = 0;

    tktNo = P.tktNo;
    strcpy(pname,P.pname);
    age = P.age;
    gender = P.gender;
}

Pnode::~Pnode()
{
    delete []pname;
}

const char* Pnode:: getPname() const
{
    return pname;
}

const int Pnode:: getTktNo() const
{
    return tktNo;
}


void Pnode:: enterN()
{
    cin.ignore(50,'\n');
    cout<<"\n\nEnter name          : ";
    cin.getline(pname,30);
    do
    {
        cout<<"Enter age           : ";
        cin>>age;
    }while(age<1 || age>115);

    do
    {
        cout<<"Enter gender (M/F/O): ";
        cin>>gender;
        gender = toupper(gender);
    }while(gender!='M'&& gender!='F'&& gender!='O');
}

void Pnode:: displayN() const
{
    cout<<"\nNo.    : ";
    cout<<tktNo;
    cout<<"\nName   : ";
    cout<<pname;
    cout<<"\nAge    : ";
    cout<<age;
    cout<<"\nGender : ";
    cout<<gender;
    cout<<endl;

}
