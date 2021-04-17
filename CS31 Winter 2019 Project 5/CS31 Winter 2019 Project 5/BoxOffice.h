//
//  BoxOffice.h
//  CS31 Winter 2019 Project 5
//
//  Created by Jason Guerrero on 2/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include "Ticket.h"

class BoxOffice {
    
public:
    
    BoxOffice();
    
    Ticket buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    
    
    
};

#endif /* BoxOffice_h */
