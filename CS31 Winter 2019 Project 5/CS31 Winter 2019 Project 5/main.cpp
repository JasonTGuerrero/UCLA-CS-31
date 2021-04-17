//
//  main.cpp
//  CS31 Winter 2019 Project 5
//
//  Created by Jason Guerrero on 2/25/19.
//  Copyright © 2019 Jason Guerrero. All rights reserved.
//




#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"

#include <iostream>
#include <cassert>
using namespace std;


int main() {
    
    
    
    
    // box office object test
    
    BoxOffice boxoffice;
    Ticket ticket1 = boxoffice.buyTicket( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    
    assert( ticket1.getPrice() == 0 );
    assert( ticket1.getRow() == "Pavillion Row 13" );
    assert( ticket1.getSeat() == 45 );
    assert( ticket1.getEvent() == "Dodgers vs. Brewers" );
    assert( ticket1.getVenue() == "Dodger Stadium" );
    assert( ticket1.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( ticket1.getDayTime() == "August 1, 7:30PM" );
    
    ticket1.setPrice( 150.00 );
    
    assert( ticket1.getPrice() == 150.00 );
    
    
    BoxOffice boxoffice1;
    Ticket t1 = boxoffice1.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    
    assert( t1.getPrice() == 20.00 );
    t1.setPrice( 15.00 );
    assert( t1.getPrice() == 15.00 );
    assert( t1.getRow() == "Orchestra Row U" );
    assert( t1.getSeat() == 20 );
    assert( t1.getEvent() == "Episode VII: The Force Awakens" );
    assert( t1.getVenue() == "Royce Hall" );
    assert( t1.getKind() == Ticket::KIND::MOVIE );
    assert( t1.getDayTime() == "September 1, 7:30PM" );
    
   
    
    
    // spec example test case for ATHLETICGAME
    Ticket t( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    BoxOffice b;
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    assert( t.getEvent() == "Dodgers vs. Brewers" );
    assert( t.getVenue() == "Dodger Stadium" );
    assert( t.getDayTime() == "August 1, 7:30PM" );
    
    // spec example test case for MOVIE
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "September 1, 7:30PM" );
    
    // Balcony, MOVIE, AM, Student
    t = b.buyRoyceHallStudentTicket( "Balcony Row K", 23, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 11:30AM" );
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row K" );
    assert( t.getSeat() == 23 );
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "September 1, 11:30AM" );
    
    // Orchestra, ATHLETIC GAME, PM, Student
    t = b.buyRoyceHallStudentTicket( "Orchestra Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "120.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Balcony, ATHLETICGAME, PM, Student
    t = b.buyRoyceHallStudentTicket( "Balcony Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Orchestra, CONCERT, PM, Student
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::CONCERT, "February 6, 4:00PM" );
    assert( std::to_string( t.getPrice() ) == "100.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 6, 4:00PM" );
    
    // Orchestra, CONCERT, AM, Student
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::CONCERT, "February 20, 10:00AM" );
    assert( std::to_string( t.getPrice() ) == "70.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 20, 10:00AM" );
    
    // Orchestra, OTHER, AM, Student
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::OTHER, "February 20, 10:00AM" );
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 20, 10:00AM" );
    
    // Orchestra, OTHER, PM, Student
    t = b.buyRoyceHallStudentTicket( "Orchestra Row M", 32, "Hamilton", Ticket::KIND::OTHER, "July 20, 8:00PM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row M" );
    assert( t.getSeat() == 32 );
    assert( t.getEvent() == "Hamilton" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "July 20, 8:00PM" );
    
    // Balcony, OTHER, PM, Staff
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "October 1, 7:30PM" );
    
    // Orchestra, ATHLETICGAME, PM, Staff
    t = b.buyRoyceHallStaffTicket( "Orchestra Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Balcony, ATHLETICGAME, PM, Staff
    t = b.buyRoyceHallStaffTicket( "Balcony Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Orchestra, CONCERT, PM, Staff
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::CONCERT, "February 6, 4:00PM" );
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 6, 4:00PM" );
    
    // Orchestra, CONCERT, AM, Staff
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::CONCERT, "February 20, 10:00AM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 20, 10:00AM" );
    
    // Orchestra, OTHER, AM, Staff
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::OTHER, "February 20, 10:00AM" );
    assert( std::to_string( t.getPrice() ) == "60.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 20, 10:00AM" );
    
    // Orchestra, MOVIE, PM, Staff
    t = b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "22.500000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "September 1, 7:30PM" );
    
    
    // Orchestra, CONCERT, PM, General Public
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "November 1, 7:30PM" );
    
    // Orchestra, ATHLETICGAME, PM, General Public
    t = b.buyRoyceHallTicket( "Orchestra Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Balcony, ATHLETICGAME, PM, General Public
    t = b.buyRoyceHallTicket( "Balcony Row L", 44, "Bruins vs Trojans", Ticket::KIND::ATHLETICGAME, "January 15, 2:30PM" );
    assert( std::to_string( t.getPrice() ) == "75.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row L" );
    assert( t.getSeat() == 44 );
    assert( t.getEvent() == "Bruins vs Trojans" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "January 15, 2:30PM" );
    
    // Orchestra, CONCERT, PM, General Public
    t = b.buyRoyceHallTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::CONCERT, "February 6, 4:00PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 6, 4:00PM" );
    
    // Orchestra, OTHER, AM, General Public
    t = b.buyRoyceHallTicket( "Orchestra Row A", 22, "Midterm Mayhem", Ticket::KIND::OTHER, "February 20, 10:00AM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 22 );
    assert( t.getEvent() == "Midterm Mayhem" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "February 20, 10:00AM" );
    
    // Orchestra, OTHER, PM, General Public
    t = b.buyRoyceHallTicket( "Orchestra Row M", 32, "Hamilton", Ticket::KIND::OTHER, "July 20, 8:00PM" );
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row M" );
    assert( t.getSeat() == 32 );
    assert( t.getEvent() == "Hamilton" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "July 20, 8:00PM" );
    
    // Balcony, MOVIE, AM, General Public
    t = b.buyRoyceHallTicket( "Balcony Row K", 23, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 11:30AM" );
    assert( std::to_string( t.getPrice() ) == "12.500000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row K" );
    assert( t.getSeat() == 23 );
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getDayTime() == "September 1, 11:30AM" );
    
    cerr << "all tests passed!" << endl;
    
    return 0;
}
