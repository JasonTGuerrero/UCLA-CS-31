//
//  Ticket.cpp
//  CS31 Winter 2019 Project 5
//
//  Created by Jason Guerrero on 2/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "Ticket.h"

// Ticket constructor
Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
    
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mKind = kind;
    mDayTime = daytime;
    
}

// all of tickets accessors
string Ticket::getRow()
{
    return mRow;
}

int Ticket::getSeat()
{
    return mSeat;
}

string Ticket::getEvent()
{
    return mEvent;
}

string Ticket::getVenue()
{
    return mVenue;
}

double Ticket::getPrice()
{
    return mPrice;
}

Ticket::KIND Ticket::getKind()
{
    return mKind;
}

// and Ticket's mutator
void Ticket::setPrice(double price)
{
    mPrice = price;
}

string Ticket::getDayTime()
{
    return mDayTime;
}
