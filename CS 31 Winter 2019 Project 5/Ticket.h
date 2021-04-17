//
//  Ticket.h
//  CS31 Winter 2019 Project 5
//
//  Created by Jason Guerrero on 2/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef Ticket_h
#define Ticket_h

#include "Project5Helper.h"

#include <iostream>
using namespace std;



class Ticket {
    
public:
    
    enum KIND { ATHLETICGAME, CONCERT, MOVIE, OTHER };
    
   
    Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);
    
    string getRow();
    int getSeat();
    string getEvent();
    string getVenue();
    double getPrice();
    void setPrice(double price);
    KIND getKind();
    string getDayTime();

    
private:
    
    string mRow;
    int mSeat;
    string mEvent;
    string mVenue;
    double mPrice;
    KIND mKind;
    string mDayTime;

};


#endif /* Ticket_h */
