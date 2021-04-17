//
//  BoxOffice.cpp
//  CS31 Winter 2019 Project 5
//
//  Created by Jason Guerrero on 2/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//

#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"

// BoxOffice default constructor
BoxOffice::BoxOffice()
{
    
}

// Method 1
Ticket BoxOffice::buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime )
{
    Ticket ticket( row, seat, event, venue, 0, kind, daytime ); // the price is set to 0 as desired by the spec
    
    return ticket;
}

// Method 2
Ticket BoxOffice::buyRoyceHallStudentTicket( string row, int seat, string event, Ticket::KIND kind, string daytime )
{
    double price = 0;
    
    Project5Helper helper; // I need this to use the helper's methods
    
    
    switch (kind) // we are switching on all of kind's enumerations
    {
            
        case Ticket::KIND::ATHLETICGAME:
            
            price = 75.00;
            
            if ( helper.startsWithOrchestra(row) ) { // double the price for Orchestra seats
                price = 2*price;
            }
            
            price = price - 30.00; // student discount $30 off for tickets $40 or more
            
            break;
        
        case Ticket::KIND::CONCERT:
            
            price = 50.00;
            
            if ( helper.endsWithPM(daytime) ) { // for evening events
                price = 65.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = price - 30.00;
            
            break;
        
        case Ticket::KIND::MOVIE:
            
            price = 12.50;
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = 0.80 * price; // 20% off for students purchasing tickets less than $40
            
            break;
            
        case Ticket::KIND::OTHER:
            
            price = 40.00;
            
            if ( helper.endsWithPM(daytime) ) {
                price = 55.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = price - 30.00;
            
            break;
            
    }
    
    // The venue is always Royce Hall for Royce Hall tickets
    Ticket studentTicket( row, seat, event, "Royce Hall", price, kind, daytime );
    
    return studentTicket;
}


// Method 3
Ticket BoxOffice::buyRoyceHallStaffTicket( string row, int seat, string event, Ticket::KIND kind, string daytime )
{
    
    double price = 0;
    
    Project5Helper helper;
    
    switch (kind)
    {
            
        case Ticket::KIND::ATHLETICGAME:
            
            price = 75.00;
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = price - 20.00; // staff discount $20 off for tickets $40 or more
            
            break;
            
        case Ticket::KIND::CONCERT:
            
            price = 50.00;
            
            if ( helper.endsWithPM(daytime) ) {
                price = 65.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = price - 20.00;
            
            break;
            
        case Ticket::KIND::MOVIE:
            
            price = 12.50;
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = 0.90 * price; // 10% off for staff purchasing tickets less than $40
            
            break;
            
        case Ticket::KIND::OTHER:
            
            price = 40.00;
            
            if ( helper.endsWithPM(daytime) ) {
                price = 55.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            price = price - 20.00;
            
            break;
            
    }
    
    
    Ticket StaffTicket( row, seat, event, "Royce Hall", price, kind, daytime );
    
    
    return StaffTicket;
}

// Method 4
Ticket BoxOffice::buyRoyceHallTicket( string row, int seat, string event, Ticket::KIND kind, string daytime )
{
    double price = 0;
    
    Project5Helper helper;
    
    switch (kind)
    {
            
        case Ticket::KIND::ATHLETICGAME:
            
            price = 75.00;
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            
            break;
            
        case Ticket::KIND::CONCERT:
            
            price = 50.00;
            
            if ( helper.endsWithPM(daytime) ) {
                price = 65.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            
            break;
            
        case Ticket::KIND::MOVIE:
            
            price = 12.50;
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            
            break;
            
        case Ticket::KIND::OTHER:
            
            price = 40.00;
            
            if ( helper.endsWithPM(daytime) ) {
                price = 55.00;
            }
            
            if ( helper.startsWithOrchestra(row) ) {
                price = 2*price;
            }
            
            
            break;
            
    } // we are applying no discounts because the purchaser is neither student nor staff
    
    Ticket RoyceHallTicket(row, seat, event, "Royce Hall", price, kind, daytime );
    
    return RoyceHallTicket;
}
